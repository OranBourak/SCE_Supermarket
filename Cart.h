#pragma once
#include "Structs.h"
#include "Product.h"



void printCartInfo(Cart cart);

/// <summary>
/// Adding product to cart.
/// </summary>
/// <param name="userName">cart's user name </param>
/// <param name="productSerialNumber">serial number of the product to add</param>
/// <param name="quantity">quantity to add to the cart</param>
void addProductToCart(char* userName, int productSerialNumber, unsigned int quantity );

/// <summary>
/// Remove product from cart by serial number
/// </summary>
/// <param name="userName"></param>
/// <param name="serialNumber"></param>
void remove_Product_From_Cart(char* userName, int serialNumber);
void remove_Product_From_All_Carts(int serialNumber);
/// <summary>
/// Return user's Cart struct
/// </summary>
/// <param name="userName"></param>
/// <returns></returns>
Cart getCartByUser(char* user_name);

enum Bool empty_the_cart(Cart* cart);//empty all product from cart
enum Bool check_product_exsistenc_in_catalog();
enum Bool check_product_exsistenc_in_cart(int id);






