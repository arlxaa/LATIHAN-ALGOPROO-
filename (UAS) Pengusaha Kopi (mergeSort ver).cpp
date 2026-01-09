#include <stdio.h>

struct cafe{
	char nama[35];
	long long harga;
};

void merge(struct cafe arr[], int left, int mid, int right){
	int i = left;
	int j = mid+1;
	int k = 0;
	int tempsize = right - left +1;
	struct cafe temp[tempsize];
	
	while (i <= mid && j <= right){
		if (arr[i].harga <= arr[j].harga){
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
	
	for (int mbek = 0 ; mbek < tempsize ; mbek++){
		arr[mbek+left] = temp[mbek];
	}
}


void mergeSort(struct cafe arr[], int left, int right){
	if (left >= right){
		return;
	}
	int mid = left + (right - left)/2;
	
	mergeSort(arr, left, mid);
	mergeSort(arr, mid+1, right);
	merge(arr, left, mid, right);
}

int main(){
	int n, mili;
	scanf("%d", &n); getchar();
	struct cafe wle[n];
	
	for (int i = 0 ; i < n; i++){
		scanf("%[^#]#%d", wle[i].nama, &mili); getchar();
		if (mili >= 0 && mili <= 354){
			wle[i].harga = 53000;
		} else if (mili > 354 && mili <= 473){
			wle[i].harga = 57000;
		} else if (mili > 473 && mili <= 591){
			wle[i].harga = 60000;
		} else{
			wle[i].harga = 70000;
		}
	}
	
	mergeSort (wle, 0, n-1);
	
	for (int i = 0 ; i < n ; i++){
		printf("%s - %lld\n", wle[i].nama, wle[i].harga);
	}
}



