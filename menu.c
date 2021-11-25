#include "menu.h"

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





//-----------------------------MANAGER-MENU-SECTION-------------------------//

/// <summary>
/// MANAGER MENU SYSTEM
///Displays the options to the manager and activates the requested function
/// </summary>
/// <param name="loged_User"></param>
void managerMenu(User loged_User) {
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
			UpdateOrdersMenu();
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
///view catalog menu for manager
///Displays the options to the customer and activates the requested function
/// </summary>
void viewCatalogManager() {
	int choice;

	enum option { SORT_BY_PRICE = 1, CHOOSE_CATEGORY = 2, REFRESH_PAGE=3, EXIT = 4 };
	system("cls");
		puts("\t\t\t\t\t*****VIEW CATALOG*****\n");
		showProducts();//prints the catalog
	do {
		puts("Choose one of the following options:");
		puts("\n(1) Sort by price.\n(2) Choose category.\n(3) Refresh Page.\n(4) Go back.\n");
		scanf("%d", &choice);
		getchar();
		switch (choice) {

		case SORT_BY_PRICE:
			system("cls");
			puts("\t\t\t\t\t*****VIEW CATALOG*****\n");
			showByPrice();
			break;

		case CHOOSE_CATEGORY:
			system("cls");
			puts("\t\t\t\t\t*****VIEW CATALOG*****\n");
			ShowProductsByCategory();
			break;
		case REFRESH_PAGE:
			system("cls");
			puts("\t\t\t\t\t*****VIEW CATALOG*****\n");
			showProducts();//prints the catalog
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
void updateInventoryMenu() {
	int choice;

	enum option { ADD_PRODUCT = 1, REMOVE_PRODUCT = 2, UPDATE_PRODUCT = 3, EXIT = 4 };
	do {
		system("cls");
		puts("\t\t\t\t\t*****UPDATE INVENTORY*****\n");
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

void UpdateOrdersMenu() {
	int choice;

	enum option { SHOW_ORDER_BY_STATUS = 1, UPDATE_ORDER = 2, EXIT = 3 };
	do {
		system("cls");
		puts("\t\t\t\t\t*****UPDATE ORDERS*****\n");
		puts("Choose one of the following options:");
		puts("\n(1) Show Orders By Status .\n(2) Update Order.\n(3) Go back.\n");
		scanf("%d", &choice);
		getchar();
		switch (choice) {

		case SHOW_ORDER_BY_STATUS:
			break;

		case UPDATE_ORDER:
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
/// UPDATE PRODUCT MENU 
/// </summary>
/// <returns></returns>
void UpdateProductMemu() {
	int choice;

	enum option { Update_Product_Price = 1, UPDATE_PRODUCT_QUANTITY = 2, EXIT = 3 };
	do {
		system("cls");
		puts("\t\t\t\t\t*****UPDATE PRODUCT INFO*****\n");
		puts("Choose one of the following options:");
		puts("\n(1) Update Product Price .\n(2) Update Product Quantity.\n(3) Go back.\n");
		scanf("%d", &choice);
		getchar();
		switch (choice) {

		case Update_Product_Price:
			break;

		case UPDATE_PRODUCT_QUANTITY:
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

//-----------------------------COSTUMER-MENU-SECTION-------------------------//


/// <summary>
/// CUSTOMER MENU SYSTEM
///Displays the options to the customer and activates the requested function
/// </summary>
/// <returns></returns>
void customerMenu(User loged_User) {
	int choice;


	enum option { VIEW_CATALOG = 1, VIEW_CART = 2, ADD_PRODUCT = 3, CLUB_MEMBER = 4, CONTACT_US = 5, EXIT = 6 };
	do {
		system("cls");
		printf(BOLDGREEN"\t\t\t\t\t*****CUSTOMER MENU*****\n"RESET);
		printf(BOLDBLUE"Hello %s, How can we help you today?\n\n"RESET, loged_User.userName );
		puts("\n(1) View Catalog.\n(2) View Cart.\n(3) Add Product To Cart.\n(4) Club Member.\n(5) Contact Us\n(6) Sign Out.\n");
		scanf("%d", &choice);
		getchar();
		switch (choice) {

		case VIEW_CATALOG:
			viewCatalogCustomer(loged_User);
			break;

		case VIEW_CART:
			viewCartMenu(loged_User);
			break;

		case ADD_PRODUCT:
			addProductMenu(loged_User);
			break;
		case CLUB_MEMBER:
			break;
		case CONTACT_US:
			ContactUs();
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
void viewCatalogCustomer(User loged_User) {
	int choice;

	enum option { SORT_BY_PRICE = 1, CHOOSE_CATEGORY = 2,ADD_PRODUCT=3,REFRESH_PAGE=4,EXIT = 5 };
		system("cls");
		puts("\t\t\t\t\t*****VIEW CATALOG*****\n");
		showProducts();//prints the catalog
	do {
		puts("Choose one of the following options:");
		puts("\n(1) Sort by price.\n(2) Choose category.\n(3) Add product to cart.\n(4) Refresh Page\n(5) Go back.\n");
		scanf("%d", &choice);
		getchar();
		switch (choice) {

		case SORT_BY_PRICE:
			system("cls");
			puts("\t\t\t\t\t*****VIEW CATALOG*****\n");
			showByPrice();
			break;

		case CHOOSE_CATEGORY:
			system("cls");
			puts("\t\t\t\t\t*****VIEW CATALOG*****\n");
			ShowProductsByCategory();
			break;

		case ADD_PRODUCT:
			addProductToCartMenu(loged_User);
			break;
		case REFRESH_PAGE:
			system("cls");
			puts("\t\t\t\t\t*****VIEW CATALOG*****\n");
			showProducts();//prints the catalog
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
/// VIEW CART MENU FOR CUSTOMER USE
/// </summary>
/// <returns></returns>
void viewCartMenu(User loged_User) {
	int choice;
	enum option { REMOVE_PRODUCT = 1, PROCEED_TO_CHECKOUT = 2, EXIT = 3 };
	do {
		system("cls");
		printf(BOLDGREEN"\t\t\t\t\t*****VIEW CART*****\n"RESET);
		printCartInfo(getCartByUser(loged_User.userName));//print costumer cart
		puts("Choose one of the following options:");
		puts("\n(1) Remove Product From Cart.\n(2) Proceed To Checkout.\n(3) Go back.\n");
		scanf("%d", &choice);
		getchar();
		switch (choice) {

		case REMOVE_PRODUCT:
			removeProductFromCart(loged_User);
			printCartInfo(getCartByUser(loged_User.userName));//print costumer cart
			break;

		case PROCEED_TO_CHECKOUT:
			Create_Order(loged_User.userName);
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
/// ADD PRODUCT MENU FOR COSTUMER
/// </summary>
/// <returns></returns>
void addProductMenu(User loged_User) {
	int choice;

	enum option { ADD_PRODUCT = 1,EXIT = 2};
	do {
		system("cls");
		puts("\t\t\t\t\t*****ADD PRODUCTS TO CART*****\n");
		showProducts();
		puts("Choose one of the following options:");
		puts("\n(1) Add Product.\n(2) Go back.\n");
		scanf("%d", &choice);
		getchar();
		switch (choice) {

		case ADD_PRODUCT:
			addProductToCartMenu(loged_User);
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


//------------------------Auxiliary Functions--------------//

/// <summary>
/// Prints menu for the costumer/manager
///use 'showByCategory' function from Product.h
/// </summary>
/// <returns></returns>
void ShowProductsByCategory() {
	int choice;
	puts("\nChoose one of the categories:[0-4]");
	puts("(0) Fruits\n(1) Vegetables\n(2) Drinks\n(3) Meat\n(4) Farm");
	scanf("%d", &choice);
	showByCategory(choice);
}





///-------Costumer Functions--------///



void addProductToCartMenu(User loged_User) {
	int productSerial=0;
	int quantity=0;
	int flag = 1;
	char* temp [50];
	do
	{
		/*Input and validation check of Serial number*/
		puts("Please enter the serial number of the product you want to add:");
		gets(temp);
		productSerial = atoi(temp);//return 0 if the string is not build from numbers only,otherwise return int
		if (!productSerial) {
			puts("Invalid input....please try again.");
			continue;
		}
		else if (isProductExsist(productSerial))
			flag = 0;
		else
			puts("Invalid serial number....pleas try again.");
	} while (flag);
	do
	{	
		flag = 1;
		/*Input and availability check of quantity*/
		puts("Please enter quantity:[cannot be greater then the available in stock]");
		gets(temp);
		if (!strcmp(temp,"0"))
			return;
		quantity = atoi(temp);
		if (!quantity||quantity<0) {
			puts("Invalid input....please try again.");
			continue;
		}
		else if (getProductQuantity(productSerial) < quantity) {
			puts("Great quantity from the available in stock....please try again.");
			continue;
		}
		else {
			flag = 0;
		}


	} while (flag);

	/*Adds product to cart*/
	addProductToCart(loged_User.userName, productSerial, quantity);
}

/// <summary>
///Remove product from the cart, and update the product quantity in stock.
/// </summary>
/// <returns></returns>

void removeProductFromCart(User loged_User) {
	char* temp[50];
	int serial_number = 0;
	int quantity = 0;
	puts("Enter the serial number of the product you want to remove:");
	gets(temp);
	serial_number = atoi(temp);
	if (atoi(temp)&& isProductExsist(serial_number)) {
		quantity = remove_Product_From_Cart(loged_User.userName, serial_number);
		if (!quantity) {
			puts("Invalid input...The serial number you entered is not in the cart.");
			printf("Press any key to continue...");
			getchar();
		}
		else
			changeProductQuantity(serial_number, ADD, quantity);//Adds the quantity to the available stock.
	}
	else {
		puts("Invalid input....please try again.");
		printf("Press any key to continue...");
		getchar();
	}
}



