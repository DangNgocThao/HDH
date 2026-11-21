#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <ctype.h>
#include <string.h>
#include <Windows.h>
#include "monitor.h"

//pthread_mutex_t lock;

void* philosopher(void* i)
{
	while (1)
	{
		//biến đại diện cho triết gia 
		int self = *(int*)i;
		int j, k;
		j = rand();
		j = j % 11;
		printf("Triet gia %d dang suy nghi trong %d giay\n", self, j);
		Sleep(j);
		//triết gia nhấc đũa lên
		take_chopsticks(self);
		k = rand();
		k = k % 4;
		printf("Triet gia %d dang an trong %d giay\n", self, k);
		Sleep(k);
		//triết gia đặt đũa xuống
		put_chopsticks(self);
	}

}

int main()
{
	int i, pos[N];
	//một thread tương ứng một triết gia
	pthread_t thread[N];
	pthread_attr_t attr;

	//initilize semaphore and other variables
	initialization();

	pthread_attr_init(&attr);

	for (i = 0; i < N; i++)
	{
		pos[i] = i;
		//tạo thread tương ứng với một triết gia
		pthread_create(&thread[i], NULL, philosopher, (int*)&pos[i]);
	}
	for (i = 0; i < N; i++)
	{
		pthread_join(thread[i], NULL);
	}

	return 0;
}