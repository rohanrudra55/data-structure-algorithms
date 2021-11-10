#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;                   // Store the data
    struct node *next;          // Store the next node address
}node;

// Operations can be performed 
void display(node *);
node *create_node(int);
node *create_list();
node *insert_beg(node *);
node *insert_end(node *);
node *insert_before(node *);
node *insert_after(node *);
node *delete_beg(node *);
node *delete_end(node *);
node *delete_before(node *);
node *delete_after(node *);
node *delete_list(node *);

void display(node *list){
    printf("Stored List: ");
    if(list==NULL)
        printf("List is empty");
    else{
        while (1){
            printf("%d ",list->data);
            if(list->next==NULL)
                break;
            list=list->next;
        } 
        printf("\n");
    }
}

node *create_node(int new_data){
    node *new_node = (node*)malloc(sizeof(node));
    new_node->data = new_data;
    new_node->next = NULL;
    return new_node;
}

node *create_list(){
    node *start=NULL;
    node *previous_node;
    node *new_node;
    int count=0;
    int buff=-2;
    printf(" Enter: ");
    while(buff != -1){
        if(buff==-2){
            scanf("%d",&buff);
            continue;
        }
        
        new_node=create_node(buff);
        if(start==NULL){
            start=new_node;
            previous_node=new_node;
        }
        else{
            previous_node->next=new_node;
            previous_node=new_node;
        }
        count++;
        scanf("%d",&buff);
    }
    return start;
}
node *insert_beg(node *start){       
        int  buff;
        printf(" Enter the element: ");
        scanf("%d",&buff);
        node *new_node=create_node(buff);
        new_node->next=start; 
        return new_node;
} 

node *insert_end(node *start){
    int buff;
    node *copy_list=start;
    printf(" Enter the element: ");
    scanf("%d",&buff);
    node *new_node=create_node(buff);
    while(1){
        if(copy_list->next==NULL){
            copy_list->next=new_node;
            return start;
        }
        copy_list=copy_list->next;
    }
}
node *insert_before(node *start){
    int buff,pos;
    node *copy_list=start,*previous_node;
    printf(" Enter the value before which the element will be inserted: ");
    scanf("%d",&pos);
    printf(" Enter the element to insert: ");
    scanf("%d",&buff);
    node *new_node=create_node(buff);
    while(1){
        if(copy_list->data==pos){
            previous_node->next=new_node;
            new_node->next=copy_list;
            return start;
        }
        if(copy_list->next==NULL)
            printf("Enter correct position !");
        previous_node=copy_list;
        copy_list=copy_list->next;
    }
}
node *insert_after(node *start){
    int buff,pos;
    node *copy_list=start;
    printf(" Enter the value after which the element will be inserted: ");
    scanf("%d",&pos);
    printf(" Enter the element to insert: ");
    scanf("%d",&buff);
    node *new_node=create_node(buff);
    while(1){
        if(copy_list->data==pos){
            new_node->next=copy_list->next;
            copy_list->next=new_node;
            return start;
        }
        if(copy_list->next==NULL)
            printf("Enter correct position !");
        copy_list=copy_list->next;
    }
}
node *delete_beg(node *start){
    return start->next;
}
node *delete_end(node *start){
    node *copy_list,*previos_node;
    copy_list=start;
    while(1){
        if((copy_list->next)->next==NULL){
            // previos_node->next=NULL;
            copy_list->next=NULL;
            return start;
        }
        // previos_node=copy_list;
        copy_list=copy_list->next;
    }
}
node *delete_before(node *start){
    int pos;
    node *copy_list=start,*previous_node;
    printf(" Enter the value before which the element will be deleted: ");
    scanf("%d",&pos);
    while(1){
        if(copy_list->data==pos){
            previous_node->next=copy_list->next;
            return start;
        }
        if(copy_list->next==NULL)
            printf("Enter correct position !");
        previous_node=copy_list;
        copy_list=copy_list->next;
    }
}
node *delete_after(node *start){
    int pos;
    node *copy_list=start;
    printf(" Enter the value after which the element will be deleted: ");
    scanf("%d",&pos);
    while(1){
        if(copy_list->data==pos){
            node *new_node=copy_list->next->next;
            copy_list->next=new_node;
            return start;
        }
        if(copy_list->next==NULL)
            printf("Enter correct position !");
        copy_list=copy_list->next;
    }
}
node *delete_list(node *start){
    start=NULL;
    return start;
}