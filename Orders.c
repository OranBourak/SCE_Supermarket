
#include "Orders.h"
#include "Structs.h"
#include "Cart.h"
#define MAX

void Create_Order(char* username)
{
	FILE* Orders;
	Cart temp;
	Order temp1;
	Product orderp;

	Orders = fopen(ORDERS_FILENAME, "r+");
	if (Orders == NULL)
	{
		fprintf(stderr, "\n Error open orders");
		exit(1);
	}
	FILE* User = fopen(USERS_FILENAME, "r+");
	if (User == NULL) {
		fprintf(stderr, "\nERROR OPENING FILE\n");
		exit(1);
	}
	while (fread(&temp, sizeof(Cart), 1, User)) {//Find the cart by user name and read the cart to temp parameter.
		{
			if (!strcmp(temp.userName, username))
				break;
		}
	}
	FILE* Cart= fopen(CARTS_FILENAME, "r");
	if (Cart == NULL) {
		fprintf(stderr, "\nERROR OPENING FILE\n");
		exit(1);
	}
	
	strcpy(temp1.userName , temp.userName);
	for (int i = 0; i < temp.productCounter; i++)
	{
		temp1.cart_list[i] = temp.productsInCart[i];
	}
	printf("Enter id:\n");
	fscanf(ORDERS_FILENAME, "%d", temp1.customer_id);
	printf("Enter full name:\n");
	fscanf(ORDERS_FILENAME, "%c", temp1.customer_full_name);
	printf("Enter cradit cart:\n");
	fscanf(ORDERS_FILENAME, "%d", temp1.customer_credit_card);
	printf("Enter address:\n");
	fscanf(ORDERS_FILENAME, "%d", temp1.customer_address);
	
	for (int i = 0; i < temp.productCounter; i++)
	{
		temp1.orderPrice += temp.productsInCart[i].productPrice;

	}
	temp1.status = APPENDING;

	fclose(Orders);
}




 void change_order_status(char* username)
{
	 User user;
	 Order order;
	 FILE* fpointerU;
	 FILE* fpointerO;
	 int choice=2;
	 fpointerU = fopen(USERS_FILENAME, "r+");
	 fpointerO = fopen(ORDERS_FILENAME, "r+");
	 if (fpointerU == NULL) {
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
