#pragma once

#include "Structs.h"



void Create_Order(char* username);//������ �� �� ������� �� ����� ������� ����� ������� �� ������
void change_order_status(char* username);// the function change the status of the order 
enum Bool check_id_validation(unsigned long int id);
enum Bool check_creditCard_validation(unsigned long int card);
void print_order_details(Order* order);
void all_orders();//the manager see all the orders



