#pragma once

typedef struct
{
	int serialNumber;
	char productName[MAX_SIZE];
	double productPrice;
	unsigned int quantity;
	char category[MAX_SIZE];
}Product;

//PRODUCT related functions
void showProducts();
void printProduct(Product*);
//customer only
void customerMenu();
void showByPrice();
void showByCategory();
//manager only
void managerMenu();
void addProduct();
void removeProduct();
void changeProduct();
