#include<stdlib.h>
#include<stdio.h>

typedef struct node{
    int number;
    int coordinates[2];
    struct node *row;
    struct node *column;
}node;

int sparsemat[4][4]={{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
void display_sparse_mat();
void create_upper_triangular();
void create_lower_triangular();
void create_tri_diagonal();
void reset();
void update(int,int);
node *create_node(int,int,int);

void display_sparse_mat(){
    reset();
    printf("Matrix:\n");
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            printf("%d ",sparsemat[i][j]);
        }
        printf("\n");
    }
}


void create_upper_triangular(){
    reset();
    node *start , *prv;
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            node *new_node=NULL;
            if(j<=i){
               update(i,j);
               new_node = create_node(sparsemat[i][j],i,j);
               if( start == NULL ){
                   start=new_node;
                   prv=new_node;
               }
               else if(j==0){
                   prv->row=new_node;
                   prv=new_node;
               }
               else{
                   prv->column=new_node;
                   prv=new_node;
               }

            }
        }
    }
}

void create_lower_triangular(){
    reset();
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(j>=i){
               update(i,j);
            }
        }
    }
}

void create_tri_diagonal(){
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if( j <= (i+1) && j >= (i-1) ){
               update(i,j);
            }
        }
    }
}

void update(int i,int j){
    system("clear");
    display_sparse_mat();
    printf("Enter %dth row's %dst element: ",(i+1),(j+1));
    scanf("%d",&sparsemat[i][j]);
}

void reset(){
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            sparsemat[i][j]=0;
        }
    }
}

node *create_node(int value,int x, int y){
    node *new_node=(node*)malloc(sizeof(node));
    new_node->number=value;
    new_node->coordinates[0]=x;
    new_node->coordinates[1]=y;
    new_node->column=NULL;
    new_node->row=NULL;
    return new_node;
}