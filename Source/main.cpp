#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>
#include <conio.h>
#include "main.h"

#define code 7
#define dev_code 767
#define def_malc_size 3333
#define div 1024

int main() {
	printf("Welcome to Wipe alpha! Choose your mode: \n");
	select_mode(def_malc_size);
	return 0;
}

int get_des(void) { //program description;
	printf("1 - setup memory limit and run\n2 - run without limit(lol)\n4 - Dev tools\n5 - exit\nMode: ");
	return 0;
}

int select_mode(int mal_size) { //program modes here
	int a;
	get_des();
	scanf("%d", &a);
	switch (a)
	{
	case 1:
		setup_tool(mal_size);
		break;
	case 2:
		woid(mal_size, 0);
		break;
	case 4:
		dev_tool(mal_size);
	case 5:
		exit();
		break;
	}
	return 0;
}

int woid(int mal_size, int limit) { //eat RAM
	int a,i, memory_start, memory_end;
	float * get_mem;
	long long int diftime;
	MEMORYSTATUSEX statex; //getting current memory status
	statex.dwLength = sizeof (statex);
	GlobalMemoryStatusEx(&statex);
	printf("Ready? ");
	for (i = 3; i != 0; i--) {
		printf("%d.. ", i);
		Sleep(1000);
	}
	system("cls");
	printf("Start eating memory... Please wait");
	memory_start = statex.ullAvailPhys / div / div;
	const time_t timer1 = time(NULL); //start time
	while (true){
		GlobalMemoryStatusEx(&statex);
		if (((statex.ullAvailPhys / div / div) < (memory_start - limit)) && (limit != 0)) {
			const time_t timer2 = time(NULL); //end time
			diftime = timer2 - timer1; //operation time
			memory_end = memory_start - statex.ullAvailPhys / div / div;
			printf("\nAvailable memory (MB): %d\nTook %d mb for %d sec with %d kb malloc size\n", statex.ullAvailPhys / div / div, memory_end, diftime,mal_size);
			break;
		}
		get_mem = (float *)malloc(mal_size); 
	}
	free(get_mem);
	printf("Enter 1 to show program modes, 0 to exit: ");
	scanf("%d", &a);
	if (a == 1) {
		system("cls");
		select_mode(mal_size);
	}
	else {
		exit();
	}
	return 0;
}

int setup_tool(int mal_size) { //setup tool
	int memory_limit;
	MEMORYSTATUSEX statex; //get user memory state
	statex.dwLength = sizeof (statex);
	GlobalMemoryStatusEx(&statex);
	system("cls");
	printf("Total memory (MB): %d\n", statex.ullTotalPhys / div / div);
	printf("Current available memory (MB): %d\n", statex.ullAvailPhys / div / div);
	printf("Malloc size(KB): %d\n", mal_size);
	printf("Enter memory limit: ");
	scanf("%d", &memory_limit);
	woid(mal_size, memory_limit);
	return 0;
}

int dev_tool(int mal_size) { //dev tools with one tool (malloc size) TODO more (but what?)
	int new_mal_size;
	system("cls");
	printf("Dev tools here.\nCurrent malloc size(KB): %d\nEnter malloc size (0 for default value): ", mal_size);
	scanf("%d", &new_mal_size);
	if (new_mal_size == 0) {
		printf("Backing to default value...\n");
		setup_tool(def_malc_size);
	}
	else {
		printf("Set malloc size to %d, starting setup tool...", new_mal_size);
		setup_tool(new_mal_size);
	}
	return 0;
}

int exit(void) { //guess what this function does
	printf("bye!\n");
	exit(0);
	return 0;
}