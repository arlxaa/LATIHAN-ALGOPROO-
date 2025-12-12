#include <stdio.h>

void merge(int arr[], int low, int mid, int high){
	int tempSize = high-low+1;
	int temp[tempSize];
	int i = low;
	int j = mid+1;
	int k = 0;
	
	while (i <= mid && j <= high){
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
	while (j <= high){
		temp[k] = arr[j];
		j++;
		k++;
	}
	for (int wle = 0 ; wle < tempSize ; wle++){
		arr[low+wle] = temp[wle];
	}
}


void mergeSort(int arr[], int low, int high){
	if (low >= high){
		return;
	}
	
	int mid = low + (high-low)/2;
	
	mergeSort(arr, low, mid);
	mergeSort(arr, mid+1, high);
	merge(arr, low, mid, high);
	
}

int main(){
	int t, a, time;
	scanf("%d", &t);
	for (int tc = 1; tc <= t; tc++){
		scanf("%d %d", &a, &time);
		int x[a];
		int tempTime = time;
		
		for (int i = 0 ; i < a ; i++){
			scanf("%d", &x[i]);
		}
		
		mergeSort(x, 0, a-1);
		int minCount = 0;
		int maxCount = 0;
		
		for (int i = 0 ; i < a; i++){
			if (tempTime>=x[i]){
				maxCount++;
				tempTime -= x[i];
			} else{
				break;
			}
		}
		
		tempTime = time;
		for (int i = a-1 ; i >=0; i--){
			if (tempTime>=x[i]){
				minCount++;
				tempTime -= x[i];
			} else{
				break;
			}
		}
		
		printf("Case #%d: %d %d\n", tc, minCount, maxCount);
		
		
	}
}




