#pragma once
#include "Structs.h"

//PRODUCT related functions

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
void showByPrice();
void showByCategory();

//manager only
void managerCatalogMenu();
void addProduct();
void removeProductMenu();
void removeProduct(int);
enum Bool changeProduct();


