/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

int main() {
    /**
     * Worksheet 4, Q1 (a-d)
    */
    int arr[] = {2, 4, 6, 8, 10};
    int *p = &arr[2];
    
    // (a)
    //printf("%d ", *p++);
    //printf("%d ", *p);
    //printf("%d %d %d %d %d\n", arr[0], arr[1], arr[2], arr[3], arr[4]);
    
    // (b)
    //printf("%d ", (*p)++);
    //printf("%d ", *p);
    //printf("%d %d %d %d %d\n", arr[0], arr[1], arr[2], arr[3], arr[4]);
    
    // (c)
    //printf("%d ", *++p);
    //printf("%d ", *p);
    //printf("%d %d %d %d %d\n", arr[0], arr[1], arr[2], arr[3], arr[4]);    

    // (d)
    //printf("%d ", ++*p);
    //printf("%d ", *p);
    //printf("%d %d %d %d %d\n", arr[0], arr[1], arr[2], arr[3], arr[4]);
    
    return 0;
}
