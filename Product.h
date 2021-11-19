#ifndef PRODUCT
#define PRODUCT



#define MAX_SIZE 50



/*Product Categories*/
enum category {FRUITS,VEGETABLES,DRINKS,MEAT,FARM};

typedef struct Product{
	int serialNumber;
	char productName[MAX_SIZE];
	double productPrice;
	unsigned int quantity;
	enum category product_category;
}Product;

#include "User.h"//contains Bool


//PRODUCT related functions
/*Printing all products that contains in the catalog*/
void showProducts();

/*Printing pruduct details*/
void printProduct(Product*);

/// <summary>
/// Receives serial number and return a Product struct with the product info:
/// quantity available in stock, product price and category
/// </summary>
/// <param name="serialNumber"></param>
/// <returns></returns>
Product getProductBySerial(int serialNumber);

/// <summary>
/// Receives serial number and check if there is a product in the catalog with this serial number
///if the product exsist return True, otherwise return false.
/// </summary>
enum Bool isProductExsist(int serialNumber);


//customer only
void customerMenu();
void showByPrice();
void showByCategory();


//manager only
void managerMenu();
void addProduct();
void removeProduct();
void changeProduct();
#endif // !PRODUCT
