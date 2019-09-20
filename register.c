#include <stdio.h>
#include <time.h>
#include <math.h> // ctime in C++
// Nearly no difference in -O2 flag with register keyword.
// 1/3 time with no optimization
// 1/2 time with -O1 flag
void func1(){
    clock_t start, end;
    int b;
    register int i;
    start = clock();
    for ( i = 0;i < pow(2,30); i++) {
        b = (i>>2 * b)>>2;
    }
    end = clock();
     printf("Time for func1 : %ld   b is %d\n",end - start,b);
}
void func2() { 
    clock_t start, end;
    register int b;
    start = clock();
    for (int i = 0;i < pow(2,30); i++) {
        b = (i>>2 * b)>>2;
    }
    end =  clock();
     printf("Time for func2 : %ld   b is %d\n",end - start,b);
}

void func3(){
    clock_t start, end;
    register int i;
    register int b;
    start = clock();
     for ( i = 0;i < pow(2,30); i++) {
        b = (i>>2 * b)>>2;
    }
    end = clock();
     printf("Time for func3 : %ld   b is %d\n",end - start,b);
}

void func4() {
    clock_t start, end;
    int i, b;
    start = clock();
    for ( i = 0;i < pow(2,30); i++) {
        b = (i>>2 * b)>>2;
    }
    end = clock();
     printf("Time for func4 : %ld   b is %d\n",end - start,b);
}
// Instant run time in -O2 flag compiler finds the value then replaces it. No looping
void func5(){
    clock_t start, end;
    int i, b;
    start = clock();
     for ( i = 0;i < pow(2,30); i++) {
        b = i;
    }
    
    end = clock();
    printf("Time for func5 : %ld   b is %d\n",end - start,b);
}

int main() {
    
    func1();
    func2();
    func3();
    func4();
    func5();
   
}