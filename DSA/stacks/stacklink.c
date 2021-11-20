#include<stdio.h>
#include<stdlib.h>

#define MAX 3 // Altering this value changes size of stack created

typedef struct node{
    int value;
    struct node *next;
}node;

int top=-1;
node *create_node(int);
node *push(node*);
node *pop(node*);
void peek(node*);
void display(node*);

int main(){
        int option;
        node *start=NULL;
        system("clear");
        do{
            // system("clear");
            printf("\n *****MAIN MENU*****");
            printf("\n 1. PUSH");
            printf("\n 2. POP");
            printf("\n 3. PEEK");
            printf("\n 4. DISPLAY");
            printf("\n 5. EXIT");
            printf("\n Enter your option: ");
            scanf("%d", &option);
            switch(option){
                case 1: start = push(start);
                        break;
                case 2: start=pop(start);
                        break;
                case 3: peek(start);
                        break;
                case 4: display(start);
                        break;
        }
    }while( option!=5 );
    return 0;
}

node *create_node(int val){
    node *new_node=(node*)malloc(sizeof(node));
    new_node->value=val;
    new_node->next=NULL;
    return new_node;
}

node *push(node *start){
    int val=0;
    printf(" Enter the value: ");
    scanf("%d",&val);
    if (start == NULL){
        start=create_node(val);
    }
    else{    
        node *new_node=create_node(val);
        new_node->next=start;
        start=new_node;
    }
    top++;
    return start;
}

node *pop(node *start){
    if(top == -1)
        printf("*** UNDERFLOW ! ***");
    else{
        node *new_start=start->next;
        printf(" [%d] POPED",start->value);
        start=new_start;
        top--;
    }
    return start;
}

void peek(node *start){
    if (top == -1)
        printf(" STACK IS EMPTY !");
    else
        printf(" [%d] at TOP",start->value);
}

void display(node *start){
    while(1){
        printf(" [%d]\n",start->value);

        if (start->next==NULL)
            break;
        else
            start=start->next;
    }
}