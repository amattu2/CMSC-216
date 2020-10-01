#include <stdio.h>

int main() {
    int x, y;
    
    /*
    zero iterations
    x = 0;
    y = 0;
    */
    /*
    infin iterations
    x = 0;
    y = 1;
    */
    
    while (x + y) {
        x--;
        y++;
        printf("Iteration\n");
        
        if (y > 9) { break; } /* infinity simulator */
    }
    
    return 0;
}