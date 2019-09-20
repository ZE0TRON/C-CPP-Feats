#include "inline.h"
#include <stdio.h>
// Without extern it gives and error undefined reference
extern int max(int a, int b);
// Another approach is the use the static inline function
int main(){
    int b = max(1,4);
    printf("Max is %d \n",b);
    int a = min(1,4);
    printf("Min is %d\n",a);
    return 0;
}