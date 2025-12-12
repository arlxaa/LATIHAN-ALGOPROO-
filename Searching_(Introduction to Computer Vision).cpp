#include <stdio.h>

void merge(long long arr[], long long low, long long mid, long long high){
	long long i = low;
	long long j = mid+1;
	long long k = 0;
	long long tempSize = high-low+1;
	long long temp[tempSize];
	
	while (i <= mid && j <= high){
		if (arr[i]<=arr[j]){
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
		k++;
		j++;
	}
	
	for (long long q = 0 ; q < tempSize ; q++){
		arr[low+q] = temp[q];
	}
}

void mergeSort(long long arr[], long long low, long long high){
	if (low >= high){
		return;
	}
	long long mid = low + (high-low)/2;
	
	mergeSort(arr, low, mid);
	mergeSort(arr, mid+1, high);
	merge(arr, low, mid, high);
}

int main(){
	FILE *wle;
	wle = fopen("testdata.in", "r");

	long long t, a, b, median;
	
	fscanf(wle, "%lld", &t);
	
	for (long long tc = 1; tc <= t; tc++){
		fscanf(wle, "%lld %lld", &a, &b);
		long long size = a*b;
		long long x[size];
		
		for (long long i = 0 ; i < size ; i++){
			fscanf(wle, "%lld", &x[i]);
		}
		
		mergeSort(x, 0, size-1);
		if (size % 2 == 0){
			long long val1 = x[(size / 2) - 1];
            long long val2 = x[size / 2];
            median = ceil((val1 + val2) / 2.0);
		} else{
			median = x[size/2];
		}
		
		printf("Case #%lld: %lld\n", tc, median);
	}
	fclose(wle);
}
