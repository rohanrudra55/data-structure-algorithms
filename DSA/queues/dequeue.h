#include<stdio.h>
#include<stdlib.h>
#define MAX 10

int queue[MAX];
int front=-1;
int rear=-1;

void push_front(int);
void push_rear(int);
int pop_front();
int pop_rear();
void reset();
int peek();
void display();

void push_rear(int value){
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
void push_front(int value){
    if((front==0 && rear==MAX-1)||(front==rear+1))         // This will prevent from overwriting the box
        printf(" OVERFLOW !!!\n");
    else{
        if( front==-1 && rear==-1 )
            front=rear=0;
        else if(front==0)
            front=MAX-1;
        else
            front--;
        queue[front]=value;
    }
}
int pop_front(){
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
int pop_rear(){
    int value =-1;
    if(front==-1 && rear==-1)
        printf(" UNDERFLOW !!!\n");
    else{
        value=queue[rear];
        if(front==rear)
            front=rear=-1;
        else if(rear == 0)              // Here we have to change
            front=MAX-1;
        else
            rear--;                     // Here we have to change
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
        if(front<=rear){
            for(int i=front;i<=rear;i++)
            printf("[%d] ",queue[i]);
        }
        else{
            for(int i=front;i<MAX;i++)
                printf("[%d] ",queue[i]);
            for(int i=0;i<rear;i++)
                printf("[%d] ",queue[i]);
        }
        printf("\n");
    }
}
void reset(){
    rear=-1;
    front=-1;
}