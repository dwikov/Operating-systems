#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>


int main(){
	int n = 0;
	if (fork() == 0){
		printf("Hello from child [%d - %d]\n",getpid(),n);
	}else{
		printf("Hello from parent [%d - %d]\n",getpid(),n);
	}
}

/*
the program's output was:

Hello from parent [5718 - 0]
Hello from child [5719 - 0]

because our program is ran as a parent process with id: 5718
and was ran as a child process with id: 5719
*/
