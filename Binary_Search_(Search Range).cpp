#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

struct data{
	char name[260];
	int score;
};

int binarySearch(struct data arr[], char target[], int length){
	int left = 0;
	int right = length;
	while (left <= right){
		int mid = (left + right)/2;
		if (strcmp(target, arr[mid].name) == 0){
			return mid;
		} else if (strcmp(target, arr[mid].name)>0){
			left = mid+1;
		} else{
			right = mid-1;
		}
		
	}
	return -1;
}



int main(){
	int a, b, scoreGap, boardGap;
	char org1[260], org2[260];
	
	scanf("%d", &a); getchar();
	struct data wle[a];
	
	for (int i = 0 ; i < a; i++){
		scanf("%s %d", wle[i].name, &wle[i].score); getchar();
	}
	
	scanf("%d", &b); getchar();
	for (int i = 0; i < b ;i++){
		scanf("%s %s", org1, org2); getchar();
		if (strcmp(org1, org2)==0){
			printf("not valid\n"); 
			continue;
		}
		int hasil1 = binarySearch(wle, org1, a-1);
		int hasil2 = binarySearch(wle, org2, a-1);
		if (hasil1 == -1 || hasil2 == -1){
			printf("not found\n");
		} else{
			scoreGap = abs(wle[hasil1].score - wle[hasil2].score);
			boardGap = abs(hasil1-hasil2);
			printf("%d %d\n", scoreGap, boardGap);
		}
		
	}
	
}





