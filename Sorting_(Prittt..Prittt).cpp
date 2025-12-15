#include <stdio.h>

int binarySearch(int arr[], int left, int right, int target){
	int pos = -1;
	while (left<= right){
		int mid = left + (right - left)/2;
		if (arr[mid] == target){
			return mid;
			right = mid-1;
		} else if (arr[mid] > target){
			right = mid -1;
		} else {
			left = mid +1;
		}
	} 
	return pos;
	
}

void merge(int arr[], int left, int mid, int right){
	int i = left;
	int j  = mid+1;
	int k = 0;
	int tempSize =  right-left+1;
	int temp[tempSize];
	
	while (i<= mid && j <= right){
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
	
	for (int a = 0 ; a < tempSize ; a++){
		arr[a+left] = temp[a];
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
	int a, b, target;
	
	scanf("%d", &a);
	int x[a];
	
	for (int i = 0 ; i < a ; i++){
		scanf("%d", &x[i]);
	}
	
	mergeSort(x, 0, a-1);
	
	scanf("%d", &b);

	for (int i = 0 ; i < b; i++){
		scanf("%d", &target);
		int hasil = binarySearch(x, 0, a-1, target);
		if (hasil != -1){
			printf("%d\n", hasil+1);
		} else{
			printf("%d\n", hasil);
		}
	}
	
	
}



