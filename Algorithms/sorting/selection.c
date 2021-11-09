#include<stdio.h>
#include<stdlib.h>

void display(int *list,int indx){
    printf("List: ");
    for(int i=0;i<indx;i++)
        printf("%d ",list[i]);
}
int selectionsort(int *list, int index){
    for(int i=0; i<index; i++){
        int smallest=list[i];
        int pos=i;
        int temp=smallest;
        for(int j=i;j<index;j++){           // Find the smallest element in the unsorted list
            if(smallest>list[j]){
                smallest=list[j];
                pos=j;
            }
        }
        list[i]=smallest;                   // Swap the item with the smallest item
        list[pos]=temp;
    }
    return 1;
}
int main(){
    printf("Enter a list of inetrgers: ");
    int list[10];
    for(int i=0;i<10;i++)
        scanf("%d",&list[i]);
    if( selectionsort(list,10) )
        display(list,10);
    else
        printf("Error occured ! or already sorted");
    return 0;
}