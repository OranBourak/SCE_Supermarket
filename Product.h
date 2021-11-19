#pragma once
#define MAX_SIZE 50
enum Bool { FALSE, TRUE };
/*Product Categories*/
enum category
{
	FRUITS,VEGETABLES,DRINKS,MEAT,FARM
};

typedef struct
{
	int serialNumber;
	char productName[MAX_SIZE];
	double productPrice;
	unsigned int quantity;
	enum category product_category;
}Product;


//PRODUCT related functions
/*Printing all products that contains in the catalog*/
void showProducts();

/*Printing pruduct details*/
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
