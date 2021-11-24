#define NUM_OF_CATEGORIES 5
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
	puts("_________________________________________CATALOG_________________________________________");
	while (fread(&tempProduct, sizeof(Product), 1, fpointer)) {
		printProduct(tempProduct);
	}
	fclose(fpointer);
	puts("_________________________________________________________________________________________");
}

/*Printing product details*/
void printProduct(Product p){
	char pName[MAX_SIZE];
	strcpy(pName, p.productName);
	printf("Serial: %d\t", p.serialNumber);
	printf("Name: %s\t", pName);
	printf("Price: %.2lf\t", p.productPrice);//check formating
	printf("Quantity: %d\t", p.quantity);

	switch (p.product_category)
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

Product getProductBySerial(int serialNumber){//what if serial number dosent exist?
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

enum Bool isProductExsist(int serialNumber){
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

void customerCatalogMenu(){
	showProducts();
	puts("MEAT:");
	showByCategory(MEAT);
}

void showByPrice() {
	//PART 1: getting the number of products in catalog.
	FILE* fpointer = fopen(PRODUCTS_FILENAME, "r");
	if (!fpointer) {
		fprintf(stderr, "\nERROR OPENIN FILE\n");
		exit(1);
	}
	fseek(fpointer, 0, SEEK_END);
	int tempCatalogSize = (int)(ftell(fpointer) / sizeof(Product));

	//PART 2: create a temp copy of catalog.
	Product* tempCatalog = NULL;
	Product tempProduct;
	tempCatalog = malloc(tempCatalogSize * sizeof(Product));
	if (!tempCatalog) {
		fprintf(stderr, "\nERROR ALLOCATING MEMORY\n");
		exit(1);
	}

	fseek(fpointer, 0, SEEK_SET);
	for (int i = 0; fread(&tempProduct, sizeof(Product), 1, fpointer); i++) {
		tempCatalog[i] = tempProduct;
	}
	
	qsort(tempCatalog, tempCatalogSize, sizeof(Product), priceCompare);
	
	for (int i = 0; i < tempCatalogSize; i++){
		printProduct(tempCatalog[i]);
	}

	//LAST PART: close file, free memory.
	fclose(fpointer);
	free(tempCatalog);
}

int priceCompare(const void*a, const void*b) {
	Product* L = (Product*)a;
	Product* R = (Product*)b;
	if (L->productPrice < R->productPrice) {
		return -1;
	}
	else if (L->productPrice == R->productPrice){
		return 0;
	}
	else return 1;
}

void showByCategory(enum category c) {

	Product tempProduct;
	FILE* fpointer = fopen(PRODUCTS_FILENAME, "r");
	if (!fpointer) {
		puts("Cannot open the file");
		exit(1);
	}
	
	while (fread(&tempProduct, sizeof(Product), 1, fpointer)) {
		if (tempProduct.product_category == c)
		{
			printProduct(tempProduct);
		}
	}
	
	fclose(fpointer);
	
}

void managerCatalogMenu(){
	int choice;
	do {
		showProducts();
		puts("What do you want to do?");
		puts("1. Add a product to the catalog.");
		puts("2. Remove a product from the catalog.");
		puts("3. Change a product in the catalog.");
		puts("0. EXIT");

		scanf("%d", &choice);
		switch (choice)
		{
		case 0:
			break;
		case 1:
			addProduct();
			break;
		case 2:
			removeProductMenu();
			break;
		case 3:
			puts("PRODUCT CHANGED");
			//changeProduct();
		default:
			puts("No such option");
			break;
		}
	} while (choice != 0);
}

void addProduct(){
	FILE* fpointer;
	fpointer = fopen(PRODUCTS_FILENAME, "a");
	if (!fpointer) {
		puts("Cannot open the file");
		exit(1);
	}
	
	Product new_product;

	//add checks to all see below
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

void removeProductMenu(){
	int serial;
	do {
		puts("Enter a product's serial number to delete, 0 to EXIT");
		scanf("%d", &serial);

		if (isProductExsist(serial)){
			removeProduct(serial);
			puts("Product removed successfully");
		}
		else if(serial != 0)
			puts("A product with this serial number doesn't exist.");
		
	} while (serial != 0);

}

void removeProduct(int serial) {
	//PART 1: getting the number of products in catalog.
	FILE* fpointer = fopen(PRODUCTS_FILENAME, "r");
	if (!fpointer) {
		fprintf(stderr, "\nERROR OPENIN FILE\n");
		exit(1);
	}
	fseek(fpointer, 0, SEEK_END);
	int tempCatalogSize = (int)(ftell(fpointer) / sizeof(Product)) - 1;

	//PART 2: create a temp copy of catalog minus the product to delete.
	Product* tempCatalog = NULL;
	Product tempProduct;
	tempCatalog = malloc(tempCatalogSize*sizeof(Product));
	if (!tempCatalog){
		fprintf(stderr, "\nERROR ALLOCATING MEMORY\n");
		exit(1);
	}
	
	fseek(fpointer, 0, SEEK_SET);
	for (int i=0;fread(&tempProduct, sizeof(Product), 1, fpointer);i++){
		if (tempProduct.serialNumber == serial){
			i--;
			continue;
		}
		tempCatalog[i] = tempProduct;
	}
	
	//PART 3 overwriting existing file with new
	fpointer = fopen(PRODUCTS_FILENAME, "w");
	if (!fpointer) {
		fprintf(stderr, "\nERROR OPENIN FILE\n");
		exit(1);
	}

	for (int i = 0; i < tempCatalogSize; i++){
		fwrite(&tempCatalog[i], sizeof(Product), 1, fpointer);
	}

	fclose(fpointer);
	free(tempCatalog);
}
