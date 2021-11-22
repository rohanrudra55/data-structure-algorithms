#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX 100

// Number stack
int top=-1;
float pop();
void push(float);
float stack[MAX];
// Character stack
int ctop=-1;
char popc();
void pushc(char);
float cstack[MAX];

char  postform[MAX];
void convert(char []);
float evaluate(char []);

float evaluate(char exp[]){
    float result=0.0;
    int i=0;
    while(exp[i]!='\0'){
        if(isdigit(exp[i])){
            push((float)(exp[i]-'0'));
        }
        else{
            char symb=exp[i];
            float a=pop(); // the last element in stack
            float b=pop(); // the second last elemnt in stack
            float r=0.0;
            switch (symb){
                case '+':
                    r = b+a;
                    break;
                case '-':
                    r = b-a;
                    break;
                case '/':
                    r = b/a;
                    break;
                case '*':
                    r = b*a;
                    break;
            }
            push(r);
        }
        i++;
    }
    result=pop();
    return result;
}
/*
Push the elements (braces,signs) to the stack and digits or alphabates 
to the output array until a closing brace is encountered. Then iterate 
backwards the stack till opening braces is encountered
*/
void convert(char exp[]){
    int i=0;
    int j=0;
    int error=0;
    while(exp[i]!='\0'){
        if(exp[i] == '(')
            pushc(exp[i]);
        else if(exp[i]=='+' || exp[i]=='-' || exp[i]=='*' || exp[i]=='/')
            pushc(exp[i]);
        else if(isdigit(exp[i]) || isalpha(exp[i])){
            postform[j]=exp[i];
            j++;
        }
        else if(exp[i]==')'){
            if(ctop==-1){
                printf("Invalid expression");
                error=1;
                break;
            }
            else{
                while(cstack[ctop]!='(' && ctop != -1){
                    postform[j]=popc();
                    j++;
                }
            }
            char temp = popc(); // Remove the opening brackets
        }
        else{
            printf("Incorrect elemnt");
            error=1;
            break;
        }
        i++;
    }
    if(!error)
        printf(" Postfix: %s\n",postform);
}

// Number stack
void push(float value){
    if(top==MAX-1)
        printf("Overflow");
    else{
        top++;
        stack[top]=value;
    }
}
float pop(){
    float value=0.0;
    if(top==-1){
        printf("\nUnderflow");
    }
    else{
        value=stack[top];
        top--;
    }
    return value;
}

// Character Stack 
void pushc(char value){
    if(ctop==MAX-1)
        printf("\nOverflow");
    else{
        ctop++;
        cstack[ctop]=value;
    }
}
char popc(){
    char value='\0';
    if(ctop==-1){
        printf("\nUnderflow");
    }
    else{
        value=cstack[ctop];
        ctop--;
    }
    return value;
}
