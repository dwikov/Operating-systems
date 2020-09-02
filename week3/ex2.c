
#include <stdio.h>

void swap(int *x, int *y);
void bubble_sort(int x[], int size);


int main() {
    int a[10] = {3,2,1,7,6,5,4,8,9, 0};
    bubble_sort(a, 10);
    for (int i = 0; i < 10; i++)
        printf("%d ", a[i]);
    return 0;
}

void bubble_sort(int x[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (x[j] > x[j + 1])
                swap(&x[j], &x[j+1]);
        }
    }
}

void swap(int *x, int *y) {
    int tmp = *x;
    *x = *y;
    *y = tmp;
}
