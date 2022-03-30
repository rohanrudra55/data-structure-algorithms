#include<stdio.h>
int count=0;

int interpolationsearch(int arr[],int low,int high,int val){
	count++;

	float num=low+(high-low);
	float den=(((val-arr[low])*1.0)/(arr[high]-arr[low]));
	int mid=num*den;	

	if(arr[mid]==val)
		return mid;
	else if(val<arr[mid])
		high=mid-1;
	else if(val>arr[mid])
		low=mid+1;
	else
		return -1;
	return interpolationsearch(arr,low, high, val);
}

int main(){
	int arr[]={1,2,3,4,5,6,7,8,9,10};
	int pos=interpolationsearch(arr,0,9,5);
	printf("Postion: %d counted: %d\n",pos+1,count);
	return 0;
}