#define _CRT_SECURE_NO_WARNINGS
#define MAX_SIZE 50
#include <stdio.h>
#include <stdlib.h>
#include "Product.h"


/*Printing all products that contains in the catalog*/
void showProducts(){
	Product tempProduct;
	FILE* fpointer;
	fpointer = fopen("products_data.dat", "r");
	if (!fpointer) {
		fpointer = fopen("products_data.dat", "w");
		fclose(fpointer);
		fpointer = fopen("products_data.dat", "r");
		if (!fpointer) {
			puts("Cannot open the file");
			exit(1);
		}
	}
	while (!feof(fpointer)) {
		printf("%d\n", ftell(fpointer));
		fread(&tempProduct, sizeof(Product), 1, fpointer);
		printProduct(&tempProduct);
		printf("%d\n", ftell(fpointer));
	}
	fclose(fpointer);
}


/*Printing pruduct details*/
void printProduct(Product* p){
	char pName[MAX_SIZE], pCategory[MAX_SIZE];
	strcpy(pName, p->productName);
	strcpy(pCategory, p->category);

	printf("Serial: %d\t", p->serialNumber);
	printf("Name: %s\t", pName);
	printf("Price: %.2lf\t", p->productPrice);//check formating
	printf("Quantity: %d\t", p->quantity);
	printf("Category: %s\n", pCategory);
}

void customerMenu()
{
}

void managerMenu(){
	addProduct();
}

void addProduct(){
	FILE* fpointer;
	fpointer = fopen("products_data.dat", "a");
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
	gets(new_product.category);
	
	
	/*check format
	do {//password check
		puts("Please enter user password, must contain at least 6 charcters and contain at least one number and one letter:");
		gets(new_user.password);
	} while (!isPasswordLegal(new_user.password));
	*/

	fwrite(&new_product, sizeof(Product), 1, fpointer);

	fclose(fpointer);
}