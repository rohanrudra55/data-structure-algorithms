#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node *next;
}node;

node *create_node(int value){
	node *new_node=(node*)malloc(sizeof(node));
	new_node->data=value;
	new_node->next=NULL;
	return new_node;
}

int main(){
	int n=7,k=3;
	printf("Enter the number of persons and the element to eleminate: ");
	scanf("%d %d",&n,&k);
	node *list=create_node(1);
	node *ptr=list;

	for(int i=2;i<=n;i++){
		ptr->next=create_node(i);
		ptr=ptr->next;
	}
	ptr->next=list;

	ptr=list;
	for(int count=n;count>1;count--){
		for(int i=1;i<k-1;i++)
			ptr=ptr->next;
		
		printf("Removed: %d\n",ptr->next->data);
		ptr->next=ptr->next->next;
		ptr=ptr->next;
	}
	printf("Player ID: %d",ptr->data);
	return 0;
}