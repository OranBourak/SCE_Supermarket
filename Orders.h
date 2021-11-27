#pragma once

#include "Structs.h"
#include "User.h"
#include "Product.h"
#include "Cart.h"


//create order for the client
void Create_Order(User user);//has to be broken down,
//CHECK

// the function change the status of the order 
void change_order_status(char* username);
/*MAKE*/

//check id, phone number and credit card validation (10 digits)
//enum Bool check_validation(unsigned long long num);//not sure, no harm

//print the order
void printOrder(Order order);
//CHECK

void printUserOrders(User logedUser);

//MERGE BELOW
// print the order Appending 
void print_order_details_Appending();

// print the order Approved
void print_order_details_Approved();

// print the order canceld
void print_order_details_Canceld();

/*maybe merge as well*/
// print the all order 
void print_All_order_details();




