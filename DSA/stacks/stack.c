#include<stdio.h>
#include<stdlib.h>

#define MAX 3 // Altering this value changes size of stack created

int top=-1;
void push(int st[], int val);
void display(int st[]);
int pop(int st[]);
int peek(int st[]);

int main(){
        int stack[MAX];
        int val, option;
        do{
            system("clear");
            printf("\n *****MAIN MENU*****");
            printf("\n 1. PUSH");
            printf("\n 2. POP");
            printf("\n 3. PEEK");
            printf("\n 4. DISPLAY");
            printf("\n 5. EXIT");
            printf("\n Enter your option: ");
            scanf("%d", &option);
            switch(option){
                case 1: printf(" Enter thr value: ");
                        scanf("%d",&val);
                        push(stack,val);
                        break;
                case 2: val=pop(stack);
                        printf(" Value: [%d]",val);
                        break;
                case 3: val=peek(stack);
                        printf(" Value: [%d]",val);
                        break;
                case 4: display(stack);
                        break;
        }
    }while( option!=5 );
    return 0;
}

void push(int st[],int val){
    if (top == (MAX-1))
        printf("*** OVERFLOW ! ***");
    else{
        top++;
        st[top]=val;
    }
}

int pop(int st[]){
    if (top == -1)
        printf("*** UNDERFLOW ! ***");
    else{
        int val=st[top];
        top--;
        return val;
    }
}

int peek(int st[]){
    if (top == -1)
        printf("Stack is empty");
    else{
        return st[top];
    }
}

void display(int st[]){
    if (top == -1)
        printf("Stack is empty");
    else{
        for(int i=top;i>=0;i--){
            printf("[%d]\n",st[i]);
        }
    }
    char buff;
    scanf("%c",&buff);
    scanf("%c",&buff);
}