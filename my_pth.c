//multi threaded programming with pthreads, execution of classic producer consumer using condition variables

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#define MAX 5

int buffer=0;
int data_ready = 0;
int toconsume =0;
int i=0;

pthread_t con;
pthread_t pro;
pthread_mutex_t mumu ;
pthread_cond_t condc;
pthread_cond_t condp;

void* producer (void* arg);
void* consumer (void* arg);


void* producer (void* arg)
{	for (int i=0; i<MAX; i++){
	printf("Producer---->\n");
	pthread_mutex_lock(&mumu);

	while (buffer!=0)				//if buffer is full 
		pthread_cond_wait(&condp,&mumu);   // wait here till a counter signal is received and now release the mutex since cond is not met
	printf("Producer: is producing----> %d\n",i);
	toconsume++;
	pthread_cond_signal(&condc);
	pthread_mutex_unlock(&mumu);
	sleep(1);

}

pthread_exit(0);
}

void* consumer (void* arg) {
	printf("consumer---->\n");
	for (int i=0; i<MAX ; i++){
		pthread_mutex_lock(&mumu);
		while (toconsume <=0)
			pthread_cond_wait(&condc,&mumu);
		printf("Consumer : is consuming---->%d\n",i);
		//pthread_mutex_unlock(&mumu);
		toconsume--;
		pthread_cond_signal(&condp);
		pthread_mutex_unlock(&mumu);
	}

pthread_exit(0);
}

int main(int argc, char const *argv[])
{
	pthread_mutex_init(&mumu, NULL);
    	pthread_cond_init(&condc, NULL); 
    	pthread_cond_init(&condp, NULL); 

	pthread_create(&con,NULL,consumer,NULL);
	pthread_create(&pro,NULL,producer,NULL);

	pthread_join(con,NULL);
	pthread_join(pro,NULL);

	pthread_mutex_destroy(&mumu);
    	pthread_cond_destroy(&condc); 
    	pthread_cond_destroy(&condp);


	return 0;
}
