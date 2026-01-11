#include <stdio.h>

int main(){
	int baris;
	scanf("%d", &baris);
	int x[105][105] ={0};
	int first = 1;
	for (int i = 0 ; i <= baris ; i++){
		
		for (int j = 0 ; j <= i; j++){
			if (j == 0 || j==i){
				x[i][j]=1;	
			} else{
				x[i][j] += x[i-1][j-1]+x[i-1][j];
			}
		}
	}
	
	for (int i = 0 ; i <= baris ; i++){
		if (first == -1){
			printf(" ");
		}
		printf("%d", x[baris][i]);
		first = -1;
	}
	printf("\n");
	
}



