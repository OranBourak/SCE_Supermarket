#pragma once

#define _CRT_SECURE_NO_WARNINGS
#define MAX_SIZE 50
#define MAX_Products_In_Cart 10

#define PRODUCTS_FILENAME "products_database.bin"
#define USERS_FILENAME "users_database.bin"
#define ORDERS_FILENAME "orders_database.bin"
#define CARTS_FILENAME "carts_database.bin"

#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum Bool { FALSE, TRUE };
enum Type { MANAGER, CUSTOMER, CLUB };
enum category { FRUITS, VEGETABLES, DRINKS, MEAT, FARM };
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
	int quantity;
	enum category product_category;
}Product;

typedef struct Cart {
	char userName[MAX_SIZE]; //customer website User name
	Product productsInCart[MAX_Products_In_Cart];//Products list
	unsigned int productCounter;//number of products in cart

}Cart;

struct Order
{
	char userName[MAX_SIZE]; //customer website User name
	enum Status status;//Order's status
	Product  cart_list[MAX_Products_In_Cart]; //add products list and quantity
	char customer_full_name[MAX_SIZE];
	unsigned long int customer_id;
	unsigned long int customer_credit_card;//10 digits
	char customer_address[MAX_SIZE];
	float orderPrice;
	unsigned int counter_cart_list;
	unsigned long int phoneNumber;// 10 digits exactly
	

	

}typedef Order;