#include<stdio.h>

void display(int arr[],int n){
    printf("Sorted Array: ");
    for(int i=0;i<n;i++)
        printf("%d\t",arr[i]);
    printf("\n");
}

int search(int arr[],int n){
    printf("Enter the element to search: ");
    int ele,nof=-1;
    scanf("%d",&ele);
    for(int i=0;i<n;i++){
        if(ele==arr[i])
            return i;
    }
    return nof;
}

int main(){
    int arr[]={1,2,3,4,5,6,7,8,9};
    int size=sizeof(arr)/sizeof(*arr);
    int pos=search(arr,size);
    if(pos>-1)
        printf("Found at: %dth position\n",(pos+1));
    return 0;
}