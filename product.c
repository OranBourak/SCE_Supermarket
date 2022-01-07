#define NUM_OF_CATEGORIES 5
#include "Product.h"

/*Printing all products that contains in the catalog*/
void showProducts(){
	Product tempProduct;
	FILE* fpointer;
	fpointer = fopen(PRODUCTS_FILENAME, "rb");
	if (!fpointer) {
		puts("Cannot open the file");
		exit(1);
		}
	printf(BOLDYELLOW"             *****  CATALOG ***** \n");
	printf("----------------------------------------------------------------- - \n");
	printf("S.N.|         NAME          |  QUANTITY |    PRICE    | CATEGORY \n");
	printf("----------------------------------------------------------------- - \n");
	while (fread(&tempProduct, sizeof(Product), 1, fpointer)) {
		printProduct(tempProduct);
	}
	fclose(fpointer);
	printf("----------------------------------------------------------------- - \n"RESET);
}

/*Printing product details*/
void printProduct(Product p){

	printf(" %-5d     %-15s        %-5d       %-8.2lf", p.serialNumber, p.productName, p.quantity,p.productPrice);

	switch (p.product_category)
	{
	case 0:
		puts("   Fruits");
		break;
	case 1:
		puts("   Vegetables");
		break;
	case 2:
		puts("   Drinks");
		break;
	case 3:
		puts("   Meat");
		break;
	case 4:
		puts("   Farm");
		break;
	default:
		puts("   ERROR");
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

enum Bool isProductExist(int serialNumber){
	FILE* fpointer = fopen(PRODUCTS_FILENAME, "rb");
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

// Prints all products in catalog by ascending price
void showByPrice() {
	//PART 1: getting the number of products in catalog.
	FILE* fpointer = fopen(PRODUCTS_FILENAME, "rb");
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
	//PART 3: where magic happens...
	qsort(tempCatalog, tempCatalogSize, sizeof(Product), priceCompare);
	
	printf(BOLDYELLOW"----------------------------------------------------------------- - \n");
	printf("S.N.|         NAME          |  QUANTITY |    PRICE    | CATEGORY \n");
	printf("----------------------------------------------------------------- - \n");
	for (int i = 0; i < tempCatalogSize; i++){
		printProduct(tempCatalog[i]);
	}
	printf("---------------------------------------------------------------- - \n"RESET);

	//LAST PART: close file, free memory.
	fclose(fpointer);
	free(tempCatalog);
}

// Used by qsort() in showByPrice()
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

//Prints all products of a specific category
void showByCategory(enum category c) {

	Product tempProduct;
	FILE* fpointer = fopen(PRODUCTS_FILENAME, "rb");
	if (!fpointer) {
		puts("Cannot open the file");
		exit(1);
	}
	printf(BOLDYELLOW"----------------------------------------------------------------- - \n");
	printf("S.N.|         NAME          |  QUANTITY |    PRICE    | CATEGORY \n");
	printf("----------------------------------------------------------------- - \n");
	while (fread(&tempProduct, sizeof(Product), 1, fpointer)) {
		if (tempProduct.product_category == c)
		{
			printProduct(tempProduct);
		}
	}
	printf("----------------------------------------------------------------- - \n"RESET);
	
	fclose(fpointer);
	
}

void managerCatalogMenu(){//now useless...
	int choice;
	do {
		showProducts();
		puts("What do you want to do?");
		puts("1. Add a product to the catalog.");
		puts("2. Remove a product from the catalog.");
		puts("3. Change a product in the catalog.");
		puts("0. EXIT");

		scanf("%d", &choice);
		getchar();
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
	fpointer = fopen(PRODUCTS_FILENAME, "ab");
	if (!fpointer) {
		puts("Cannot open the file");
		exit(1);
	}
	
	Product new_product;
	char tempInput[MAX_SIZE];

	do {
		puts("Enter product's serial number:");
		gets(tempInput);
	} while (!isProductSerialValid(tempInput));
	new_product.serialNumber = atoi(tempInput);

	//add checks to all see below
	puts("Enter product's name:");
	gets(new_product.productName);

	do {
		puts("Enter product's price:");
		gets(tempInput);
	} while (!isProductPriceValid(tempInput));
	new_product.productPrice = atof(tempInput);
	
	do {
		puts("Enter product's quantity:");
		gets(tempInput);
	} while (!isProductQuantityValid(tempInput));
	new_product.quantity = atoi(tempInput);

	do {
		puts("Enter product's category:");
		puts("0.FRUITS 1.VEGETABLES 2.DRINKS 3.MEAT 4.FARM");
		gets(tempInput);
	} while (!isProductCategoryValid(tempInput));
	new_product.product_category = atoi(tempInput);

	fwrite(&new_product, sizeof(Product), 1, fpointer);

	fclose(fpointer);
}

void removeProductMenu(){
	int serial;
	puts("Enter a product's serial number to delete, 0 to EXIT");
	scanf("%d", &serial);

	if (isProductExist(serial)){
		removeProduct(serial);
		puts("Product removed successfully");
	}
	else
		puts("A product with this serial number doesn't exist.");
}

//removes a product from catalog, does not check if product exist
void removeProduct(int serial) {
	//PART 1: getting the number of products in catalog.
	FILE* fpointer = fopen(PRODUCTS_FILENAME, "rb");
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
	fpointer = fopen(PRODUCTS_FILENAME, "wb");
	if (!fpointer) {
		fprintf(stderr, "\nERROR OPENIN FILE\n");
		exit(1);
	}

	for (int i = 0; i < tempCatalogSize; i++){
		fwrite(&tempCatalog[i], sizeof(Product), 1, fpointer);
	}
	
	fclose(fpointer);
	free(tempCatalog);
	
	remove_Product_From_All_Carts(serial);
}

enum Bool changeProductQuantity(int serial, enum CHANGE_MODE m, int quantity){
	Product tempProduct;
	if (!isProductExist(serial)) {
		return FALSE;
	}
	FILE* fpointer = fopen(PRODUCTS_FILENAME, "rb+");
	if (!fpointer) {
		puts("Cannot open the file");
		exit(1);
	}
	while (fread(&tempProduct,sizeof(Product),1,fpointer)){
		if (tempProduct.serialNumber ==	serial){
			break;
		}
	}
	if (m == ADD) {
		tempProduct.quantity += quantity;
	}
	else if (m == REPLACE) {
		tempProduct.quantity = quantity;
	}
	else return FALSE;
	
	if (tempProduct.quantity < 0) {
		return FALSE;
	}
	

	fseek(fpointer, -(int)sizeof(Product), SEEK_CUR);
	
	fwrite(&tempProduct, sizeof(Product), 1, fpointer);
	
	fclose(fpointer);
	return TRUE;
}

enum Bool changeProductPrice(int serial, double newPrice) {
	Product tempProduct;
	if (!isProductExist(serial) || newPrice<=0)
		return FALSE;
	FILE* fpointer = fopen(PRODUCTS_FILENAME, "rb+");
	if (!fpointer) {
		puts("Cannot open the file");
		exit(1);
	}
	while (fread(&tempProduct, sizeof(Product), 1, fpointer)) {
		if (tempProduct.serialNumber == serial) {
			break;
		}
	}
	
	tempProduct.productPrice = newPrice;

	fseek(fpointer, -(int)sizeof(Product), SEEK_CUR);

	fwrite(&tempProduct, sizeof(Product), 1, fpointer);

	fclose(fpointer);
	return TRUE;
}

int getProductQuantity(int serial) {
	FILE* fpointer = fopen(PRODUCTS_FILENAME, "rb");
	if (!fpointer) {
		puts("Cannot open the file");
		exit(1);
	}
	Product tempProduct;
	while (fread(&tempProduct,sizeof(Product),1,fpointer)){
		if (tempProduct.serialNumber == serial){
			fclose(fpointer);
			return tempProduct.quantity;
		}
	}
	fclose(fpointer);
	return -1;
}

//Is valid functions
enum Bool isProductSerialValid(char * serial) {
	if (!atoi(serial) || atoi(serial)<0) {
		puts("This serial number isn't valid");
		return FALSE;
	}
	if (isProductExist(atoi(serial))){
		puts("This serial number already exists");
		return FALSE;
	}
	return TRUE;
}

enum Bool isProductPriceValid(char * price) {
	if (!atof(price) && strcmp(price,"0")) {
		puts("This price isn't valid");
		return FALSE;
	}
	if (atof(price) <= 0){
		puts("Price can't be negative or zero");
		return FALSE;
	}
	return TRUE;
}

enum Bool isProductQuantityValid(char* quantity) {
	if (!atoi(quantity) && strcmp(quantity, "0")){
		puts("This quantity isn't valid");
		return FALSE;
	}
	if (atoi(quantity) < 0) {
		puts("Quantity cannot be negative");
		return FALSE;
	}
	return TRUE;
}

enum Bool isProductCategoryValid(char* category) {
	if (!atoi(category) && strcmp(category, "0")) {
		puts("This category isn't valid");
		return FALSE;
	}
	if (atoi(category) < 0 || atoi(category) >= NUM_OF_CATEGORIES) {
		puts("No such category");
		return FALSE;
	}
	return TRUE;
}