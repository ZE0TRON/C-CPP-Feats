#include <stdio.h>
#define eprintf(args...) fprintf (stderr, args)

int main(){

FILE *fptr;
fptr = fopen("variadic.txt","w");
eprintf ("%s:%d: ", fptr, 10);
eprintf("Success!\n");
fclose(fptr);
}
