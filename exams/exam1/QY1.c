#include <stdio.h>

int main()
{
    int arr[] = {4, 6, 1, 8, 2, 5, 4, 0, 9, 7};
    
    int *p = &arr[2];
    int *q = &arr[5];
    
    printf("%d", p - arr);
    
    return 0;
}