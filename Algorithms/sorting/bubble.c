#include<stdio.h>
#include<stdlib.h>

void display(int *list,int indx){
    printf("List: ");
    for(int i=0;i<indx;i++)
        printf("%d ",list[i]);
}

int bubblesort(int *list,int index){
    int flag=1;
    for(int i=0;i<index-1;i++){
        for(int j=0;j<index-i-1;j++){
            if(list[j]>list[j+1]){
                flag=0;
                int temp=list[j];
                list[j]=list[j+1];
                list[j+1]=temp;
            }
        }
        if(flag)
            return 0;
    }
    return 1;
}
int main(){
    printf("Enter a list of inetrgers: ");
    int list[10];
    for(int i=0;i<10;i++)
        scanf("%d",&list[i]);
    if( bubblesort(list,10) )
        display(list,10);
    else
        printf("Error occured ! or already sorted");
    return 0;
}