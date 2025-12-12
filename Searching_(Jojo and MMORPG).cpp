#include <stdio.h>

void merge(long long arr[], long long low, long long mid, long long high){
	long long i = low;
	long long j = mid+1;
	long long k = 0;
	long long tempSize = high - low + 1;
	long long temp[high-low+1];
	
	while (i <= mid && j <= high){
		if(arr[i]<=arr[j]){
			temp[k] = arr[i];
			i++;
		} else {
			temp[k] = arr[j];
			j++;
		}
		k++;
	}
	while (i<= mid){
		temp[k] = arr[i];
		i++;
		k++;
	}
	while (j <= high){
		temp[k] = arr[j];
		j++;
		k++;
	}
	for (long long wle = 0; wle < tempSize; wle++){
		arr[low+wle] = temp[wle];
	}
}

void mergeSort(long long arr[], long long low, long long high){
	if (low>=high){
		return;
	}
	long long mid = low + (high-low)/2;
	
	mergeSort(arr, low, mid);
	mergeSort(arr, mid+1, high);
	merge(arr, low, mid, high);
}

int main(){
	long long n, pow, counter=0, j=0;
	scanf("%lld", &n);
	long long x[n];
	for (long long i = 0 ; i < n ; i++){
		scanf("%lld", &x[i]);
	}
	
	mergeSort(x, 0, n-1);
	scanf("%lld", &pow);
	while (j < n && x[j] <= pow){
		pow -= x[j];
		counter++;
		j++;
	}
	printf("%lld\n", counter);
	
	
}

