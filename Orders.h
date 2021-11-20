#pragma once

#include "Structs.h"





void Create_Order(char* username);//מאתחלת את כל הנתונים של הזמנה ומוסיפה לבסיס הנתונים של הזמנות
enum Bool change_order_status();
enum Bool check_id_validation(unsigned long int id);
enum Bool check_creditCard_validation(unsigned long int card);
void print_order_details(Order* order);



