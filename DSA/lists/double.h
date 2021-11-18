#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    struct node *prv;
    int data;
    struct node *next;
}node;

int create_circular = 0;
node *create_node(int);
node *create_ll();
void display(node *);
node *insert_beg(node *);
node *insert_end(node *);
node *insert_before(node *);
node *insert_after(node *);
node *delete_beg(node *);
node *delete_end(node *);
node *delete_before(node *);
node *delete_after(node *);
node *delete_list(node *);

node *create_node(int value){
    node *new_node=(node*)malloc(sizeof(node));
    new_node->data=value;
    new_node->next=NULL;
    new_node->prv=NULL;
    return new_node;
}

node *create_ll(){
    node *start=NULL, *previous=NULL, *new_node=NULL;
    int buff=-2;
    printf(" Enter the data: ");
    scanf("%d",&buff);
    while(buff!=-1){
        new_node=create_node(buff);
        if(start==NULL){
            start=new_node;
            previous=new_node;
        }
        else{
            new_node->prv=previous;
            previous->next=new_node;
            previous=new_node;
        }
        scanf("%d",&buff);
    }
    if( create_circular ){
        start->prv=previous;
        previous->next=start;
    }
    return start;
}

void display(node *start){
    while(1){
        printf("%d ",start->data);
        if(start->next==NULL)
            break;
        start=start->next;
    }
}

node *insert_beg(node *start){
    int buff=-2;
    printf(" Enter the data: ");
    scanf("%d",&buff);
    node *new_node=create_node(buff);
    start->prv=new_node;
    new_node->next=start;
    return new_node;
}

node *insert_end(node *start){
    int buff=-2;
    printf(" Enter the data: ");
    scanf("%d",&buff);
    node *new_node=create_node(buff);
    node *temp=start;
    while(1){
        if(temp->next==NULL){
            temp->next=new_node;
            new_node->prv=temp;
            break;
        }
        temp=temp->next;
    }
    return start;
}

node *insert_before(node* start){
    int buff=-2,val;
    printf(" Enter the data: ");
    scanf("%d",&buff);
    node *new_node=create_node(buff);
    node *temp=start;
    printf(" Enter a node: ");
    scanf("%d",&val);
    while(1){
        if(temp->data==val){
            new_node->prv=temp->prv;
            temp->prv=new_node;
            new_node->next=temp;
            break;
        }
        temp=temp->next;
    }
    return start;
}
node *insert_after(node *start){
    int buff=-2,val;
    printf(" Enter the data: ");
    scanf("%d",&buff);
    node *new_node=create_node(buff);
    node *temp=start;
    printf(" Enter a node: ");
    scanf("%d",&val);
    while(1){
        if(temp->data==val){
            new_node->next=temp->next;
            new_node->prv=temp;
            temp->next=new_node;
            break;
        }
        temp=temp->next;
    }
    return start;
}

node *delete_beg(node *start){
    start->next->prv=NULL;
    return start->next;
}

node *delete_end(node *start){
    node *temp=start;
    while(1){
        // printf("q");
        if(temp->next->next==NULL){
            temp->next=NULL;
            break;
        }
        temp=temp->next;
    }
    return start;
}
node *delete_before(node *start){
    node *temp=start;
    int val=0;
    printf("Enter node: ");
    scanf("%d",&val);
    while(1){
        if(temp->data==val){
            temp->prv->prv->next=temp;
            temp->prv=temp->prv->prv;
            break;
        }
        temp=temp->next;
    }
    return start;  
}
node *delete_after(node *start){
    node *temp=start;
    int val=0;
    printf("Enter node: ");
    scanf("%d",&val);
    while(1){
        if(temp->data==val){
            temp->next->next->prv=temp;
            temp->next=temp->next->next;
            break;
        }
        temp=temp->next;
    }
    return start;    
}
node *delete_list(node *start){
    start=NULL;
    return start;
}