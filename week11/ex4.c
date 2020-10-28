#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int src, dist;
    char *file1, *file2;
    size_t fsize;

    src = open("ex1.txt", O_RDONLY);
    fsize = lseek(src, 0, SEEK_END);
    file1 = mmap(NULL, fsize, PROT_READ, MAP_PRIVATE, src, 0);

    dist = open("ex1.memcpy.txt", O_RDWR | O_CREAT, 0666);
    ftruncate(dist, fsize);
    file2 = mmap(NULL, fsize, PROT_READ | PROT_WRITE, MAP_SHARED, dist, 0);
    
    memcpy(file2, file1, fsize);

    munmap(file1, fsize);
    munmap(file2, fsize);

    close(src); close(dist);
    return 0;
}
