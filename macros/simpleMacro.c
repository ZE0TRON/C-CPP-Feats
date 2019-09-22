#include <stdio.h>
#define BUFSIZE 1024
#define TABLESIZE BUFSIZE
#define min(X,Y) ((X) < (Y) ? (X) : (Y))
int main() {
    int table[TABLESIZE];
    int minimum = min (20,30);
    float minimum2  = min (1.34,1.02);
    int minimum3 = min(minimum, 12);
    int minimum4 = min(min(10,30),40);
    printf("Minimum 1 : %d\n",minimum);
    printf("Minimum 2 : %f\n",minimum2);
    printf("Minimum 3 : %d\n",minimum3);
    printf("Minimum 4 : %d\n",minimum4);
    // Predefined macros __FILE__ and __LINE__ 
    // useful for error reporting and debugging
    fprintf (stderr, "Internal error: "
                 "negative string length "
                 "%d at %s, line %d.",
         -1, __FILE__, __LINE__);
    return 0;
}