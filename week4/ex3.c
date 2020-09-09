#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int main(){
	char word[20];

	while(true){
		printf("admin@dwik: ");
		fgets(word,sizeof(word),stdin);
		system(word);
	}
}
