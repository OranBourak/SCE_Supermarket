#pragma once
#define MAX_SIZE 50
#define MAX_Products_In_Cart 10
#include "Product.h"
enum Bool { FALSE, TRUE };

typedef struct Cart
{
	char userName[MAX_SIZE]; //costumer website Username
	Product productsInCart[MAX_Products_In_Cart];//Products list

}Cart;



void printCart(Cart* cart);
void addProductToCart();
void remove_Product_From_Cart(int id);
enum Bool empty_the_cart(Cart* cart);//empty all product from cart
enum Bool check_product_exsistenc_in_catalog();
enum Bool check_product_exsistenc_in_cart(int id);






