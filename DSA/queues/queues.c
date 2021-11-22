#include<stdio.h>
#include<stdlib.h>
#define MAX 100

int queue[MAX];
int front=-1;
int rear=-1;
void push(int);
void display();
void peek();
void reset();
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
                    printf("Poped [%d]\n",value);
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                reset();
                break;
        }
    }while(option!=6);
    return 0;
}
void push(int value){
    if(rear == MAX-1)
        printf("OVERFLOW !!!\n");
    else if(rear == -1 && front == -1)
        front=rear=0;
    else
        rear++;
    queue[rear]=value;
}
int pop(){
    int value;
    if(front>rear || front == -1){
        printf("UNDERFLOW !!!\n");
        value=-1;
    }
    else{
        value=queue[front];
        front++;
        if(front>rear)
            reset;
    }
    return value;
}
void peek(){
    if(front==-1 || front>rear)
        printf(" Empty queue :( \n");
    else
        printf(" Number: %d",queue[front]);
}
void reset(){
    front=-1;
    rear=-1;
}
void display(){
    int i=0;
    for(i=front;i<=rear;i++)
        printf("[%d] ",queue[i]);
}