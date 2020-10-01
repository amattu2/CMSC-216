#include <stdio.h>

int main()
{
    /*
    zero iterations
    int x = 1;
    */ 
    /*
    one iteration
    int x = 0;
    */
    
    while (!x) {
        x++;
        printf("Iteration\n");
        
        if (x > 9) { break; } /* infinity simulator */
    }
    
    return 0;
}