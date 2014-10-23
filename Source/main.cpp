#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <conio.h>
#include "main.h"

#define code 7
#define dev_code 767
#define def_malc_size 3333
#define div 1024

int main() {
	long long int i;
	int a;
	printf("Welcome to Wipe alpha! Choose your mode: \n");
	get_des();
	scanf("%d", &a);
	switch (a)
	{
	case 1:
		setup_tool();
		break;
	case 2:
		woid(def_malc_size, 0);
		break;
	case 3:
		printf("bye!\n");
		exit(0);
	}
	getch();
	return 0;
}
