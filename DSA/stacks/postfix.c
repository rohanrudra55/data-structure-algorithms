#include "postfix.h"

// This is at basic level
// Sign precedences needed to be updated
// Update error handeling 

int main(){
    float val=0.0;
    char exp[100];
    int option=0;
    system("clear");
    printf("\n 1. Convert Infix to Postfix");
    printf("\n 2. Evalute Postfix");
    printf("\n >>> ");
    scanf("%d",&option);
    char pause;
    scanf("%c",&pause);
    switch(option){
        case 1:
                printf(" Enter any Infix expression: ");
                scanf("%s",exp);
                convert(exp);
                break;
        case 2: 
                printf(" Enter any postfix expression: ");
                scanf("%s",exp);
                val = evaluate(exp);
                printf(" Value of the postfix expression = %.2f", val);
                break;
    }
    return 0;
}