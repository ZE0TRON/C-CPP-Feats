#include <stdio.h>
#define eprintf(args...) fprintf (stderr, args)
#define jprintf(format,...) fprintf (stderr,format, __VA_ARGS__)
int main(){

FILE *fptr;
fptr = fopen("variadic.txt","w");
eprintf ("%s:%d:\n", fptr, 10);
eprintf("Success!\n");
jprintf ("%s:%d: ", fptr, 10);
fclose(fptr);
}
