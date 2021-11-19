#pragma once
#define MAX_SIZE 50
#define MAX_Products_In_Cart 10
#include "Product.h"

enum Bool { FALSE, TRUE };

enum Status
{
	APPENDING,APPROVED,CANCELD
};

struct Order
{
	char userName[MAX_SIZE]; //costumer website Username
	enum Status status;//Order's sataus
	Product  cart_list[MAX_Products_In_Cart]; //add products list and quantity
	char costumer_full_name[MAX_SIZE];
	unsigned long int costumer_id;
	unsigned long int costumer_credit_card;
	char costumer_address[MAX_SIZE];

}typedef Order;




Order Create_Order(char* username);//מאתחלת את כל הנתונים של הזמנה ומוסיפה לבסיס הנתונים של הזמנות
enum Bool change_order_status();
enum Bool check_id_validation(unsigned long int id);
enum Bool check_creditCard_validation(unsigned long int card);
void print_order_details(Order* order);



