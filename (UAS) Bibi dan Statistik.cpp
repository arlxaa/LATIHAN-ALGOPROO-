#include <stdio.h>

int main (){
	FILE *wle;
	wle = fopen("testdata.in", "r");
	int n;
	fscanf(wle, "%d", &n);
	double x;
	double sum = 0.00;
	
	for (int i = 0 ; i < n ; i++){
		fscanf(wle, "%lf", &x);
		sum += x;
	}
	double mean = sum/n;
	
	printf("%.2lf\n", mean);
	
}



