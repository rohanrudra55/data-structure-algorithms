#include <stdio.h>
#include <stdlib.h>
/*
There are three types of recursive calls:
    1) Direct 
    2) Indirect
    3) Tail
*/
// Comment below line to switch mode --->
#define TAIL 1

int fact0(int);
int fact1(int);
int fact2(int,int);

int main(){
    int input;
    printf(" Factorial Calculator\n >>> ");
    scanf("%d",&input);
    #ifndef TAIL
    printf(" Result: %d\n",fact0(input));
    #else
    printf(" Result: %d\n",fact1(input));
    #endif
    return 0;
}

int fact0(int number){                      // Non - tail recursive function
    if(number == 0)                         // Base case
        return 1;
    return (number*fact(number-1));         // Recursive case
}

int fact1(int number){                      // Tail recursive function
    return fact2(number,1);
}
int fact2(int number,int res){
    if(number==1)
        return 1;
    return fact2(number-1,res*number);
}