#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}node;

node *create_node( int );
node *create_circular_list();
void display_circualr_list( node *);
node *insert_beg( node *);
node *insert_end( node *);
node *delete_beg( node *);
node *delete_end( node *);
node *delete_after( node *);
node *delete_list( node *);

node *create_node(int value){
    node *new_node=(node*)malloc(sizeof(node));
    new_node->data=value;
    new_node->next=NULL;
    return new_node;
}

node *create_circular_list(){
    node *start=NULL, *previous=NULL, *new_node=NULL;
    int buff=-2;
    printf(" Enter the data: ");
    while(buff!=-1){
        if( buff == -2 ){
            scanf("%d",&buff);
            continue;
        }
        new_node=create_node(buff);
        if(start==NULL){
            start=new_node;
            previous=new_node;
        }
        else{
            previous->next=new_node;
            previous=new_node;
        }
        scanf("%d",&buff);
    }
    previous->next=start;
    return start;
}

void display_circualr_list(node *start){
    node *list=start;
    printf(" Sorted list: ");
    while (1){
        printf("%d ",list->data);
        if(list->next==start)
            break;
        list=list->next;
    } 
    char pause;
    scanf("%c",&pause);
}

node *insert_beg(node *start){
    int buff;
    printf(" Enter the data; ");
    scanf("%d",&buff);
    node *new_node=create_node(buff);
    node *copy_list=start;
    new_node->next=copy_list;
    while(1){
        if(copy_list->next == start){
            copy_list->next=new_node;
            start=new_node;
            break;
        }
        copy_list=copy_list->next;
    }
    return start;
}

node *insert_end(node *start){
    int buff;
    printf(" Enter the data: ");
    scanf("%d",&buff);
    node *new_node=create_node(buff);
    node *copy_list=start;
    new_node->next=start;
    while(1){
        if(copy_list->next==start){
            copy_list->next=new_node;
            break;
        }
        copy_list=copy_list->next;
    }
    return new_node->next;
}

node *delete_beg(node *start){
    node *copy_list=start;
    while(1){
        if(copy_list->next==start){
        copy_list->next=start->next;
        break;
        }
    copy_list=copy_list->next;
    }
    return copy_list->next;
}

node *delete_end(node *start){
    node *copy_list=start;
    while(1){
        if(copy_list->next->next==start){
            copy_list->next=start;
            break;
        }
        copy_list=copy_list->next;
    }
    return start;
}

node *delete_after(node *start){
    int pos;
    node *copy_list=start;
    printf(" Enter a node: ");
    scanf("%d",&pos);
    while(1){
        if(copy_list->data == pos){
            node *temp=copy_list->next->next;
            copy_list->next=temp;
            break;
        }
        copy_list=copy_list->next;
    }
    return start;
}
node *delete_list(node *start){
    start=NULL;
    return start;
}