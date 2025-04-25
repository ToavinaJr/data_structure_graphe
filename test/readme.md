# int foo() vs int foo(void)

# ATTENTION!

En utilisant le compilateur g++ le code suivant est seulemnt un warning :

```c
int foo() {return 15;}

int main() {
    int result = foo(12);

    printf("Result: %d\n", result);
}
```

Mais le code suivant génère une erreur :

```c
int foo(void) {return 15;}

int main() {
    int result = foo(12);

    printf("Result: %d\n", result);
}
```