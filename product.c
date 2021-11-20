#include "Product.h"


/*Printing all products that contains in the catalog*/
void showProducts(){
	Product tempProduct;
	FILE* fpointer;
	fpointer = fopen(PRODUCTS_FILENAME, "r");
	if (!fpointer) {
		puts("Cannot open the file");
		exit(1);
		}
	
	while (fread(&tempProduct, sizeof(Product), 1, fpointer)) {
		printProduct(&tempProduct);
	}
	fclose(fpointer);
}




/*Printing pruduct details*/
void printProduct(Product* p){
	char pName[MAX_SIZE], pCategory[MAX_SIZE];
	strcpy(pName, p->productName);

	printf("Serial: %d\t", p->serialNumber);
	printf("Name: %s\t", pName);
	printf("Price: %.2lf\t", p->productPrice);//check formating
	printf("Quantity: %d\t", p->quantity);

	switch (p->product_category)
	{
	case 0:
		puts("Category: Fruits");
		break;
	case 1:
		puts("Category: Vegetables");
		break;
	case 2:
		puts("Category: Drinks");
		break;
	case 3:
		puts("Category: Meat");
		break;
	case 4:
		puts("Category: Farm");
		break;
	default:
		puts("ERROR");
		break;
	}
}

Product getProductBySerial(int serialNumber)
{
	FILE* fpointer = fopen(PRODUCTS_FILENAME, "r");
	if (fpointer == NULL) {
		fprintf(stderr, "\nERROR OPENIN FILE\n");
		exit(1);
	}
	Product temp;
	while (fread(&temp, sizeof(Product), 1, fpointer))
		if (temp.serialNumber == serialNumber) {
			fclose(fpointer);
			return temp;
		}
}

enum Bool isProductExsist(int serialNumber)
{
	FILE* fpointer = fopen(PRODUCTS_FILENAME, "r");
	if (fpointer == NULL) {
		fprintf(stderr, "\nERROR OPENIN FILE\n");
		exit(1);
	}
	Product temp;
	while (fread(&temp, sizeof(Product), 1, fpointer))
		if (temp.serialNumber == serialNumber) {
			fclose(fpointer);
			return TRUE;
		}
	fclose(fpointer);
	return FALSE;
}

void customerMenu()
{
}

void managerMenu(){
	addProduct();
}

void addProduct(){
	FILE* fpointer;
	fpointer = fopen(PRODUCTS_FILENAME, "a");
	if (!fpointer) {
		puts("Cannot open the file");
		exit(1);
	}
	
	Product new_product;

	
	puts("Enter product's serial number:");
	scanf("%d", &(new_product.serialNumber));
	getchar();
	
	puts("Enter product's name:");
	gets(new_product.productName);

	puts("Enter product's price:");
	scanf("%lf", &(new_product.productPrice));//check formating
	getchar();

	puts("Enter product's quantity:");
	scanf("%u", &(new_product.quantity));
	getchar();

	puts("Enter product's category:");
	puts("0.FRUITS 1.VEGETABLES 2.DRINKS 3.MEAT 4.FARM");
	scanf("%d", &(new_product.product_category));
	
	
	/*check format
	do {//password check
		puts("Please enter user password, must contain at least 6 charcters and contain at least one number and one letter:");
		gets(new_user.password);
	} while (!isPasswordLegal(new_user.password));
	*/

	fwrite(&new_product, sizeof(Product), 1, fpointer);

	fclose(fpointer);
}