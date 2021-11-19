#ifndef USER
#define USER




#define MAX_SIZE 50
#define PRODUCTS_FILENAME "users_database.dat"
#define USERS_FILENAME "products_database.dat"
#define ORDERS_FILENAME "orders_database.dat"
#define CARTS_FILENAME "carts_database.dat"

#define _CRT_SECURE_NO_WARNINGS
#define MANAGER_CODE "qwerty"
#define PASSWORD_MIN_LENGTH 6

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "Cart.h"

enum Bool { FALSE, TRUE };
enum Type { MANAGER, CUSTOMER, CLUB };

typedef struct User {
	char userName[MAX_SIZE];
	char password[MAX_SIZE];
	enum Type userType;
}User;

//USER declaration and related functions 
User startMenu();
enum Bool login(User*);//to add? inform if username wrong or password?
void signUp();
enum Type managerSignUp();
enum Bool isNameTaken(char*);
enum Bool isPasswordLegal(char*);


#endif // !USER