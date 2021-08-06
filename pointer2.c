#include<stdio.h>
//call by value
int b = 3;
void change_val(int** ptr){
    printf("(func1)ptr_val = %p, ptr = %p, ptr stored in = %p\n", *ptr, ptr, &ptr);
    *ptr = &b;
    printf("(func2)ptr_val = %p, ptr = %p, ptr stored in = %p\n", *ptr, ptr, &ptr);
}
int main(){
    int a = 1;
    int *ptr = &a;
    int ** ptrptr = &ptr;
    printf("(main1)ptr_val = %p, ptr = %p, ptr stored in = %p\n", *ptrptr, ptrptr, &ptrptr);
    change_val(ptrptr);
    printf("(main2)ptr_val = %p, ptr = %p, ptr stored in = %p\n", *ptrptr, ptrptr, &ptrptr);
}

/*
function     *ptrptr        ptrptr value   ptrptr stored place    after function *ptrptr       
  main      0061FECC(&a)      0061FEC8           0061FEC4              00403008(&b)
change_val  0061FECC(&a)      0061FEC8           0061FEB0              00403008(&b)  
*/  