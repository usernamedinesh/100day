#include <stdio.h>

void Dispaly(int age);
int add(int,int);
int sub(int,int);


int main() {
    int age = 22;
    int sum, diff;
    // if i use here it will skip the Dispaly() func
    // goto funGoto;
    Dispaly(age);

    int (* arithm) (int, int); //function pointer declartion point to all func whose return tyep is int
    arithm = add; //func poiinter point to add()
    sum = arithm(20, 10);

    arithm = &sub; //works same
    diff = arithm(50, 25);

    printf("20+10 = %d\n", sum);
    printf("50-25 = %d\n", diff);

funGoto:
    printf("from goto statement\n");
    return 0;
}


void Dispaly(int age ) {
    printf("may age is : %d \n", age);
    printf("from dispaly\n");
}

int add(int n1, int n2) {
    return n1+n2;
}

int sub(int n1, int n2) {
    return n1-n2;
}
