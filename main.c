#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "User.h"
#include "Product.h"

#define PRODUCTS_FILENAME "users_database.dat"
#define USERS_FILENAME "products_database.dat"
#define ORDERS_FILENAME "orders_database.dat"
#define CARTS_FILENAME "carts_database.dat"
void initFiles(); //initialize all files 
/*DATABASE NAMES:
1)users_database.dat
2)products_database.dat
3)orders_database.dat
4)carts_database.dat
*/

int main() {
	
	//User logedUser = startMenu();//gives us a user without password
	//
	//enum userType logedUserType = logedUser.userType;
	//char logedUserName[MAX_SIZE];
	//strcpy(logedUserName, logedUser.userName);
	///*
	//enum userType logedUserType = MANAGER;//for tests
	//
	//showProducts();
	//if (logedUserType == MANAGER)
	//	managerMenu();
	//else
	//	customerMenu();
	//*/

	return 0;
}



void initFiles(){
	FILE* usersFile, * productsFile, * cartsFile, * ordersFile;
	usersFile = fopen(USERS_FILENAME, "ab");
	if (usersFile == NULL) {
		fprintf(stderr, "\nERROR OPENING USERS FILE\n");
		exit(1);
	}
	else
		fclose(usersFile);
	productsFile = fopen(PRODUCTS_FILENAME, "ab");
	if (productsFile == NULL) {
		fprintf(stderr, "\nERROR OPENING MANAGERS FILE\n");
		exit(1);
	}
	else
		fclose(productsFile);
	cartsFile = fopen(CARTS_FILENAME, "ab");
	if (cartsFile == NULL) {
		fprintf(stderr, "\nERROR OPENING POSTS FILE\n");
		exit(1);
	}
	else
		fclose(cartsFile);
	ordersFile = fopen(ORDERS_FILENAME, "ab");
	if (ordersFile == NULL) {
		fprintf(stderr, "\nERROR OPENING APPLIED FILE\n");
		exit(1);
	}
	else
		fclose(ordersFile);
	return;
}


