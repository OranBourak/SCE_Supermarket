#pragma once


#define _CRT_SECURE_NO_WARNINGS
#define MAX_SIZE 50
#define MAX_Products_In_Cart 10

#define PRODUCTS_FILENAME "products_database.dat"
#define USERS_FILENAME "users_database.dat"
#define ORDERS_FILENAME "orders_database.dat"
#define CARTS_FILENAME "carts_database.dat"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



enum category { FRUITS, VEGETABLES, DRINKS, MEAT, FARM };
enum Bool { FALSE, TRUE };
enum Type { MANAGER, CUSTOMER, CLUB };
enum Status{APPENDING, APPROVED, CANCELD};



typedef struct User {
	char userName[MAX_SIZE];
	char password[MAX_SIZE];
	enum Type userType;
}User;




typedef struct Product {
	int serialNumber;
	char productName[MAX_SIZE];
	double productPrice;
	unsigned int quantity;
	enum category product_category;
}Product;





typedef struct Cart {
	char userName[MAX_SIZE]; //customer website Username
	Product productsInCart[MAX_Products_In_Cart];//Products list
	unsigned int productCounter;//number of products in cart

}Cart;



struct Order
{
	char userName[MAX_SIZE]; //customer website Username
	enum Status status;//Order's sataus
	Product  cart_list[MAX_Products_In_Cart]; //add products list and quantity
	char customer_full_name[MAX_SIZE];
	unsigned long int customer_id;
	unsigned long int customer_credit_card;
	char customer_address[MAX_SIZE];

}typedef Order;