#include <stdio.h>

int binarySearch(int arr[], int right, int target){
	int left = 1;
	int pos = -1;
	while (left <= right){
		int mid = left + (right-left)/2;
		if (arr[mid] <= target){
			left = mid+1;
			pos = mid;
		} else{
			right = mid-1;
		}
	}
	return pos;
}

int main(){
	int a, b, temp, target;
	scanf("%d", &a);
	int x[a+1];
	x[0] = 0;
	for (int i = 1 ; i <= a; i++){
		scanf("%d", &temp);
		x[i] = x[i-1] + temp;
	}
	scanf("%d", &b);
	for (int i = 0 ; i < b ; i++){
		scanf("%d", &target);
		int ans = binarySearch(x, a, target);
		printf("Case #%d: %d\n", i+1, ans);
	}
	
}
