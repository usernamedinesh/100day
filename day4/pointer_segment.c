#include <stdio.h>
#include <stdlib.h>

int global_var = 10;        // .data
static int static_var = 10; // .bss

void hello() {              //.txt
    printf("Hi\n");
}


int main() {
    int local = 4; //stack
    int *heap_ptr = malloc(sizeof(int)); //heap
    *heap_ptr = 100;

    int *p1 = &global_var; //points to .data
    int *p2 = &static_var; //points to .bss
    int *p3 = &local;      // poinst to static
    void (*func_ptr)() = &hello; //point to .txt

    printf("global_var addr: %p\n", (void*)p1);
    printf("static_var addr: %p\n", (void*)p2);
    printf("local addr:      %p\n", (void*)p3);
    printf("heap_ptr addr:   %p\n", (void*)heap_ptr);
    printf("func_ptr addr:   %p\n", (void*)func_ptr);

    free(heap_ptr);

}
