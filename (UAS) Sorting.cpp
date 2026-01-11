#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int left, int mid, int right){
	int i = left;
	int j = mid+1;
	int k = 0;
	int tempsize = right - left +1;
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
		k++;
		i++;
	}
	
	while (j <= right){
		temp[k] = arr[j];
		k++;
		j++;
	}
	
	for (int ap = 0 ; ap < tempsize ; ap++){
		arr[ap+left] = temp[ap];
	}
}

void mergesort(int arr[], int left, int right){
	if (left >= right){
		return;
	}
	
	int mid = left + (right-left)/2;
	
	mergesort(arr, left, mid);
	mergesort(arr, mid+1, right);
	merge(arr, left, mid, right);
}

int main(){
	int n;
	scanf("%d", &n);
	int x[n];
	
	for (int i = 0 ; i <  n ; i++){
		scanf("%d", &x[i]);
	}
	
	mergesort(x, 0, n-1);
	
	int max = abs(x[0] - x[1]);
	
	for (int i = 1 ; i < n-1 ; i++){
		if (max < abs(x[i] - x[i+1])){
			max = abs(x[i] - x[i+1]);
		}
	}
	int first = 1;
	for (int i = 0 ; i < n ; i++){
		if (max == abs(x[i] - x[i+1])){
			
			if (first == 1){
				printf("%d %d", x[i], x[i+1]);
				first = 0;
			} else{
				printf(" %d %d", x[i], x[i+1]);
			}
			
		}
	}
	printf("\n");
	
}



