#include <stdio.h>
#include <string.h>

struct gudank{
	char item[101];
	int stock;
};

void merge (struct gudank arr[], int left, int mid, int right){
	int i = left;
	int j = mid+1;
	int k = 0;
	int tempsize = right-left+1;
	struct gudank temp[tempsize];
	
	while (i <= mid && j <= right){
		if (strcmp (arr[i].item, arr[j].item)<=0){
			temp[k] = arr[i];
			i++;
		} else{
			temp[k] = arr[j];
			j++;
		}
		k++;
	}
	
	while (i <= left){
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

void mergeSort(struct gudank arr[], int left, int right){
	if (left >= right){
		return;
	}
	int mid = left + (right-left)/2;
	
	mergeSort(arr, left, mid);
	mergeSort(arr, mid+1, right);
	merge(arr, left, mid, right);
}

int main(){
	int t, a, b;
	scanf("%d", &t);
	struct gudank wle[t];
	
	for (int i = 0 ; i < t; i++){
		scanf("%s %d %d", wle[i].item, &a, &b); getchar();
		wle[i].stock = a-b;
	}
	
	mergeSort(wle, 0, t-1);
	
	for (int i = 0 ; i < t; i++){
		printf("%s %d\n", wle[i].item, wle[i].stock);
	}
}



