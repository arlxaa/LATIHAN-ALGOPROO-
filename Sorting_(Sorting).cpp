#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>

void merge(int arr[], int left, int mid, int right){
	int i = left;
	int j = mid+1;
	int k = 0;
	int tempSize = right-left+1;
	int temp[tempSize];
	
	while (i <= mid && j <= right){
		if (arr[i]<= arr[j]){
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
	
	while (j<= right){
		temp[k] = arr[j];
		j++;
		k++;
	}
	
	for (int wle = 0 ; wle < tempSize ; wle++){
		arr[wle+left] = temp[wle];
	}
}

void mergeSort(int arr[], int left, int right){
	if (left>= right){
		return;
	} 
	int mid = left + (right-left)/2;
	
	mergeSort(arr, left, mid);
	mergeSort(arr, mid+1, right);
	merge(arr, left, mid, right);
}

int main(){
	int n, max;
	scanf("%d", &n);
	int x[n];
	for (int i = 0 ; i < n ; i++){
		scanf("%d", &x[i]);
	}
	
	mergeSort(x, 0, n-1);
	
	max = abs(x[0]-x[1]);
	
	for (int i = 0 ; i< n-1 ; i++){
		if (max < abs(x[i] - x[i+1])){
			max = abs(x[i] - x[i+1]);
		}
	}
	
	int first = 1;
	for (int i = 0 ; i< n-1 ; i++){
		if (max == abs(x[i] - x[i+1])){
			if (first != 1){
				printf(" ");
			}
			first = 0;
			printf("%d %d", x[i], x[i+1]);
		}		
	}
	printf("\n");
	
}









