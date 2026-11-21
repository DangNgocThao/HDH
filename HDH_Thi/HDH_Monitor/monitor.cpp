#include <stdio.h>
#include <pthread.h>
#include <ctype.h>
#include <semaphore.h>
#include "monitor.h"

//Triển khai monitor bằng semaphore
sem_t mutex;
sem_t next;
//biến đếm
int next_count = 0;

//triển khai biến điều kiện bằng semaphore
//semaphore và biến số nguyên thay thế biến điều kiện
typedef struct
{
	sem_t sem;
	//count variable for philosophers waiting on condition semaphore sem
	int count;
}condition;
condition x[N];

//trạng thái của mỗi triết gia
int state[N];

//biến turn tương ứng với mỗi chiếc đũa
//nếu triết gia i muốn mỗi turn[i] và turn[left] phải được đặt về i
int turn[N];

//wait on condition
void wait(int i)
{
	x[i].count++;
	if (next_count > 0)
	{
		//signal semaphore next
		sem_post(&next);
	}
	else
	{
		//signal semaphore mutex
		sem_post(&mutex);
	}
	sem_wait(&x[i].sem);
	x[i].count--;
	//	printf("\nX.count -> %d",x.count);
}

//signal on condition
void signal(int i)
{
	if (x[i].count > 0)
	{
		next_count++;
		//signal semaphore x[i].sem
		sem_post(&x[i].sem);
		//wait semeaphore next
		sem_wait(&next);
		next_count--;
	}
}
void test(int i)
{
	if (state[i] == HUNGRY && state[LEFT] != EATING && state[RIGHT] != EATING && turn[i] == i && turn[LEFT] == i)
	{
		state[i] = EATING;

		//signal on condition
		signal(i);

		/*	printf("\nNext Count -> %d, X_count -> %d,state[%d] -> %d,state[%d] -> %d,state[%d] -> %d",
			next_count,x[i].count,i,state[i],LEFT,state[LEFT],RIGHT,state[RIGHT]);*/

	}
}

void take_chopsticks(int i)
{
	//wait semaphore mutex
	sem_wait(&mutex);
	state[i] = HUNGRY;
	test(i);
	while (state[i] == HUNGRY)
	{
		//printf("\nThread %d is waiting on condition",i);

		//wait on condition
		wait(i);
	}
	if (next_count > 0)
	{
		//signal semaphore next
		sem_post(&next);
	}
	else
	{
		//signal semaphore mutex
		sem_post(&mutex);
	}
}

void put_chopsticks(int i)
{
	//wait semaphore mutex
	sem_wait(&mutex);
	state[i] = THINKING;
	//đặt biến turn về left và right của các triết gia
	turn[i] = RIGHT;
	turn[LEFT] = LEFT;

	test(LEFT);
	test(RIGHT);

	if (next_count > 0)
	{
		//signal semaphore next
		sem_post(&next);
	}
	else
	{
		//signal semaphore mutex
		sem_post(&mutex);
	}
}

void initialization()
{
	int i;
	sem_init(&mutex, 0, 1);
	sem_init(&next, 0, 0);
	for (i = 0; i < N; i++)
	{
		state[i] = THINKING;
		sem_init(&x[i].sem, 0, 0);
		x[i].count = 0;
		turn[i] = i;
	}
	//thiết lập biến turn sao cho triết gia 0, 2 hoặc 4 có thể dùng đũa đầu tiên
	turn[1] = 2;
	turn[3] = 4;
	turn[6] = 0;
}