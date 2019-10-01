// Reference : https://gcc.gnu.org/onlinedocs/gcc-4.3.0/gcc/Function-Attributes.html

#include <stdio.h>
#include <stdarg.h>
#define EXIT_SUCCESS 0;

// Alias attribute

void __f()
{
    printf("Inside __f \n");
}
// The alias attribute causes the declaration to be emitted as an alias for another symbol, which must be specified.
// Also aliases doesn't work on darwin.
#ifndef __APPLE__
void f() __attribute__((weak, alias("__f")));
#else
void f()
{
    __f();
}
#endif
// alloc_size

void *my_calloc(size_t, size_t) __attribute__((alloc_size(1, 2)));
void my_realloc(void *size_t) __attribute__((alloc_size(2)));

// always_inline

// Generally, functions are not inlined unless optimization is specified.For functions declared inline,
// this attribute inlines the function even if no optimization level was specified.

inline void inlineFunc() __attribute__((always_inline));

// deprecated

int old_fn() __attribute__((deprecated));
int old_fn() {}
//Gives deprecated warning
int (*fn_ptr)(void) = &old_fn;

// format

int my_printf(void *my_object, const char *my_format, ...)
    __attribute__((format(printf, 2, 3)));
int my_printf(void *my_object, const char *my_format, ...)
{
    // int count; // TODO: calculate number of arguments from format string
    // char typeString;

    // va_list intArgumentPointer;
    // va_start(intArgumentPointer, 2);
    // for (int i = 0; i < count; i++)
    // {
    //     switch (typeString)
    //     {
    //     case 'd':
    //         int temp = va_arg(intArgumentPointer, int);
    //         __asm("push %0" ::"=r"(temp));
    //         break;
    //     case 'f':
    //         float temp = va_arg(intArgumentPointer, float);
    //         __asm("push %0" ::"=r"(temp));
    //         break;
    //     case 's':
    //         char *temp = va_arg(intArgumentPointer, char *);
    //         __asm("push %0" ::"=r"(temp));
    //         break;
    //     default:
    //         printf("Unkown argument");
    //         break;
    //     }
    // }
    // va_end(intArgumentPointer);
    // __asm("push %0" ::"=r"(my_format));
    // __asm("call printf");
    printf("The format is correct \n");
}

// interrupt
// Tells the compiler that the function is a interrupt handler
#ifdef __ARM__
void f() __attribute__((interrupt("IRQ")));
#endif

//l1_text
// Puts the function to the l1 cache ( L1 Instruction SRAM.   into a specific section named .l1.text)
void cached_func() __attribute((l1_text));

int main()
{
    //Gives deprecated warning
    old_fn();
    f();
    my_printf(0, "%s:%d", "Number is", 15);
    // Gives compiler warning
    my_printf(0, "%s", 10, "asdasd");
    return EXIT_SUCCESS;
}