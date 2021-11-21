
#include "Orders.h"
#include "Structs.h"
#include "Cart.h"
#define MAX

void Create_Order(char* username)
{
	FILE* Orders;
	FILE* carts_file;
	FILE* fpointerU;
	Cart cart;
	Order order;
	Product orderp;
	User user;

	Orders = fopen(ORDERS_FILENAME, "r+");
	if (Orders == NULL)
	{
		fprintf(stderr, "\n Error open orders");
		exit(1);
	}
	carts_file = fopen(CARTS_FILENAME, "r+");
	if (carts_file == NULL)
	{
		fprintf(stderr, "\n Error open orders");
		exit(1);
	}
	fpointerU = fopen(USERS_FILENAME, "r+");
	if (fpointerU == NULL)
	{
		fprintf(stderr, "\n Error open orders");
		exit(1);
	}

	fread(&cart, sizeof(Cart), 1, carts_file);

	while (fread(&cart, sizeof(Cart), 1, fpointerU)) {
		{
			if (!strcmp(cart.userName, username))
				break;
		}
	}
	//FILE* User = fopen(USERS_FILENAME, "r+");
	//if (User == NULL) {
	//	fprintf(stderr, "\nERROR OPENING FILE\n");
	//	exit(1);
	//}
	//while (fread(&cart, sizeof(Cart), 1, User)) {//Find the cart by user name and read the cart to temp parameter.
	//	{
	//		if (!strcmp(cart.userName, username))
	//			break;
	//	}
	//}
	//FILE* cart= fopen(CARTS_FILENAME, "r+");
	//if (cart == NULL) {
	//	fprintf(stderr, "\nERROR OPENING FILE\n");
	//	exit(1);
	//}
	
	strcpy(order.userName , cart.userName);
	for (int i = 0; i < cart.productCounter; i++)
	{
		strcpy(order.cart_list[i].productName, cart.productsInCart[i].productName);
		order.cart_list[i].productPrice = cart.productsInCart[i].productPrice;
		order.cart_list[i].product_category = cart.productsInCart[i].product_category;
		order.cart_list[i].quantity = cart.productsInCart[i].quantity;
		order.cart_list[i].serialNumber = cart.productsInCart[i].serialNumber;

	}
	int id=0;
	printf("Enter id:\n");
	scanf("%d", &id);
	/*fscanf(ORDERS_FILENAME, "%d", order.customer_id);
	printf("Enter full name:\n");
	fscanf(ORDERS_FILENAME, "%c", order.customer_full_name);
	printf("Enter cradit cart:\n");
	fscanf(ORDERS_FILENAME, "%d", order.customer_credit_card);
	printf("Enter address:\n");
	fscanf(ORDERS_FILENAME, "%d", order.customer_address);*/
	
	for (int i = 0; i < cart.productCounter; i++)
	{
		order.orderPrice += cart.productsInCart[i].productPrice;

	}
	order.status = APPENDING;
	fwrite(&order, sizeof(Order), 1, Orders);

	fclose(Orders);
	fclose(carts_file);
	fclose(fpointerU);
}




 void change_order_status(char* username)
{
	 User user;
	 Order order;
	 FILE* fpointerU;
	 FILE* fpointerO;
	 int choice=2;
	 fpointerU = fopen(USERS_FILENAME, "r+");
	 if (fpointerU == NULL) {
		 fprintf(stderr, "\nERROR OPENING FILE\n");
		 exit(1);
	 }
	 fpointerO = fopen(ORDERS_FILENAME, "r+");
	 if (fpointerO == NULL) {
		 fprintf(stderr, "\nERROR OPENING FILE\n");
		 exit(1);
	 }
	 fread(&order, sizeof(Order), 1, fpointerO);

	 while (fread(&user, sizeof(User), 1, fpointerU)) {
		 {
			 if (!strcmp(user.userName, username))
				 break;
		 }
	 }
	 while (fread(&order, sizeof(Order), 1, fpointerU)) {//Find the order by user name 
		 {
			 if (!strcmp(order.userName, username))
				 break;
		 }
	 }
	 if (order.status == APPENDING)
	 {
		 if (user.userType == MANAGER)
		 {

			 printf("Would you like to cancel or approve the order\nPress 1 to approve or 2 to cancel\n");
			 scanf("%d", &choice);
			 while (choice != 1 || choice != 2)
			 {
				 if (choice == 1)
				 {
					 order.status = APPROVED;
					 break;
				 }
				 if (choice == 2)
				 {
					 order.status = CANCELD;
					 break;
				 }

				 else
					 printf("You entered wrong answer, please try again\n");

			 }






		 }

		 else
		 {
			 
			 while (choice != 1 || choice != 2)
			 {
				 printf("Would you like to cancel your order?\nPress 1 for yes or 2 for no\n");
				 scanf("%d", &choice);

				 if (choice == 1) {
					 order.status = CANCELD;
					 break;
				 }

				 if (choice == 2)
					 break;
				 
				 else
					 printf("You entered wrong answer, please try again\n");

			 }


		 }
	 }
	  else
		 printf("there is no appending order\n");


	 fclose(fpointerO);
	 fclose(fpointerU);
}
