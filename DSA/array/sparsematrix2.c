#include<stdlib.h>
#include<stdio.h>

int sparsemat[4][4]={{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
void display_sparse_mat();
void create_upper_triangular();
void update(int,int);

int main(){
    create_upper_triangular();
}

void create_lower_triangular(){
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(j>=i){
               update(i,j);
            }
        }
    }
}

void display_sparse_mat(){
    printf("Matrix:\n");
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            printf("%d ",sparsemat[i][j]);
        }
        printf("\n");
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