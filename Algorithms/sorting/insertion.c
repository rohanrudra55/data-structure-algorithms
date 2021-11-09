#include<stdio.h>
#include<stdlib.h>

void display(int *list,int index){
    printf("Sorted List: ");
    for(int i=0;i<index;i++)
        printf("%d ",list[i]);
    printf("\n");
}
int insertionsort(int *list,int index){
    // int flag=1;
    for(int i=0;i<index;i++){
        int lastsort=list[i];               // Last element of the sorted array
        int pos=i;                          // Position of the last element
        int element=lastsort;
        for(int j=i;j<index;j++){
            if(list[j]<lastsort){           // Check if any element in the unsorted array is smaller than the last elemnt
                element=list[j];
                pos=j;
                break;
            }
        }
        for(int j=pos;j>=0;j--){            // Insert the matched element in sorted array
            if(element>list[j]){            // If the element is bigger than any elemnt it is places in its right
                list[j+1]=element;
                break;
            }
            else if(j==0)                   // When the first elemrnt of the array is updated
                list[j]=element;

            else
                list[j]=list[j-1];          // Push elemnts one step in right 
        }
    }
    return 1;
}
int main(){
    printf("Enter a list of inetrgers: ");
    int list[10];
    for(int i=0;i<10;i++)
        scanf("%d",&list[i]);
    if( insertionsort(list,10) )
        display(list,10);
    else
        printf("Error occured ! or already sorted");
    return 0;
}