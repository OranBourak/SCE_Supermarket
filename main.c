#include "User.h"
#include "Cart.h"
#include "Orders.h"
//#include "Product.h"
/*initialize all data files */
void initFiles(); 

int main() {
	initFiles();
	Menu();




	
	

	return 0;
}



//initialize all data files 
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

	
	return ;
}


