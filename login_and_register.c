/*	Made by Oran and Ilya
	Maybe change variable names to be more clear?	*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "DataStructures.h"
#define MANAGER_CODE "qwerty"
#define PASSWORD_MIN_LENGTH 6


//start menu, only login or register, no option to exit at this stage(made problems)
User startMenu() {//want to return from function loged user name and type.
	int choice;
	User logedUser;
	enum Bool isLogedIn = FALSE;
	do {
		puts("Welcome to SCE_Supermaekt\n1.Login\n2.Sign-up");// no need for \n, because puts() adds it by default
		scanf("%d", &choice);
		getchar();//clean enter
		switch (choice)
		{
		case 1://login
			isLogedIn = login(&logedUser);
			if(isLogedIn)
				return logedUser;//notice that returned user has garbage password
			break;
		case 2:
			signUp();
			break;
		default://for any other number no acion is taken.
			break;
		}
	} while (TRUE);
}

//checks users details in order to login
enum Bool login(User* user) {
	FILE* fpointer;
	User login_data;
	User comparing_user;
	fpointer = fopen("users_data.dat", "r");
	if (!fpointer) {
		fpointer = fopen("users_data.dat", "w");//quick solution for login problem when no file exists
		fclose(fpointer);//not sure that needed
		fpointer = fopen("users_data.dat", "r");
		if (!fpointer) {
			puts("Cannot open the file");
			exit(1);
		}
	}
	
	puts("Please enter user name:");
	gets(login_data.userName);
	puts("Please enter user password:");
	gets(login_data.password);

	while (!feof(fpointer)) {//return 1 when reach to end of file
		fread(&comparing_user, sizeof(User), 1, fpointer);
		int	a = strcmp(comparing_user.userName, login_data.userName);
		int	b = strcmp(comparing_user.password, login_data.password);
		if (!(a || b)) {
			puts("Login sucssefuly.");
			strcpy(user->userName, comparing_user.userName);//this returns to startMenu the users name
			user->userType = comparing_user.userType;//this returns to startMenu the users type
			fclose(fpointer);
			return TRUE;
			//break;
		}
		if (feof(fpointer)) {
			puts("Wrong user name or password.");
			fclose(fpointer);
			return FALSE;
			//break;
		}
	}
	fclose(fpointer); //I think if here cannot be reached
}

// adds user signing up to users databse
void signUp() {
	FILE* fpointer;
	fpointer = fopen("users_data.dat", "a");
	if (!fpointer) {
		puts("Cannot open the file");
		exit(1);
	}
	User new_user;
	
	do {//user name check
		puts("Please enter user name, cannot be an existing name:");
		gets(new_user.userName);
	} while(isNameTaken(new_user.userName));
	
	do {//password check
		puts("Please enter user password, must contain at least 6 charcters and contain at least one number and one letter:");
		gets(new_user.password);
	} while (!isPasswordLegal(new_user.password));
	
	new_user.userType = managerSignUp();

	fwrite(&new_user, sizeof(User), 1, fpointer);

	fclose(fpointer);
}

//assigns user type, customer or manager based on secret code
enum Type managerSignUp(){//works
	char choice;
	char managerCode[MAX_SIZE];

	do {
		puts("Do you wish to sign-up as a manager? y/n:");
		scanf("%c", &choice);
		getchar();//clean enter
		if (choice == 'y') {
			puts("Enter secret manger code:");
			scanf("%s", managerCode);
			getchar();//clean enter
			if (!strcmp(managerCode, MANAGER_CODE))
				return MANAGER;
			else puts("Wrong code");
		}
		else if (choice == 'n')
			return CUSTOMER;
		else puts("Invalid option, please enter y/n");
	} while (TRUE);//I maybe dont need it,lets save. YES NO NEED
	//while (choice != 'y' || choice != 'n') saved
}

//check if username taken
enum Bool isNameTaken(char* user_name)//works
{
	FILE* fpointer = fopen("users_data.dat", "r");
	User tempUser;
	
	while (!feof(fpointer)) {//return 1 when reach to end of file
		fread(&tempUser, sizeof(User), 1, fpointer);
		//printf("TEST tempUser.userName = %s, user_name = %s\n", tempUser.userName, user_name);
		if (!strcmp(tempUser.userName, user_name)){
			fclose(fpointer);
			return TRUE;//return true if name is taken
		}
	}
	fclose(fpointer);
	return FALSE;//return false if name is not taken
}

//check password for length and charcters
enum Bool isPasswordLegal(char* user_password) {
	int passwordLen = strlen(user_password);
	int numbersCount = 0;
	int lettersCount = 0;
	if (passwordLen < PASSWORD_MIN_LENGTH)
		return FALSE;
	for (int i = 0; i < passwordLen; i++) {
		char currentChar = user_password[i];
		//maybe add breaks, more efficent
		if (currentChar >= '0' && currentChar <= '9')
			numbersCount++;
		if (currentChar >= 'a' && currentChar <= 'z')
			lettersCount++;
		if (currentChar >= 'A' && currentChar <= 'Z')
			lettersCount++;
		}
	if (numbersCount == 0 || lettersCount == 0)
		return FALSE;
	return TRUE;//passed in this stage all checks
}



