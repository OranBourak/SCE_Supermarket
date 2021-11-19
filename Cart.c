#include "Cart.h"

void printCartInfo(Cart* cart)
{
	printf("\nProducts List:\n");
	printf("----------------\n");
	int listSize = cart->productCounter;
		for (int i = 0; i < listSize; i++)
			printf("Product name: %s\tProduct quantity:%d\n", cart->productsInCart->productName, cart->productsInCart[i].quantity);
		printf("\n----------------------------------------------------------------------\n\n");
}

void addProductToCart(char* userName, int productSerialNumber, unsigned int quantity)
{
	FILE* fpointer = fopen(CARTS_FILENAME, "r+");
	if (fpointer == NULL) {
		fprintf(stderr, "\nERROR OPENING FILE\n");
		exit(1);
	}
	Cart temp;
	while (fread(&temp, sizeof(Cart), 1, fpointer)){//Find the cart by user name and read the cart to temp parameter.
		if (!strcmp(temp.userName, userName))
			break;
	}
	if (temp.productCounter < MAX_Products_In_Cart) {//Check if the cart is full.
		temp.productsInCart[temp.productCounter] = getProductBySerial(productSerialNumber);//adds the product to cart
		fseek(fpointer, -(int)sizeof(Cart), SEEK_CUR);// jump back one Cart
		fwrite(&temp, sizeof(Product), 1, fpointer);//rewrite the cart with the new product included
		fclose(fpointer);
	}
	else{
		printf("\nThe cart is full.\n");
	}

}
