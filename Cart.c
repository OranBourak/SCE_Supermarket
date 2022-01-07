#include "Cart.h"

void printCartInfo(Cart cart, User loged_User)
{
	printf(BOLDYELLOW"             *****  MY CART ***** \n");
	printf("----------------------------------------------------------------- - \n");
	printf("S.N.|         NAME          |  QUANTITY |    PRICE    | CATEGORY \n");
	printf("----------------------------------------------------------------- - \n");
	for (int i = 0; i < cart.productCounter; i++) 
		printProduct(cart.productsInCart[i]);
	printf("----------------------------------------------------------------- - \n");
	if (loged_User.userType == CLUB) {
		printf(WHITE"						Cart Price: %.2lf\n", getCartPrice(loged_User) / 0.9);
		printf(WHITE"				Total Price after discount: %.2lf\n", getCartPrice(loged_User));
	}
	else
		printf(WHITE"						Total Price: %.2lf\n", getCartPrice(loged_User));
	printf(BOLDYELLOW"----------------------------------------------------------------- - \n"RESET);
}


void addProductToCart(char* userName, int productSerialNumber, int quantity)
{
	FILE* fpointer = fopen(CARTS_FILENAME, "rb+");
	if (fpointer == NULL) {
		fprintf(stderr, "\nERROR OPENING FILE\n");
		exit(1);
	}
	Cart temp;
	while (fread(&temp, sizeof(Cart), 1, fpointer)){//Find the cart by user name and read the cart to temp parameter.
		if (!strcmp(temp.userName, userName))
			break;
	}


	/*if the product is already exist it the cart*/
	for(int i=0;i<temp.productCounter;i++)
		if (temp.productsInCart[i].serialNumber == productSerialNumber) {//in case the product already contain in the cart
			temp.productsInCart[i].quantity += quantity;//Adds the quantity to the existing product in the cart
			fseek(fpointer, -(int)sizeof(Cart), SEEK_CUR);// jump back one Cart
			fwrite(&temp, sizeof(Cart), 1, fpointer);//rewrite the cart with the new product included
			fclose(fpointer);
			changeProductQuantity(productSerialNumber, ADD, -quantity);//Updates the quantity in stock
			return;
		}

	/*if the product not exist in cart: checking if there is free space in cart and add the product*/
	if (temp.productCounter < MAX_Products_In_Cart) {//Check if the cart is full.
		temp.productsInCart[temp.productCounter] = getProductBySerial(productSerialNumber);//adds the product to cart(copy product from the inventory)
		temp.productsInCart[temp.productCounter].quantity = quantity;//update the quantity in cart
		temp.productCounter++;
		fseek(fpointer, -(int)sizeof(Cart), SEEK_CUR);// jump back one Cart
		fwrite(&temp, sizeof(Cart), 1, fpointer);//rewrite the cart with the new product included
		fclose(fpointer);
		changeProductQuantity(productSerialNumber, ADD, -quantity);//Updates the quantity in stock
	}
	else{
		printf("\nThe cart is full.\n");
	}

}

int remove_Product_From_Cart(char* userName, int serialNumber)
{
	Cart temp,temp2;
	int quantity = 0;
	FILE* fpointer = fopen(CARTS_FILENAME, "rb+");
	if (fpointer == NULL) {
		fprintf(stderr, "\nERROR OPENING FILE\n");
		exit(1);
	}
	while (fread(&temp, sizeof(Cart), 1, fpointer)) {//Find the cart by user name and read the cart to temp parameter.
		if (!strcmp(temp.userName, userName))
			break;
	}
	strcpy(temp2.userName,temp.userName);//copy user name 
	temp2.productCounter = 0;
	/*copy all product one by one, and skip the product we want to remove*/
	for (int i = 0; i < temp.productCounter; i++) {
		if (!(temp.productsInCart[i].serialNumber == serialNumber)) {
			temp2.productsInCart[temp2.productCounter] = temp.productsInCart[i];
			temp2.productCounter++;
		}
		else if(temp.productsInCart[i].serialNumber == serialNumber)
			quantity = temp.productsInCart[i].quantity;//save the product quantity that removed from cart .needs to be returned to update the inventory.
	}

	fseek(fpointer, -(int)sizeof(Cart), SEEK_CUR);
	fwrite(&temp2, sizeof(Cart), 1, fpointer);
	fclose(fpointer);
	return quantity;
}

void remove_Product_From_All_Carts(int serialNumber)
{
	User temp;

	FILE* fpointer = fopen(USERS_FILENAME, "rb");
	if (fpointer == NULL) {
		fprintf(stderr, "\nERROR OPENING FILE\n");
		exit(1);
	}
	while (fread(&temp, sizeof(User), 1, fpointer))
		remove_Product_From_Cart(temp.userName, serialNumber);
	fclose(fpointer);
}

Cart getCartByUser(char* user_name)
{
	FILE* fpointer = fopen(CARTS_FILENAME, "rb");
	if (fpointer == NULL) {
		fprintf(stderr, "\nERROR OPENING FILE\n");
		exit(1);
	}
	Cart temp;
	while (fread(&temp, sizeof(Cart), 1, fpointer)){
		if (!strcmp(temp.userName, user_name)) {
			fclose(fpointer);
			return temp;
		}
	}
}


/// <summary>
/// Return the Cart's total price 
///if the costumer is Club member return the price with 10% discount.
/// </summary>
/// <param name="userName"></param>
/// <returns></returns>
double getCartPrice(User userName)
{
	FILE* fpointer = fopen(CARTS_FILENAME, "rb");
	Cart temp;
	double sum = 0;
	while (fread(&temp, sizeof(Cart), 1, fpointer))
	{
		if (!strcmp(temp.userName, userName.userName)) {
			fclose(fpointer);
			for (int i = 0; i < temp.productCounter; i++) {
				sum += temp.productsInCart[i].productPrice * temp.productsInCart[i].quantity;
			}
			if (userName.userType == CLUB)
				return sum * CLUB_MEMBER_PRICE_AFTER_DISCOUNT;
			return sum;
		}
	}
}

enum Bool empty_the_cart(User loged_user)
{	
	Cart tempCart;
	FILE* fpointer = fopen(CARTS_FILENAME,"r+b");
	if (!fpointer) {
		puts("Cannot open the file");
		exit(1);
	}
	while (fread(&tempCart, sizeof(Cart), 1, fpointer)) {
		if (!strcmp(loged_user.userName, tempCart.userName)) {
			tempCart.productCounter = 0;
			fseek(fpointer, -(int)sizeof(Cart), SEEK_CUR);
			fwrite(&tempCart, sizeof(Cart), 1, fpointer);
			fclose(fpointer);
			return TRUE;
		}

	}
	fclose(fpointer);
	return FALSE;
}


/// <summary>
/// 
/// </summary>
/// <param name="userName"></param>
/// <param name="serialNumber"></param>
/// <param name="quantity">quantity to remove</param>
/// <returns></returns>
void remove_product_quantity_in_Cart(char* userName, int serialNumber,int quantity)
{
	Cart temp;
	int quantity1;
	FILE* fpointer = fopen(CARTS_FILENAME, "rb+");
	if (fpointer == NULL) {
		fprintf(stderr, "\nERROR OPENING FILE\n");
		exit(1);
	}
	while (fread(&temp, sizeof(Cart), 1, fpointer)) //Find the cart by user name and read the cart to temp parameter.
		if (!strcmp(temp.userName, userName)) 
			break;
	
	for (int i = 0; i < temp.productCounter; i++)//change the product quantity
		if (temp.productsInCart[i].serialNumber == serialNumber) {
			if (temp.productsInCart[i].quantity - quantity <= 0) {//if product quantity in cart is smaller than the quantity to remove
				fclose(fpointer);
				quantity1=remove_Product_From_Cart(userName, serialNumber);
				changeProductQuantity(serialNumber, ADD, quantity1);
				return;
			}
			else {
				temp.productsInCart[i].quantity -= quantity;
				changeProductQuantity(serialNumber, ADD, quantity);//update the quantity in stock
				fseek(fpointer, -(int)sizeof(Cart), SEEK_CUR);
				fwrite(&temp, sizeof(Cart), 1, fpointer);
				fclose(fpointer);
			}
		}
}


enum Bool is_product_exist_in_cart(int serial,char* userName) {
	Cart temp;
	FILE* fpointer = fopen(CARTS_FILENAME, "rb");
	if (fpointer == NULL) {
		fprintf(stderr, "\nERROR OPENIN FILE\n");
		exit(1);
	}
	while (fread(&temp, sizeof(Cart), 1, fpointer))
		if (!strcmp(temp.userName,userName)) {
			fclose(fpointer);
			break;
		}

	for (int i = 0; i < temp.productCounter; i++)
		if (temp.productsInCart[i].serialNumber == serial)
			return TRUE;
	return FALSE;
}
