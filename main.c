#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "DataStructures.h"

int main() {
	User logedUser = startMenu();
	puts("TEST, WE ARE BACK IN MAIN");
	puts("PROOF WE GOT USER DETAILS:");
	printf("  User's name: %s, type: %d\n", logedUser.userName, logedUser.userType);
	puts("PROOF WE GOT NO PASSWORD:");
	printf("  Garbage password: %s\n", logedUser.password);
	return 0;
}