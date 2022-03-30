#include<stdio.h>
#define SIZE 7

void display(int arr[]){
	printf("Sorted Array: ");
	for(int i=0;i<SIZE;i++)
			printf("%d \t",arr[i] );
		printf("\n");
}

void swap(int *i,int *j){
	//  Swap the array elements and 
	int temp=*i;
	*i=*j;
	*j=temp;
}

int partition(int arr[],int beg,int end){
	// Using begining as the pivot as default 
	int flag=0,pivot=beg;
	int left=beg,right=end;
	while(flag!=1){
		// iteratng from the right
		while(arr[pivot]<=arr[right] && pivot!=right)
			right--;
		if(right==pivot)
			flag=1;
		else if(arr[pivot]>arr[right]){
			swap(&arr[pivot],&arr[right]);
			pivot=right;
		}

		if(flag!=1){
			// Iterating form the left 
			while(arr[pivot]>=arr[left] && pivot!=left)
				left++;
			if(left==pivot)
				flag=1;
			else if(arr[pivot]<arr[left]){
				swap(&arr[pivot],&arr[left]);
				pivot=left;
			}
		}

	}
	return pivot;
}

void quicksort(int arr[],int beg ,int end){
	if(beg<end){
		int pivot=partition(arr,beg,end);
		quicksort(arr,beg,pivot-1);
		quicksort(arr,pivot+1,end);
	}
}

int main(){
	int arr[]={7,6,5,4,3,2,1};
	quicksort(arr,0,SIZE-1);
	display(arr);
	return 0;
}