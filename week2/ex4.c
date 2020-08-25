#include <stdio.h>
void swap(int *a,int *b){
    int l = *b;
    *b = *a;
    *a = l;
}
int main() {
    int x,y;
    scanf("Please enter two integers...\n");
    scanf("%d%d",&x,&y);
    swap(&x, &y);
    printf("%d %d",x,y);
}
