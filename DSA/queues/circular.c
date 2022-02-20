#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int queue[MAX];
int front=-1;
int rear=-1;

void display();
void push(int);
void reset();
int peek();
int pop();

int main(){
    int option;
    int value;
    system("clear");
    printf(" *** QUEUE Commands ***\n");
    printf(" 1. Push value\n");
    printf(" 2. Pop value\n");
    printf(" 3. Peek value\n");
    printf(" 4. Display value\n");
    printf(" 5. Reset queue\n");
    printf(" 6. EXIT\n");
    do{
        printf(" >>> ");
        scanf("%d",&option);
        switch(option){
            case 1:
                scanf("%d",&value);
                push(value);
                break;
            case 2:
                value=pop();
                if(value!=-1)
                    printf("Popped: [%d]\n",value);
                break;
            case 3:
                value=peek();
                if(value!=-1)
                    printf("Peeking: [%d]\n",value);
                break;
            case 4:
                display();
                break;
            case 5:
                reset();
                break;
        }
        // printf("Front-> %d Rear-> %d\n",front,rear);
    }while(option!=6);
    return 0;
}
void push(int value){
    if((front==0 && rear==MAX-1)||(front==rear+1))         // This will prevent from overwriting the box
        printf(" OVERFLOW !!!\n");
    else{
        if( front==-1 && rear==-1 )
            front=rear=0;
        else if( front!=0 && rear==MAX-1 )
            rear=0;
        else
            rear++;
        queue[rear]=value;
    }
}
int pop(){
    int value =-1;
    if(front==-1 && rear==-1)
        printf(" UNDERFLOW !!!\n");
    else{
        value=queue[front];
        if(front==rear)
            front=rear=-1;
        else if(front == MAX-1)
            front=0;
        else
            front++;
    }
    return value;
}
int peek(){
    int value=-1;
    if((front==-1 && rear==-1))
        printf(" EMPTY !!!\n");
    else{
        value=queue[front];
    }
    return value;
}
void display(){
    if((front==-1 && rear==-1))
        printf("EMPTY !!!\n");
    else{
        if(front>rear){
            for(int i=front;i<MAX;i++)
                printf("[%d] ",queue[i]);
            for(int i=rear;i<front;i++)
                printf("[%d] ",queue[rear]);
        }
        else{
        for(int i=front;i<=rear;i++)
            printf("[%d] ",queue[i]);
        }
        printf("\n");
    }
}
void reset(){
    rear=-1;
    front=-1;
}