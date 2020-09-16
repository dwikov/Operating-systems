
#include <pthread.h> 
#include <stdio.h>
#include <stdlib.h>


void *myThread(void *tid) {
	printf("Thread number %d is created and executed...\n", tid); 
	pthread_exit(NULL);
}

int main(int argc, char *argv[]) {

	pthread_t threads[10];
	int status, i;
	for(i=0; i < 10; i++) {
		printf("Creating thread %d...\n", i);
		status = pthread_create(&threads[i], NULL, myThread, (void *)i);
		if (status != 0) {
		printf("Error %d in thread creation\n", status); 
			return -1;
	    	} 
		status = pthread_join(threads[i],NULL);
		if (status == 0) {
			printf("Thread %d exits\n",i);
	    	} 

	}
}



