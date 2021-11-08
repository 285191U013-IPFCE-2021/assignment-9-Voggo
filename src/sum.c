#include "sum.h"

int sum(int a[], int n)
{
    int result;

    if (n == 0){
        return 0;
    } else {
        result = result + a[n-1];
        return result + sum(a, n-1);;
    }
}