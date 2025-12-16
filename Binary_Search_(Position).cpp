#include <stdio.h>

int binarySearch(int arr[], int left, int right, int target){
	int pos = -1;
	while (left<= right){
		int mid = left + (right - left)/2;
		if (arr[mid] == target){
			pos = mid;
			right = mid-1;
		} else if (arr[mid] > target){
			right = mid-1;
		} else if (arr[mid] < target){
			left = mid+1;
		}
	}
	return pos;
}

int main(){
	int a, b, target;
	scanf("%d %d", &a, &b);
	int x[a];
	for (int i = 0 ; i < a; i++){
		scanf("%d", &x[i]);
	}
	for (int i = 0 ; i < b ; i++){
		scanf("%d", &target);
		int ans = binarySearch(x, 0, a-1, target);
		if (ans == -1){
			printf("-1\n");
		} else{
			printf("%d\n", ans+1);
		}
	}
}
