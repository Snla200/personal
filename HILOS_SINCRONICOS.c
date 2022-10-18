/*=========================================================*/
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <pthread.h>
#include <stdlib.h>
/*========================================================*/
void * hilo_1(void * aux);
void * hilo_2 (void* aux);
/*=======================================================*/
short global = 1;
int intento=0;
pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;
/*======================================================*/
int main (void)
{	
	printf("[%d] MAIN: Hola!\n",getpid());
	int num = 99;
	pthread_t tid_1,tid_2;
	pthread_create(&tid_1,NULL, hilo_1, (void*)&tid_1); //--> hilo_1((void*)&tid_1);
	pthread_create(&tid_2,NULL, hilo_2, (void*)&tid_2); //-> hilo_2((void*)&tid_2)
	/*-----------------------------------------------------*/
	printf("[%d] MAIN: Trabajando...  num = (%p) -> [%d]\n",getpid(),&num,num);
	printf("[%d] MAIN: Thread ID = (%ld) \n",getpid(),tid_1);
	/*-----------------------------------------------------*/
	pthread_join(tid_1,NULL);
	pthread_join(tid_2,NULL);
	printf("[%d] MAIN: Finalizando...[%d]\n",getpid(),num);
	return 0;
}
/*=========================================================*/
void* hilo_1 (void* aux)
{	int* z = (int*)aux;
	(*z)++;
	printf("[%d] HILO_1: Variable = (%p) -> [%d]\n",getpid(),z,*z);
	pthread_mutex_lock(&mtx);
	printf("[%d] HILO_1: MUTEX ¡BLOQUEADO! = (%p)\n",getpid(),&mtx);
	printf("mutex trylock= %d\n",pthread_mutex_trylock(&mtx));
	sleep(5);
	pthread_mutex_unlock(&mtx);
	printf("[%d] HILO_1: MUTEX ¡DESBLOQUEADO! = (%p)\n",getpid(),&mtx);
	printf("%d\n",pthread_mutex_trylock(&mtx));
	printf("[%d] HILO_1: Finalizando...\n",getpid());
	return NULL; 
}
/*=========================================================*/
void* hilo_2 (void* aux)
{	int* z = (int*)aux;
	srand(time(NULL));
	(*z)++;
	printf("[%d] HILO_2: Variable = (%p) -> [%d]\n",getpid(),z,*z);
	while(global){
		intento++;
		
		printf("intento N°%d\n",intento);
		if (((rand() % 101) < 5) &&  pthread_mutex_trylock(&mtx) > 0)
		{
			global=0;
		}
		sleep(1);
	}
	printf("[%d] HILO_2: Finalizando...\n",getpid());
	return NULL; 
}
/*=========================================================*/
