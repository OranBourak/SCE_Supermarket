#pragma once
#include "Structs.h"
#include "Product.h"



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






