#include <stdio.h>

int foo() { return 15;}

int main() {
    int result = foo(12);
    printf("Result: %d\n", result);
    
    return 0;
}