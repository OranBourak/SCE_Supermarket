#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "Structs.h"
#include "User.h"
#include "Product.h"
#include "Cart.h"
#include "Orders.h"

/// <summary>
/// MAIN MENU function
/// </summary>
void Menu();

//-----------------------------MANAGER-MENU-SECTION-------------------------//

/// <summary>
/// MANAGER MENU SYSTEM
///Displays the options to the manager and activates the requested function
/// </summary>
/// <param name="loged_User"></param>
void managerMenu(User loged_User);

/// <summary>
///view catalog menu for manager
///Displays the options to the customer and activates the requested function
/// </summary>
void viewCatalogManager();

/// <summary>
/// Update inventory func:
///prints the options for the manager and activates the requested function
/// </summary>
/// <returns></returns>
void updateInventoryMenu();

void updateProductQuantityMenu();
void changeProductPriceMenu();

void UpdateOrdersMenu();

/// <summary>
/// UPDATE PRODUCT MENU 
/// </summary>
/// <returns></returns>
void UpdateProductMemu();



//-----------------------------COSTUMER-MENU-SECTION-------------------------//

/// <summary>
/// CUSTOMER MENU SYSTEM
///Displays the options to the customer and activates the requested function
/// </summary>
/// <returns></returns>
void customerMenu(User loged_User);

/// <summary>
/// view catalog menu for manager
///Displays the options to the customer and activates the requested function
/// </summary>
/// <param name="username">Using username in Add product function</param>
/// <returns></returns>
void viewCatalogCustomer(User loged_User);

/// <summary>
/// VIEW CART MENU FOR CUSTOMER USE
/// </summary>
/// <returns></returns>
void viewCartMenu(User loged_User);

/// <summary>
/// ADD PRODUCT MENU FOR COSTUMER
/// </summary>
/// <returns></returns>
void addProductMenu(User loged_User);

void viewOrdersMenu(User loged_User);

void clubMemberMenu(User* loged_User);

//------------------------Auxiliary Functions--------------//

/// <summary>
/// Prints menu for the costumer/manager
///use 'showByCategory' function from Product.h
/// </summary>
/// <returns></returns>
void ShowProductsByCategory();

///-------Costumer Functions--------///

void addProductToCartMenu(User loged_User);

/// <summary>
///Remove product from the cart, and update the product quantity in stock.
/// </summary>
/// <returns></returns>
void removeProductFromCart(User loged_User);

void cancelOrderByCustomer(User loged_User);

void changeMembership(User* loged_User);