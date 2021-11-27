#include "User.h"
//#include "Cart.h"
#include"Orders.h"
#include <string.h>
/* Maybe change variable names to be more clear? */




//start menu, only login or register, no option to exit at this stage(made problems)
User startMenu() {
	int choice;
	User logedUser;
	enum Bool isLogedIn = FALSE;
	do {
		puts("Welcome to Sami market\n1.Login\n2.Sign-up");// no need for \n, because puts() adds it by default
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
	fpointer = fopen(USERS_FILENAME, "rb");
	if (!fpointer) {
		puts("Cannot open the file");
		exit(1);
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
			puts("Login successfully.");
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
	char temp_key;
	fpointer = fopen(USERS_FILENAME, "ab");
	if (!fpointer) {
		puts("Cannot open the file");
		exit(1);
	}
	User new_user;
	system("cls");//clear terminal screen
	
	do {//user name check
		puts("\t\t\t\t\t*****REGISTRITION*****\n\n");
		puts("Please enter user name [cannot be an existing name]:");
		gets(new_user.userName);
		if (isNameTaken(new_user.userName)) {
			puts(RED"\nThe username you selected is already taken...please try again\n"RESET);
			printf("Press any key to continue...");
			scanf("%c", &temp_key);
			getchar();
			system("cls");//clear terminal screen
		}

	} while(isNameTaken(new_user.userName));
	
	do {//password check
		puts("\nPlease enter user password:[must contain at least 6 charcters  and include  number and letter]");
		gets(new_user.password);
	} while (!isPasswordLegal(new_user.password));
	
	new_user.userType = managerSignUp();

	if (new_user.userType == CUSTOMER) {//creating a cart for an new customer.
		Cart newCart;
		FILE* cartPtr = fopen(CARTS_FILENAME, "ab");
		strcpy(newCart.userName,new_user.userName);
		newCart.productCounter = 0;
		fwrite(&newCart, sizeof(Cart), 1, cartPtr);
		fclose(cartPtr);
	}

	fwrite(&new_user, sizeof(User), 1, fpointer);
	
	fclose(fpointer);
	
	puts("User Registered successfully");
}

//assigns user type, customer or manager based on secret code
enum Type managerSignUp(){//works
	char choice;
	char managerCode[MAX_SIZE];

	do {
		puts("\nDo you want to sign-up as a manager? y/n:");
		scanf("%c", &choice);
		getchar();//clean enter
		if (choice == 'y') {
			puts("\nEnter secret manger code:");
			scanf("%s", managerCode);
			getchar();//clean enter
			if (!strcmp(managerCode, MANAGER_CODE))
				return MANAGER;
			else puts(RED"\nWrong code"RESET);
		}
		else if (choice == 'n')
			return CUSTOMER;
		else puts(RED"\nInvalid option, please enter y/n"RESET);
	} while (TRUE);//I maybe dont need it,lets save. YES NO NEED
	//while (choice != 'y' || choice != 'n') saved
}

//check if username taken
enum Bool isNameTaken(char* user_name)//works
{
	FILE* fpointer = fopen(USERS_FILENAME, "rb");
	User tempUser;
	
	while (fread(&tempUser, sizeof(User), 1, fpointer)) {
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
void ContactUs()
{
	char name[MAX_SIZE], email[MAX_SIZE], phone[MAX_SIZE], message[MAX_SIZE];
	int check = 0;
	system("cls");
	printf(BOLDYELLOW"\t\t\t\t\t*****Contact Us*****\n");
	printf("\t\t\t\t\t About Sami market\n");
	printf("Email:ramzi@sami.com\n");
	printf("Phone:08-8765456\n");
	printf("The address:Ashdod, bnay brit 5/6\n");
	printf("*****Leave a message*****\n");
	printf(BOLDBLUE"If you encounter any problems,fill the following form and we'll get back to you with a complete solution \n"RESET);
	printf("Enter your name:\n");
	gets(name);
	puts("Enter your email:");
	gets(email);
	puts("Enter your phone number: ");
	gets(phone);
	check = atoi(phone);
	while (strlen(phone)!=10 || check == 0)
	{
		printf(RED"wrong phone please try again with 10 digits only:\n"RESET);
		scanf("%s", &phone);
		check = atoi(phone);
		getchar();
	}
	puts("Enter the problem description:");
	gets(message);
	
	puts("\n\n\n\n\t\t****Thank you for contacting us and we'll get back to you within 48 hours with a reply****");
	getchar();
}