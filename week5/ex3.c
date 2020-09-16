#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>



pthread_mutex_t the_mutex;
pthread_cond_t condc, condp;
int buffer = 0;
int i = 1;

void *producer(void *ptr)
{
	
	while(1){
		while(buffer == 10) 
			pthread_cond_wait(&condp,&the_mutex);
		i = i + 1;
		buffer = i;
		printf("produced item N=%d\n", i);
		pthread_cond_signal(&condc);
		
	}
	pthread_exit(0);
}

void *consumer(void *ptr)
{

	while(1){
		while(buffer == 0) 
			pthread_cond_wait(&condc,&the_mutex);
		
		i = i - 1;
		buffer = i;
		printf("Consumer takes item N=%d\n",buffer);
		pthread_cond_signal(&condp);
		
	}
	pthread_exit(0);
}

int main(int argc, char **argv){ 
	pthread_t pro, con;  
	pthread_cond_init(&condc, 0); 
	pthread_cond_init(&condp, 0); 
	pthread_create(&con, 0, consumer, 0);
	pthread_create(&pro, 0, producer, 0); 
	pthread_join(pro, 0);
	pthread_join(con, 0); 
	pthread_cond_destroy(&condc);

	pthread_cond_destroy(&condp);
}
