#pragma once
#define _CRT_SECURE_NO_WARNINGS
#define MAX_SIZE 50
#define MAX_Products_In_Cart 10

#include <stdio.h>
#include <stdlib.h>
#include "User.h"//contains Bool
#include "Product.h"

typedef struct Cart
{
	char userName[MAX_SIZE]; //costumer website Username
	Product productsInCart[MAX_Products_In_Cart];//Products list
	unsigned int productCounter;//number of products in cart

}Cart;


/// <summary>
/// Printing all cart's products.
/// </summary>
/// <param name="cart">Pointer to cart</param>
void printCartInfo(Cart* cart);

void addProductToCart();
void remove_Product_From_Cart(int id);
enum Bool empty_the_cart(Cart* cart);//empty all product from cart
enum Bool check_product_exsistenc_in_catalog();
enum Bool check_product_exsistenc_in_cart(int id);






