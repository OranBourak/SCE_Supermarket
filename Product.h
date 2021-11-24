#pragma once
#include "Structs.h"

/*Printing all products that contains in the catalog*/
void showProducts();

/*Printing product details*/
void printProduct(Product);

/// <summary>
/// Receives serial number and return a Product struct with the product info:
/// quantity available in stock, product price and category
/// </summary>
/// <param name="serialNumber"></param>
/// <returns></returns>
Product getProductBySerial(int serialNumber);

/// <summary>
/// Receives serial number and check if there is a product in the catalog with this serial number
///if the product exist return True, otherwise return false.
/// </summary>
enum Bool isProductExsist(int serialNumber);

//customer only
void customerCatalogMenu();
void showByPrice();//to make
int priceCompare(const void*, const void*);
void showByCategory(enum category);

//manager only
void managerCatalogMenu();
void addProduct();//add checks
void removeProductMenu();
void removeProduct(int);
enum Bool changeProduct();//to make

//Functions used to create/edit a product
enum Bool isProductSerialValid(int);
enum Bool isProductNameValid(char*);
enum Bool isProductPriceValid(double);
enum Bool isProductQuantityValid(unsigned int);
enum Bool isProductCategoryValid(enum category);


