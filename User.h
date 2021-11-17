#pragma once
#define MAX_SIZE 50

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


