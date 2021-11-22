#pragma once

#include "Structs.h"



void Create_Order(char* username);//create order for the client
void change_order_status(char* username);// the function change the status of the order 
enum Bool check_validation(unsigned long long num);//check id, phone number and credit card validation (10 digits)
void print_order_details(Order* order);// print the order
void all_orders();//the manager see all the orders



