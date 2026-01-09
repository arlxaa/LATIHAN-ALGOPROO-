#include <stdio.h>

void merge(int arr[], int left, int mid, int right){
	int i = left;
	int j = mid+1;
	int k = 0;
	int tempsize = right-left+1;
	int temp[tempsize];
	
	while (i <= mid && j <= right){
		if (arr[i] <= arr[j]){
			temp[k] = arr[i];
			i++;
		} else{
			temp[k] = arr[j];
			j++;
		}
		k++;
	}
	
	while (i <= mid){
		temp[k] = arr[i];
		i++;
		k++;
	}
	while (j <= right){
		temp[k] = arr[j];
		j++;
		k++;
	}
	
	for (int mbek = 0 ; mbek < tempsize ; mbek++){
		arr[mbek+left] = temp[mbek];
	}
}

void mergeSort(int arr[], int left, int right){	
	if (left >= right){
		return;
	}
	int mid = left + (right-left)/2;
	
	mergeSort(arr, left, mid);
	mergeSort(arr, mid+1, right);
	merge(arr, left, mid, right);
}

int main(){
	int n;
	
	scanf("%d", &n);
	
	int x[n];
	
	for (int i = 0 ; i < n ; i++){
		scanf("%d", &x[i]);
	}
	
	mergeSort (x, 0, n-1);
	
	int pos = n/2;
	
	for (int i = pos +1 ; i < n ; i++){
		if (i > pos+1){
			printf(" ");
		}
		printf("%d", x[i]);
	}
}


