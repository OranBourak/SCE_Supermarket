#pragma once

#include "Structs.h"



void Create_Order(char* username);//create order for the client
void change_order_status(char* username);// the function change the status of the order 
enum Bool check_validation(unsigned long long num);//check id, phone number and credit card validation (10 digits)
void print_order(Order order);//print the order
void print_order_details_Appending();// print the order Appending 
void print_order_details_Approved();// print the order Approved
void print_order_details_Canceld();// print the order canceld
void print_All_order_details();// print the all order 
void all_orders();//the manager see all the orders



