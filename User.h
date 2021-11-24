#pragma once

#define MANAGER_CODE "qwerty"
#define PASSWORD_MIN_LENGTH 6

#include "Structs.h"
#include "Cart.h"




//USER declaration and related functions 
User startMenu();
enum Bool login(User*);//to add? inform if username wrong or password?
void signUp();
enum Type managerSignUp();
enum Bool isNameTaken(char*);
enum Bool isPasswordLegal(char*);
void ContactUs();


