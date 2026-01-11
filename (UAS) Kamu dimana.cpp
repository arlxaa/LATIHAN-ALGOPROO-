#include <stdio.h>

struct data{
	int nilai;
	char nama[11];
};

int binarysearch(struct data arr[], int left, int right, int target){
	int pos;
	while (left <= right){
		int mid = left + (right - left)/2;
		
		if (target > arr[mid].nilai){
			left = mid+1;
		} else if (target < arr[mid].nilai){
			right = mid-1;
			
		} else{
			pos = mid;
			right = mid-1;
		}
	}
	
	return pos;
}


int main(){
	int n, cari1;
	char siapa1[11];
	
	scanf("%d", &n);
	struct data wle[n];
	getchar();
	
	for (int i = 0 ; i < n ; i++){
		scanf("%d", &wle[i].nilai);
		getchar();
	}
	
	for (int i = 0 ; i < n ; i++){
		scanf("%s", wle[i].nama);
		getchar();
	}
	scanf("%d %s", &cari1, siapa1); getchar();
	int pos1 = binarysearch(wle, 0, n-1, cari1);
	
	printf("%d %s %s\n", pos1+1, wle[pos1-1].nama, wle[pos1+1].nama);
}

