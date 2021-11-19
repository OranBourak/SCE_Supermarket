#include "Cart.h"

void printCartInfo(Cart* cart)
{
	printf("\nProduct List:\n");
		for (int i = 0; i < cart->productCounter; i++)
			printf("Product name: %s    Product quantity:%d\n", cart->productsInCart->productName, cart->productsInCart[i].quantity);
		printf("\n----------------------------------------------------------------------\n\n");
}
