#include <stdio.h>
int main(int argc, char *argv[]) {
    int n;
    sscanf(argv[1],"%d",&n);
    for(int i=1;i<=n;i++){
        int len = 2*n-1 - (2*i-1);
        for(int j=0;j<len/2;j++){
            printf(" ");
        }
        for(int j=0;j<2*i-1;j++) {
            printf("*");
        }
        printf("\n");
    }
}
