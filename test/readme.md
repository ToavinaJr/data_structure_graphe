# int foo() vs int foo(void)

# ATTENTION!

En utilisant le compilateur g++ le code suivant est seulemnt un warning :

```c
int main() {
    int result = foo(12);

    printf("Result: %d\n", result);
}
```
