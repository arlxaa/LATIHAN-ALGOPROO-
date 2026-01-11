#include <stdio.h>
#include <math.h>
#include <string.h>

int main(){
	char kata[100];
	
	int sum = 0;
	int length;
	
	int min = 100000;
	int max = -10000;
	
	FILE *wle;
	wle = fopen("testdata.in", "r");
	
	while (fscanf(wle, "%[^\n]", kata) == 1){
		sum = 0;
		fgetc(wle);
		length = strlen(kata);
		
		for (int i = 0 ; i < length ; i+=2){
			sum += kata[i]-'0';
		}
		if (max < sum){
			max = sum;
		} 
		if (min > sum){
			min = sum;
		}
	}
	
	printf("%d\n", abs(max-min));
	
}

