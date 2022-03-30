#include<stdio.h>
#include<math.h>
int count=0;

int jumpsearch(int arr[],int val,int end){
	int jump=sqrt(end);

	int beg=0;
	while(arr[jump-1]<val){
		count++;
		beg=jump;
		jump+=sqrt(end);
		if(beg>=end || jump>end)
			return -1;
	}


	while(arr[beg]<val){
		beg++;
		count++;
	}
	if(arr[beg]==val)
		return beg;
	return -1;

}
int main(){
	int arr[]={1,2,3,4,5,6,7,8,9,10};
	int size=sizeof(arr)/sizeof(*arr);
	int pos=jumpsearch(arr,9,size) + 1; 
	printf("Position: %d Counted: %d\n",pos,count );
}