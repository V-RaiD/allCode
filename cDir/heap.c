#include<stdio.h>

void max_heapify(int* arr, int arrlen, int root);
void swap(int root,int index,int* arr);

int main(){
	int* arr;
	int arrlen;
	int index = 0;
	//fill array

	////////////
	index = arrlen/2;

	for(index = arrlen/2;index > 0; index--){
		max_heapify(arr,arrlen,index);
	}
	return 0;
}

int* max_heapify(int* arr, int arrlen, int root){
	int left = 2*root + 1;
	int right = 2*root + 2;
	int maxindex = root;

	if(left < arrlen && arr[left] > arr[maxindex]){
		maxindex = left;
	}

	if(right < arrlen && arr[right] > arr[maxindex]){
		maxindex = right;
	}

	if(maxindex != root){
		swap(root,maxindex,arr);

		max_heapify(arr,arrlen,maxindex);
	}
	
}

void swap(int root,int index,int* arr){
	int temp = 0;

	temp = arr[root];
	arr[root] = arr[index];
	arr[index] = temp;
}
