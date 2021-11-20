
#include "User.h"
#include "Cart.h"
//#include "Product.h"

void initFiles(); //initialize all files 


int main() {
	initFiles();
	
	////User logedUser = startMenu();//gives us a user without password
	////
	////enum userType logedUserType = logedUser.userType;
	////char logedUserName[MAX_SIZE];
	////strcpy(logedUserName, logedUser.userName);
	//
	//enum userType logedUserType = MANAGER;//for tests
	//
	//showProducts();
	//if (logedUserType == MANAGER)
	//	managerMenu();
	//else
	//	customerMenu();
	//
	signUp();
	User temp;
	login(&temp);
	addProduct();
	addProductToCart(temp.userName,1,10);
	printCartInfo()
	

	return 0;
}



void initFiles(){
	FILE* usersFile, * productsFile, * cartsFile, * ordersFile;
	usersFile = fopen(USERS_FILENAME, "ab");
	if (usersFile == NULL) {
		fprintf(stderr, "\nERROR OPENING USERS FILE\n");
		exit(1);
	}
	else
		fclose(usersFile);
	productsFile = fopen(PRODUCTS_FILENAME, "ab");
	if (productsFile == NULL) {
		fprintf(stderr, "\nERROR OPENING MANAGERS FILE\n");
		exit(1);
	}
	else
		fclose(productsFile);
	cartsFile = fopen(CARTS_FILENAME, "ab");
	if (cartsFile == NULL) {
		fprintf(stderr, "\nERROR OPENING POSTS FILE\n");
		exit(1);
	}
	else
		fclose(cartsFile);
	ordersFile = fopen(ORDERS_FILENAME, "ab");
	if (ordersFile == NULL) {
		fprintf(stderr, "\nERROR OPENING APPLIED FILE\n");
		exit(1);
	}
	else
		fclose(ordersFile);
	return;
}


