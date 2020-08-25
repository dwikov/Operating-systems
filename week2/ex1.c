#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {
    int a = INT_MAX;
    float b = FLT_MAX;
    double c = DBL_MAX;
    printf("%lu %d\n",sizeof(a),a);
    printf("%lu %f\n",sizeof(b),b);
    printf("%lu %f\n",sizeof(c),c);
}

