#include<stdio.h>

int search(int arr[],int l,int u,int n){
	int mid=(l+u)/2;

	if(l>u) return -1;

	if(mid>n) mid=search(arr,l,mid,n);

	else if(mid<n) mid=search(arr,mid+1,u,n);

	return mid;
}

int main(){
	int arr[10]={1,2,3,4,5,6,7,8,9,10};
	int num;
	printf("Enter the number to found: ");
	scanf("%d",&num);
	int ele=search(arr,0,9,num);
	if(ele!=-1) printf("Found at: %d",ele);
	return 0;
}