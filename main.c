#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "User.h"
#include "Product.h"

int main() {
	User logedUser = startMenu();//gives us a user without password
	
	enum userType logedUserType = logedUser.userType;
	char logedUserName[MAX_SIZE];
	strcpy(logedUserName, logedUser.userName);
	
	/*test for User.h and user.c
	puts("TEST, WE ARE BACK IN MAIN");
	puts("PROOF WE GOT USER DETAILS:");
	printf("  User's name: %s, type: %d\n", logedUser.userName, logedUser.userType);
	puts("PROOF WE GOT NO PASSWORD:");
	printf("  Garbage password: %s\n", logedUser.password);
	*/
	showProducts();
	if (logedUserType == MANAGER)
		managerMenu();
	else
		customerMenu();
	return 0;
}