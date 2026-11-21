#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <Windows.h>

#define N 5
#define SUYNGHI 2
#define DOI 1
#define AN 0
#define TRAI (phnum + 4) % N
#define PHAI (phnum + 1) % N

int state[N];
int phil[N] = { 0,1,2,3,4 };//5 triết gia

sem_t mutex;
sem_t S[N];

void test(int phnum)
{
	if (state[phnum] == DOI && state[TRAI] != AN && state[PHAI] != AN)
	{
		//Trạng thái ăn
		state[phnum] = AN;
		Sleep(2);
		printf("Triet gia %d lay dua %d va %d\n", phnum + 1, TRAI + 1, phnum + 1);
		printf("Triet gia %d an\n", phnum + 1);
		sem_post(&S[phnum]);
	}
}

//Cầm đũa
void take_fork(int phnum)
{
	sem_wait(&mutex);
	//Trạng thái đói
	state[phnum] = DOI;
	printf("Triet gia %d doi\n", phnum + 1);
	//ăn nếu người bên cạnh không ăn
	test(phnum);
	sem_post(&mutex);
	//Nếu không thể ăn đợi để được báo hiệu ăn
	sem_wait(&S[phnum]);
	Sleep(1);
}

//Đặt đũa xuống
void put_fork(int phnum)
{
	sem_wait(&mutex);
	//Trạng thái suy nghĩ
	state[phnum] = SUYNGHI;
	printf("Triet gia %d dat dua %d va %d xuong\n", phnum + 1, TRAI + 1, phnum + 1);
	printf("Triet gia %d suy nghi\n", phnum + 1);
	test(TRAI);
	test(PHAI);
	sem_post(&mutex);
}

void* philospher(void* num)
{
	while (1)
	{
		int* i = (int*)num;
		Sleep(1);
		take_fork(*i);
		Sleep(0);
		put_fork(*i);
	}
}

int main()
{
	int i;
	pthread_t thread_id[N];
	//Khởi tạo Semaphores
	sem_init(&mutex, 0, 1);
	for (i = 0; i < N; i++)
		sem_init(&S[i], 0, 0);
	for (i = 0; i < N; i++)
	{
		//Tạo các tiến trình "triết gia"
		pthread_create(&thread_id[i], NULL, philospher, &phil[i]);
		printf("Triet gia %d suy nghi\n", i + 1);
	}
	for (i = 0; i < N; i++)
		pthread_join(thread_id[i], NULL);
}