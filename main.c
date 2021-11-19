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
	/*
	enum userType logedUserType = MANAGER;//for tests
	
	showProducts();
	if (logedUserType == MANAGER)
		managerMenu();
	//else
		//customerMenu();
	*/
	return 0;
}