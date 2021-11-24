#include "Structs.h"



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

	enum option { VIEW_CATALOG = 1, UPDATE_INVENTORY = 2, UPDATE_ORDERS = 3, EXIT = 4 };
	do {
		system("cls");
		puts("\t\t\t\t\t*****MANAGER MENU*****\n");
		printf("Hello %s, How can we help you today?\n\n", loged_User.userName);
		puts("(1) View catalog.\n(2) Update inventory.\n(3) Update order's status.\n(4) Sign Out.\n");
		scanf("%d", &choice);
		getchar();
		switch (choice) {

		case VIEW_CATALOG:
			viewCatalogManager();
			break;

		case UPDATE_INVENTORY:
			updateInventoryMenu();
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


	enum option { VIEW_CATALOG = 1, VIEW_CART = 2, ADD_PRODUCT = 3, CLUB_MEMBER = 4, CONTACT_US = 5, EXIT = 6 };
	do {
		system("cls");
		puts("\t\t\t\t\t*****CUSTOMER MENU*****\n");
		printf("Hello %s, How can we help you today?\n\n", loged_User.userName);
		puts("\n(1) View Catalog.\n(2) View Cart.\n(3) Add Product To Cart.\n(4) Club Member.\n(5) Contact Us\n(6) Sign Out.\n");
		scanf("%d", &choice);
		getchar();
		switch (choice) {

		case VIEW_CATALOG:
			viewCatalogCustomer(loged_User);
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


/// <summary>
/// view catalog menu for manager
///Displays the options to the customer and activates the requested function
/// </summary>
/// <returns></returns>
viewCatalogManager() {
	int choice;

	enum option { SORT_BY_PRICE = 1, CHOOSE_CATEGORY = 2, EXIT = 3 };
	do {
		system("cls");
		puts("\t\t\t\t\t*****VIEW CATALOG*****\n");
		puts("Choose one of the following options:");
		puts("\n(1) Sort by price.\n(2) Choose category.\n(3) Go back.\n");
		scanf("%d", &choice);
		getchar();
		switch (choice) {

		case SORT_BY_PRICE:
			break;

		case CHOOSE_CATEGORY:
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
/// view catalog menu for manager
///Displays the options to the customer and activates the requested function
/// </summary>
/// <param name="username">Using username in Add product function</param>
/// <returns></returns>
viewCatalogCustomer(User loged_User) {
	int choice;

	enum option { SORT_BY_PRICE = 1, CHOOSE_CATEGORY = 2,ADD_PRODUCT=3, EXIT = 4 };
	do {
		system("cls");
		puts("\t\t\t\t\t*****VIEW CATALOG*****\n");
		puts("Choose one of the following options:");
		puts("\n(1) Sort by price.\n(2) Choose category.\n(3) Add product to cart.\n(4) Go back.\n");
		scanf("%d", &choice);
		getchar();
		switch (choice) {

		case SORT_BY_PRICE:
			break;

		case CHOOSE_CATEGORY:
			break;

		case ADD_PRODUCT:
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
/// Update inventory func:
///prints the options for the manager and activates the requested function
/// </summary>
/// <returns></returns>
updateInventoryMenu() {
	int choice;

	enum option { ADD_PRODUCT = 1, REMOVE_PRODUCT = 2, UPDATE_PRODUCT = 3, EXIT = 4 };
	do {
		system("cls");
		puts("\t\t\t\t\t*****VIEW CATALOG*****\n");
		puts("Choose one of the following options:");
		puts("\n(1) Add New Product To Inventory .\n(2) Remove Product From Inventory.\n(3) Update Product Info.\n(4) Go back.\n");
		scanf("%d", &choice);
		getchar();
		switch (choice) {

		case ADD_PRODUCT:
			break;

		case REMOVE_PRODUCT:
			break;

		case UPDATE_PRODUCT:
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
