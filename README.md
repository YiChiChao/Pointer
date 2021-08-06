# Pointer Note

## 什麼是指標？
在宣告一個變數並給予一個值的時候，記憶體會有一個空間給這個變數。而指標就像是這個記憶體位置的門牌號碼。

```c=
#include<stdio.h>
int main(){
    int a;
    int *p = &a;
    scanf("%d", p);
    printf("%d\n", *p);
    return 0;   
}
```
在宣告時， 「 * 」代表的是宣告一個指標變數，例如： int* 就是一個指標變數指向int。
然而在程式執行過程中，「 * 」代表的是將一個指標變數打開取值。

>煥宗的比喻我超喜歡：
>&a 是表示a的地址，當scanf要存進一個值的時候就要告訴程式變數的地址
>而$*$p就是當要用鑰匙打開一個給定的地址才能夠取到值，所以「$*$」就有點像一把鑰匙

## 指標變數
上面提到如果需要建立指標變數，就要在宣告時加$*$。而當我們在funtion中需要呼叫一個指標變數的指標，就需要為指標變數再設一個指標(繞口的鬼東西)

簡言之，雙重指標的值就會是一個指標，而最終指向的還是最一開始的int的值(假設它是一個int$*$)

```c=
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
```

## Call by Value
在主程式將某個變數裡面的值傳入副程式的時候，副程式會再建立一個新的變數去存取這個值。也就是說，當我們在副程式中變更這個值，主程式的的變數裡的值是不會被更改的。
```c=
#include<stdio.h>
int b = 3;
void func(int* a){
    a = &b;
    printf("(func)a = %d\n", *a);
}

int main(){
    int a = 1;
    printf("(main)init a = %d\n", a)
    func(&a);
    printf("(main)final a = %d\n", a);
    return 0;
}
/*
 * (main)init a = 1
 * (func)a = 3
 * (main)final a = 1
 * /
```
這個程式有兩個改法：
一個是不要自作聰明，直接在副程式更改a的值就好。

一個是用雙重指標再把指標&a打包起來，這樣存取指標的位置雖然會更改，但是這並不會影響到&a存取的位置，
>位置會在主程式宣告的指標變數ptrptr裡面

如此一來，執行的時候就能夠更改到主程式當中的值。
```c=
#include<stdio.h>
//call by value
int b = 3;

void change_val(int** ptrptr){
    printf("(func1)ptr_val = %p, ptr = %p, ptr stored in = %p\n", *ptrptr, ptrptr, &ptrptr);
    *ptrptr = &b;
    printf("(func2)ptr_val = %p, ptr = %p, ptr stored in = %p\n", *ptrptr, ptrptr, &ptrptr);
}

int main(){
    int a = 1;
    int *ptr = &a;
    int ** ptrptr = &ptr;
    
    change_val(ptrptr);
    printf("(main2)ptr_val = %p, ptr = %p, ptr stored in = %p\n", *ptrptr, ptrptr, &ptrptr);
}

/*
function     *ptrptr        ptrptr value   ptrptr stored place    after function *ptrptr       
  main      0061FECC(&a)      0061FEC8           0061FEC4              00403008(&b)
change_val  0061FECC(&a)      0061FEC8           0061FEB0              00403008(&b)  
*/  
```
