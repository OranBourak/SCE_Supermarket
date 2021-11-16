#pragma once
#define MAX_SIZE 50

enum Bool { FALSE, TRUE };
enum Type { MANAGER, CUSTOMER, CLUB };

//USER declaration and related functions 
typedef struct User {
	char userName[MAX_SIZE];
	char password[MAX_SIZE];
	enum Type userType;
}User;

User startMenu();
enum Bool login(User*);//to add? inform if username wrong or password?
void signUp();
enum Type managerSignUp();
enum Bool isNameTaken(char*);
enum Bool isPasswordLegal(char*);

//PRODUCT declaration and related functions
typedef struct
{
	int serialNumber;
	char productName[MAX_SIZE];
	double productPrice;
	unsigned int quantity;
	char category[MAX_SIZE];
}Product;

//GENERAL functions?
