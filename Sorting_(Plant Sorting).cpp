#include <stdio.h>
#include <string.h>



struct tanaman{
	int nomor;
	char nama[45];
};

void merge(struct tanaman arr[], int left, int mid, int right){
	int i = left;
	int j = mid+1;
	int k = 0;
	int tempSize = right - left + 1;
	struct tanaman temp[tempSize];
	
	while (i <= mid && j <= right){
		if (strcmp(arr[i].nama, arr[j].nama)<=0){
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
	
	for (int p = 0 ; p < tempSize ; p++){
		arr[left+p] = temp[p];
	}
}

void mergeSort(struct tanaman arr[], int left, int right){
	if (left >= right){
		return;
	}
	int mid = left + (right - left)/2;
	
	mergeSort(arr, left, mid);
	mergeSort(arr, mid+1, right);
	merge(arr, left, mid, right);
}


int main(){
	FILE *wle;
	wle = fopen ("testdata.in", "r");
	
	int n;
	
	
	fscanf(wle, "%d", &n); fgetc(wle);
	struct tanaman well[n];
	for (int i = 0 ; i < n ; i++){
		fscanf(wle, "%d#%[^\n]", &well[i].nomor, well[i].nama);
		fgetc(wle);
	}
	
	mergeSort(well, 0, n-1);
	
	for (int i = 0 ; i < n ;i++){
		printf("%d %s\n", well[i].nomor, well[i].nama);
	}
	
}



