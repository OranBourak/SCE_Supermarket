#define _CRT_SECURE_NO_WARNINGS
#pragma once
#define MAX_SIZE 50
#define MAX_Products_In_Cart 10

#define PRODUCTS_FILENAME "users_database.dat"
#define USERS_FILENAME "products_database.dat"
#define ORDERS_FILENAME "orders_database.dat"
#define CARTS_FILENAME "carts_database.dat"


#include "Product.h"



typedef struct Cart {
	char userName[MAX_SIZE]; //customer website Username
	Product productsInCart[MAX_Products_In_Cart];//Products list
	unsigned int productCounter;//number of products in cart

}Cart;


/// <summary>
/// Printing all cart's products.
/// </summary>
/// <param name="cart">Pointer to cart</param>
void printCartInfo(Cart* cart);

/// <summary>
/// Adding product to cart.
/// </summary>
/// <param name="userName">cart's user name </param>
/// <param name="productSerialNumber">serial number of the product to add</param>
/// <param name="quantity">quantity to add to the cart</param>
void addProductToCart(char* userName, int productSerialNumber, unsigned int quantity );


void remove_Product_From_Cart(int id);


enum Bool empty_the_cart(Cart* cart);//empty all product from cart
enum Bool check_product_exsistenc_in_catalog();
enum Bool check_product_exsistenc_in_cart(int id);






