#include<stdio.h>
int main(){
    int a;
    int *p = &a;
    scanf("%d", p);
    printf("%d\n", *p);
    return 0;   
}
