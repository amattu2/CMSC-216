/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

int main() {
    /**
     * Worksheet 4, Q2 (a-g)
    */
    int arr[10] = {9, 4, 6, 3, 1, 5, 2, 8, 7, 10};
    int *p = &arr[2], *q = &arr[6];
    
    // (a)
    //printf("%d", *(p + 1));
    
    // (b)
    //printf("%d", *(p) + 1);
    
    // (c)
    //printf("%d", (int) (q - p));
    
    
    // (d)
    //printf("%d", (int) (*q - *p));
    
    // (e)
    //printf("%d", q[*q]);
    
    // (f)
    //printf("%d", ++*q);
    
    // (g)
    //printf("%d", (int) sizeof(p[3]));
    
    return 0;
}
