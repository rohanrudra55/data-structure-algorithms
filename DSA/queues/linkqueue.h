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

// Queue operations
struct queue* push(struct queue*,int);
struct queue* delete_ele(struct queue*);
void display(struct queue*);
void reset(struct queue*);
int peek(struct queue*);
// Linking operations
node *create_node(int);
void create_queue(struct queue*);

node *create_node(int value){
    node *new_node=(node*)malloc(sizeof(node));
    new_node->data=value;
    new_node->next=NULL;
    return new_node;
}
void create_queue(struct queue *q){
    // q=(struct queue*)malloc(sizeof(struct queue));
    q->front=NULL;
    q->rear=NULL;
}
struct queue* push(struct queue *q,int value){
    node *ptr=create_node(value);
    if(q->front==NULL){
        q->front=ptr;
        q->rear=ptr;
    }
    else{
        q->rear->next=ptr;
        q->rear=ptr;
    }
    return q;
}
struct queue* delete_ele(struct queue* q){
    if(q->front==NULL){
        printf(" UNDERFLOW !!! \n");
    }
    else{
        node *temp=q->front->next;
        printf(" Deleted: %d\n",q->front->data);
        q->front=temp;
    }
    return q;
}
int peek(struct queue* q){
    if(q->front==NULL){
        printf(" Empty queue\n");
        return -1;
    }
    return q->front->data;
}
void display(struct queue* q){
    if(q->front==NULL){
        printf(" Empty !!!");
    }
    else{
        node *ptr=q->front;
        while(1){
            printf("[%d] ",ptr->data);
            if(ptr->next==NULL)
                break;
            ptr=ptr->next;
        }
    }
    printf("\n");
}
void reset(struct queue *q){
    create_queue(q);
}