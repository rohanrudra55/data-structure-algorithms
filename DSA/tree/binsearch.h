#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node *left;
	struct node *right;
}node;

node *create_node(int data){
	node *new_node = (node*)malloc(sizeof(node));
	new_node->data = data;
	new_node->left = NULL:
	new_node->right = NULL;
}