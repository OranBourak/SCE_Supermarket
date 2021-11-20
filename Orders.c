//#include "Orders.h"
//#include "Structs.h"
//#include "Cart.h"
//#define MAX
//
//void Create_Order(char* username)
//{
//	FILE* Orders;
//	Cart temp;
//	Order temp1;
//	Product orderp;
//
//	Orders = fopen(ORDERS_FILENAME, "r+");
//	if (Orders == NULL)
//	{
//		fprint(stderr, "\n Error open orders");
//		exit(1);
//	}
//	FILE* User = fopen(USERS_FILENAME, "r+");
//	if (User == NULL) {
//		fprintf(stderr, "\nERROR OPENING FILE\n");
//		exit(1);
//	}
//	while (fread(&temp, sizeof(Cart), 1, User)) {//Find the cart by user name and read the cart to temp parameter.
//		{
//			if (!strcmp(temp.userName, username))
//				break;
//		}
//	}
//	FILE* Cart= fopen(CARTS_FILENAME, "r");
//	if (Cart == NULL) {
//		fprintf(stderr, "\nERROR OPENING FILE\n");
//		exit(1);
//	}
//	
//	strcpy(temp1.userName , temp.userName);
//	temp1.productInOrder = temp.productCounter;
//	for (int i = 0; i < MAX_Products_In_Cart; i++)
//	{
//		temp1.cart_list[i] = temp.productsInCart[i];
//	}
//	printf("Enter id:\n");
//	fscanf(ORDERS_FILENAME, "%d", temp1.customer_id);
//	printf("Enter full name:\n");
//	fscanf(ORDERS_FILENAME, "%c", temp1.customer_full_name);
//	printf("Enter cradit cart:\n");
//	fscanf(ORDERS_FILENAME, "%d", temp1.customer_credit_card);
//	printf("Enter address:\n");
//	fscanf(ORDERS_FILENAME, "%d", temp1.customer_address);
//
//
//}
//
//
//
//
////
////char userName[MAX_SIZE]; //customer website Username
////enum Status status;//Order's sataus
////Product  cart_list[MAX_Products_In_Cart]; //add products list and quantity
////char customer_full_name[MAX_SIZE];
////unsigned long int customer_id;
////unsigned long int customer_credit_card;
////char customer_address[MAX_SIZE];
////unsigned int productInOrder;