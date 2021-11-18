#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int num;
    int coeff;
    struct node *next;
    }node;

node *create_poly( node *);
void display_poly( node *);
node *add_poly( node *,  node *);
node *sub_poly( node *,  node *);

node *create_node(int number,int coefficient){
    node *new_node=(node*)malloc(sizeof(node));
    new_node->num=number;
    new_node->coeff=coefficient;
    new_node->next=NULL;
    return new_node;
}

node *create_poly(node *start){
    start=NULL;
    node *prv;
    int num=0,coeff=0;
    char sign,power,enter;
    while(1){
        printf("Enter the number and coefficient: ");
        scanf("%d%c%d",&num,&power,&coeff);

        
        node *new_node=create_node(num,coeff);
        if(start==NULL){
            start=new_node;
            prv=new_node;
        }
        prv->next=new_node;
        prv=new_node;
        scanf("%c",&sign);
        if(sign == '!')
            break;
    }
    return start;
}

void display_poly(node *start){
    node *temp=start;
    printf("Equation: ");
    while(1){

        if(temp->num==0)
            printf(" +%d",temp->num);
        else if(temp->num<0 || temp->num==start->num)
            printf(" %dx^%d",temp->num,temp->coeff);

        else
            printf(" +%dx^%d",temp->num,temp->coeff);

        if(temp->next==NULL)
            break;
        else
            temp=temp->next;
    }
}

node *add_poly(node *start1, node *start2){
    node *result=NULL,*prv=NULL;
    while(1){
        int add=start1->num+start2->num;
        node *new_node=create_node(add,start1->coeff);

        if(result==NULL){
            result=new_node;
            prv=new_node;
        }
        else{
            prv->next=new_node;
            prv=new_node;
        }

        if(start1->next==NULL && start2->next == NULL){
            break;
        }

        start1=start1->next;
        start2=start2->next;
    }

    return result;
}

node *sub_poly(node *start1,node *start2){
    node *result=NULL,*prv=NULL;
    while(1){
        int sub=start1->num-start2->num;
        node *new_node=create_node(sub,start1->coeff);

        if(result==NULL){
            result=new_node;
            prv=new_node;
        }
        else{
            prv->next=new_node;
            prv=new_node;
        }

        if(start1->next==NULL && start2->next == NULL){
            break;
        }

        start1=start1->next;
        start2=start2->next;
    }

    return result;
}

