#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char *directory = "/home/tmgbug/week10/tmp";
    size_t directory_length = strlen(directory);
    char *path = malloc(directory_length + 1 + NAME_MAX);
    strcpy(path, directory);
    path[directory_length] = '/';
    DIR *dirp = opendir(directory);
    struct dirent *dp;
    struct stat st;
    while ((dp = readdir(dirp)) != NULL){
        if(dp->d_name[0] == '.')continue;
        strcpy(path + directory_length + 1, dp->d_name);
        if(stat(path,&st) == -1){
            perror(path);
            continue;
        }
        int inode = st.st_ino;
        if(st.st_nlink < 2)continue;
        printf("file '%s' with inode %d is linked to: ",dp->d_name,inode);
        DIR *dirp1 = opendir(directory);
        struct dirent *dp1;
        struct stat st1;
        while((dp1 = readdir(dirp1)) != NULL){
            strcpy(path + directory_length + 1, dp1->d_name);
            if(stat(path,&st1) == -1){
                perror(path);
                continue;
            }
            if(st1.st_ino == inode){
                printf("%s ",dp1->d_name);
            }
        }
        printf("\n");
    }
}
