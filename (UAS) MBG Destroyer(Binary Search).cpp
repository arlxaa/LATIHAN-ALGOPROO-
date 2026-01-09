//MBG DESTROYER DR RESPONSI

#include <stdio.h>

int binarysearch(int arr[], int target, int left, int right){
	int pos = -1;
	while (left <= right){
		int mid = left + (right-left)/2;
		if (arr[mid] == target){
			pos = mid;
			right = mid-1;
		} else if (target > arr[mid]){ //krn urutan datanya dari besar ke kecil
			right = mid-1;
		} else {
			left = mid + 1;
		}
	}
	return pos;
}

int main(){
	int x, y;
	scanf("%d %d", &x, &y);
	int mbg[x];
	int cari;
	
	for (int i = 0 ; i < x; i++){
		scanf("%d", &mbg[i]);
	}
	for (int i = 0 ; i < y ; i++){
		scanf("%d", &cari);
		
		int position = binarysearch(mbg, cari, 0, x-1);
		
		if (position == -1){
			printf("MBG %d was not located!\n", cari);
		} else{
			printf("MBG %d was located in %d meters!\n", cari, position+1);
		}
	}
	
	
}
