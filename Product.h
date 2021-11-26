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
void addProduct();
void removeProductMenu();
void removeProduct(int);
enum CHANGE_MODE{ADD,REPLACE};
enum Bool changeProductQuantity(int serial, enum CHANGE_MODE m, int newQuantity);//to make
enum Bool changeProductPrice(int serial, double newPrice);
int getProductQuantity(int);

//Functions used to create or edit a product
enum Bool isProductSerialValid(char *);
enum Bool isProductPriceValid(char *);
enum Bool isProductQuantityValid(char *);
enum Bool isProductCategoryValid(char *);


