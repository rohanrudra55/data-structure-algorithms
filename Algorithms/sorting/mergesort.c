#include<stdio.h>
#include<stdlib.h>
#define SIZE 4

void display(int arr[],int l,int r){
	for(int i=0;i<SIZE;i++)
		printf("%d\t",arr[i]);
	printf("\n");
}

void merge(int arr[],int l,int mid,int r){
	int n1=mid-l+1;
	int n2=r-mid;

	int temp1[mid-l+1];
	int temp2[r-mid];

	// Stroing the left hand array in a temp place
	for(int i=0;i<n1;i++) temp1[i]=arr[l+i];
	// String the right hand array in a temp palce
	for(int i=0;i<n2;i++) temp2[i]=arr[mid+i+1];

	int i=0,j=0,k=l;
	// Merging 
	while(i<n1 && j<n2){
		if(temp1[i]<temp2[j])
			arr[k++]=temp1[i++];
		else
			arr[k++]=temp2[j++];
	}
	// Inserting the leftout items
	while(i<n1) arr[k++]=temp1[i++];
	while(j<n2) arr[k++]=temp2[j++];
}

void sort(int arr[],int l,int r){
	if(l<r){	
		int mid=(r+l)/2;
		
		sort(arr,l,mid);
		sort(arr,mid+1,r);
		merge(arr,l,mid,r);
	}
}

int main(){
	int usr[SIZE]={5,3,3,1};
	sort(usr,0,SIZE-1);
	display(usr,0,SIZE-1);
	return 0;
}