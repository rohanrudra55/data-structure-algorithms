#include <stdio.h>
// Size of integers that is 0 to 10
#define SIZE 10

// To find the largest element 
int largest(int arr[],int size){
	int large=arr[0];
	for(int i=0;i<size;i++){
		if(arr[i]>large)
			large=arr[i];
	}
	return large;
}

void display(int arr[],int n){
	printf("Sorted Array:\t");
	for(int i=0;i<n;i++)
		printf("%d\t",arr[i]);
	printf("\n");
}

void radixsort(int arr[],int n){
	int large=largest(arr,n);
	int NOP=0,divisor=1;
	int bucket[SIZE][SIZE];
	int bucket_depth[SIZE];
	
	// Count the number of digits
	for(int i=large;i>0;i/=SIZE) 
		NOP++;
	
	for(int pass=0;pass<NOP;pass++){
		int k=0;
		for(k=0;k<SIZE;k++) 
			bucket_depth[k]=0;

		for(int j=0;j<n;j++){
			int reminder = (arr[j]/divisor)%SIZE;
			bucket[reminder][bucket_depth[reminder]] = arr[j];
			bucket_depth[reminder] += 1;		
		}

		divisor *= SIZE;
		k = 0;
		// Keeping the sorted array in main array
		for(int j=0;j<SIZE;j++){
			for(int i=0;i<bucket_depth[j];i++){
				arr[k]=bucket[j][i];
				k++;
			}
		}
	}
}

int main(){
	int arr[]={345, 654, 924, 123, 567, 472, 555, 808, 911};
	int size=(int)sizeof(arr)/sizeof(*arr);
	radixsort(arr,size);
	display(arr,size);
	return 0;
}