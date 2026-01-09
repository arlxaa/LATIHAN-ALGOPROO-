#include <stdio.h>

int main(){
	int x;
	int product = 1;
	int sum = 0;
	FILE *wle;
	wle = fopen("testdata.in","r");
	while (fscanf(wle, "%d", &x) != EOF){
		if (x%2==0){
			//genap
			product *= x;
		} else{
			sum += x;
		}
	}

	printf("%d\n", product-sum);
}



