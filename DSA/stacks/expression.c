#include <stdio.h>
#include <stdlib.h>
#include <string.h>
# define MAX 10

int top=-1;
char stack[MAX];
char pop();
void push(char value);

int main(){
    char exp[10];
    printf("Enter an expression: ");
    gets(exp);
    int flag=0;
    for(int i=0;i<strlen(exp);i++){
        if(exp[i]=='(' || exp[i]=='[' || exp[i]=='{')
            push(exp[i]);
        if(exp[i]==')' || exp[i]==']' || exp[i]=='}'){
            flag=1;
            if(top==-1)
                flag = 0;
            
            else{
                char temp=pop();
                if(exp[i]==')' && (temp=='{' || temp=='['))
                    flag=0;
                if(exp[i]==']' && (temp=='{' || temp=='('))
                    flag=0;
                if(exp[i]=='}' && (temp=='[' || temp=='('))
                    flag=0;
            }
        }
    }
    if(flag)
        printf("VALID EXPRESSION\n");
    else
        printf("INVALID EXPRESSION\n");
    return 0;
}

void push(char value){
    if(top == MAX-1)
        printf("*** OVERFLOW ! ***");
    else{
        top++;
        stack[top]=value;
    }
}

char pop(){
    if (top == -1)
        printf("*** UNDERFLOW ! ***");
    else{
        char val=stack[top];
        top--;
        return val;
    }
}