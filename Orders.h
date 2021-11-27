#pragma once

#include "Structs.h"
#include "User.h"
#include "Product.h"
#include "Cart.h"


//create order for the client
void Create_Order(User user);//has to be broken down,

//Changes an order status in the database [no checks here]
//If canceled, returns the products to inventory
void changeOrderStatus(int orderId,enum Status newStatus);

//Gets the user's user name by its order id
char * getOrderUsername(int orderId);

//Gets the order's status by its order id
enum Status getOrderStatus(int orderId);

//Checks in an order exists in database by its order id
enum Bool doesOrderExist(int orderId);

//check id, phone number and credit card validation (10 digits)
//enum Bool check_validation(unsigned long long num);//not sure, no harm

//Print an order
void printOrder(Order order);

//Prints all orders of a given user
void printUserOrdersByStatus(User logedUser,enum Status pickStatus);//format it by status

//--------------so far so good---------------

void printOrdersByStatus(enum Status pickStatus);

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




