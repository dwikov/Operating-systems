#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct page{
    int counter;
    int id;
};

int main(int argc, char *argv[]) {
    if(argc<=1) {
        printf("Please pass the number of pages as an argument.\n");
        exit(1);
    }
    const int number_of_page_files = atoi(argv[1]);
    struct page memory[number_of_page_files];
    for(int i=0;i<number_of_page_files;i++){
        memory[i].counter = -1;
        memory[i].id = -1;
    }
    FILE *File;
    File = fopen("Lab 09 input.txt", "r");
    int curr;
    int miss=0,hit=0;
    fscanf (File, "%d", &curr);
    while(!feof(File)){
        bool found = 0;
        int idx_min = 0;
        for(int i=0;i<number_of_page_files;i++){
            if(memory[idx_min].counter>memory[i].counter){
                idx_min = i;
            }
            memory[i].counter = memory[i].counter>>1;
            if(memory[i].id == curr){
                hit++;
                found = 1;
                memory[i].counter += (1<<7);
            }
        }
        if(!found){
            miss++;
            memory[idx_min].id = curr;
            memory[idx_min].counter = (1<<7);
        }
        fscanf (File, "%d", &curr);
    }
    printf("Hits: %d\nMisses: %d\n",hit,miss);
    printf("The ratio of Hit/Miss is %f\n",(float)hit/miss);
}
