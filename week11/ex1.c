#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <string.h>

int main(void) {
    int fd = open("ex1.txt", O_RDWR);
    const char *text = "This is a nice day";
    size_t textsize = strlen(text) + 1;
    lseek(fd, textsize-1, SEEK_SET);
    write(fd, "", 1);
    char *map = mmap(0, textsize, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    for(int i=0;i<textsize;i++){
        map[i] = text[i];
    }
    map[textsize-1] = '\0';
    msync(map, textsize, MS_SYNC);
    munmap(map, textsize);
    close(fd);
    return 0;
}
