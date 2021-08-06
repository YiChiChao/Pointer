#include<stdio.h>
int b = 3;
void func(int* a){
    a = &b;
    printf("(func)a = %d\n", *a);
}

int main(){
    int a = 1;
    printf("(main)init a = %d\n", a);
    func(&a);
    printf("(main)final a = %d\n", a);
    return 0;
}