#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>
#define def_malc_size 3333
#define div 1024

int get_des(void) {
	printf("1 - setup memory limit and run\n2 - run without limit(lol)\n3 - exit\nMode: ");
	return 0;
}

int woid(int mal_size, int limit) {
	int i,memory_start,memory_end;
	float * get_mem;
	long long int diftime;
	MEMORYSTATUSEX statex;
	statex.dwLength = sizeof (statex);
	GlobalMemoryStatusEx(&statex);
	printf("Ready? ");
	for (i = 3; i != 0; i--) {
		printf("%d.. ", i);
		_sleep(1000);
	}
	memory_start = statex.ullAvailPhys / div / div;
	const time_t timer1 = time(NULL);
	while (true){
		GlobalMemoryStatusEx(&statex);
		if (((statex.ullAvailPhys / div / div) < (memory_start - limit)) && (limit!=0)) {
			const time_t timer2 = time(NULL);
			diftime = timer2 - timer1;
			memory_end = memory_start - statex.ullAvailPhys/div/div;
			printf("\nAvailable memory (MB): %d\nTook %d mb for %d sec\n", statex.ullAvailPhys / div / div,memory_end,diftime);
			break;
		}
		get_mem = (float *)malloc(mal_size);
	}
	free(get_mem);
	return 0;
}

int setup_tool(void) { //средства разработчиков
	int memory_limit;
	MEMORYSTATUSEX statex; //состояние памяти
	statex.dwLength = sizeof (statex);
	GlobalMemoryStatusEx(&statex);
	printf("Total memory (MB): %d\n", statex.ullTotalPhys / div / div);
	printf("Current available memory (MB): %d\n", statex.ullAvailPhys / div / div);
	printf("Enter limit: ");
	scanf("%d", &memory_limit);
	woid(def_malc_size, memory_limit);
	return 0;
}