#include "User.h"

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
	fpointer = fopen(USERS_FILENAME, "r");
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
	char temp_key;
	fpointer = fopen(USERS_FILENAME, "a");
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
			puts("\nThe username you selected is already taken...please try again\n");
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
		FILE* cartPtr = fopen(CARTS_FILENAME, "a");
		strcpy(newCart.userName,new_user.userName);
		newCart.productCounter = 0;
		fwrite(&newCart, sizeof(Cart), 1, cartPtr);
		fclose(cartPtr);
	}

	fwrite(&new_user, sizeof(User), 1, fpointer);
	
	fclose(fpointer);
	
	puts("User Registered succesfuly");
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
			else puts("\nWrong code");
		}
		else if (choice == 'n')
			return CUSTOMER;
		else puts("\nInvalid option, please enter y/n");
	} while (TRUE);//I maybe dont need it,lets save. YES NO NEED
	//while (choice != 'y' || choice != 'n') saved
}

//check if username taken
enum Bool isNameTaken(char* user_name)//works
{
	FILE* fpointer = fopen(USERS_FILENAME, "r");
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
	system("cls");
	puts("\t\t\t\t\t*****Contact Us*****\n");
	puts("\t\t\t\t\t*****If you encounter a problem and you want us to get back to you if a solution is complete the following form*****\n");
}


/// <summary>
/// MAIN MENU function
/// </summary>
void Menu() {
	enum choice { REGISTER = 1, SIGN_IN = 2, EXIT = 3 };
	int choice;
	char temp_key;
	User loged_User; //The user that logged to the system
	do {
		system("cls");
		printf("***********************************\n");
		printf("   Welcome to Sami Supermarket\n");
		printf("***********************************\n\n");

		printf("(1). Register\n(2). Sign in\n(3). Exit the system\n");
		scanf("%d", &choice);
		getchar();
		switch (choice) {
		case REGISTER:
			signUp();
			break;

		case SIGN_IN:
			if (login(&loged_User)) {
				if (loged_User.userType == MANAGER)
					managerMenu(loged_User);
				else
					customerMenu(loged_User);
			}	
			break;

		case EXIT:
			printf("Goodbye ! :)\n");
			break;

		default:
			printf("You entered a wrong input. Please try again\n");
			break;
		}
		printf("Press any key to continue...");
		getchar();
		scanf("%c", &temp_key);
	} while (choice != EXIT);

}


/// <summary>
/// MANAGER MENU SYSTEM
///Displays the options to the manager and activates the requested function
/// </summary>
/// <returns></returns>
managerMenu(User loged_User) {
	int choice;

	enum option{VIEW_CATALOG=1,UPDATE_INVENTORY=2,UPDATE_ORDERS=3,EXIT=4};
	do {
		system("cls");
		puts("\t\t\t\t\t*****MANAGER MENU*****\n");
		printf("Hello %s, How can we help you today?\n\n", loged_User.userName);
		puts("(1) View catalog.\n(2) Update inventory.\n(3) Update order's status.\n(4) Sign Out.\n");
		scanf("%d", &choice);
		getchar();
		switch (choice) {

		case VIEW_CATALOG:
			break;

		case UPDATE_INVENTORY:
			break;

		case UPDATE_ORDERS:
			break;

		case EXIT:
			printf("Goodbye ! :)\n");
			break;

		default:
			printf("You entered a wrong input. Please try again\n");
			break;
		}
	} while (choice != EXIT);

}



/// <summary>
/// CUSTOMER MENU SYSTEM
///Displays the options to the customer and activates the requested function
/// </summary>
/// <returns></returns>
customerMenu(User loged_User) {
	int choice;

	enum option { VIEW_CATALOG = 1, VIEW_CART = 2, ADD_PRODUCT = 3,CLUB_MEMBER=4,CONTACT_US=5,EXIT = 6};
	do {
		system("cls");
		puts("\t\t\t\t\t*****CUSTOMER MENU*****\n");
		printf("Hello %s, How can we help you today?\n\n", loged_User.userName);
		puts("\n(1) View Catalog.\n(2) View Cart.\n(3) Add Product To Cart.\n(4) Club Member.\n(5) Contact Us\n(6) Sign Out.\n");
		scanf("%d", &choice);
		getchar();
		switch (choice) {

		case VIEW_CATALOG:
			break;

		case VIEW_CART:
			break;

		case ADD_PRODUCT:
			break;
		case CLUB_MEMBER:
			break;
		case CONTACT_US:
			break;
		case EXIT:
			printf("Goodbye ! :)\n");
			break;

		default:
			printf("You entered a wrong input. Please try again\n");
			break;
		}
	} while (choice != EXIT);
}
