/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <string.h>

int main() {
    /* Q3 
    char delicious_snack[100] = "banana";
    
    printf("%d %d\n", (int) strlen(delicious_snack), (int) sizeof(delicious_snack));
    */
    
    /* Q5A
    char s[7] = "banana";
    char t[11] = "apple";
    int i = 0;
    
    strcpy(s, t);
    */
    
    /* Q5c 
    char *s = "banana";
    char *t = "apple";
    int i = 0;
    s = t;
    */
    
    /* Q5b
    char s[7] = "banana";
    char t[11] = "apple";
    int i = 0;
    s = t;
    */ 
    
    /* Q5d
    char s[7] = "apple";
    char t[] = "tamarind";
    int i = 0;
    
    strcpy(s, t);
    for (i = 0; i < 6; i++) {
        printf("%c", s[i]);
    }
    */
    
    /* Q6
    char s[11] = "apple";
    strcat(s, "sauce");
    printf("%s\n", s);
    */
    
    /* Q7
    printf("%d", (int) strcmp("cat", "catsup"));
    */
    
    /* Q8
    char s[] = "gratification", *q;
    q = strchr(s, 'i');
    if (q != NULL) {
        printf("%d\n", (int) (q - s));
    } else {
        printf("Sorry!\n");
    }
    */
    
    /* Q9
    char s[] = "gratification";
    char *p = strchar(s, 'i');
    char *q = strstr(s, "at");
    char *r = strstr(s, "fit");
    printf("%d %c %c %c", (int) *p, q, r);
    */
    
    /* Q10
    char t[8], line[80];
    line[0] = 'c';
    line[1] = 'a';
    line[2] = 't';
    strncpy(t, line, 8);
    */
    
    /* Q11
    char s[] = "granola",
    t[] = "satisfactorily";
    char *p = &s[1];
    strncpy(p, &t[9], 4);
    printf("%s\n", s);
    strcpy(s+2, "at");
    printf("%s", s);
    */
    
    /* Q12
    char s[12] = "cha-cha";
    strcpy(&s[4], s);
    printf("%s", s);
    */
    
    return 0;
}
