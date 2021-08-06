#include <stdio.h>
int main(){
    int a = 1;
    int *ptr = &a;
    int **ptrptra = &ptr;
    printf("%p %p %d\n", ptrptra, ptr, a);
    printf("%p, %p, %p\n", &ptrptra, &ptr, &a);
    return 0;
}
/* variable    value       pointer   
      a          1         0061FEC8
     ptr      0061FEC8     0061FEC4
   ptrptra    0061FEC4     0061FEC0
*/ 