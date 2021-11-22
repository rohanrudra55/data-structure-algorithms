#include<stdio.h>
#include<stdlib.h>
#define MAX 100

typedef struct node{
    int data;
    struct node *next;
}node;

struct queue{
    node *front;
    node *rear;
};

int queue[MAX];
int front=-1;
int rear=-1;
void push(int);
void display();
void peek();
void reset();
int pop();
node *create_node(int);
struct queue *create_queue();

node *create_node(int value){
    node *new_node;
    new_node->data=value;
    new_node->next=NULL;
    return new_node;
}
struct queue* create_queue(){
    struct queue *new_queue;
    new_queue->front=NULL;
    new_queue->rear=NULL;
    return new_queue;
}