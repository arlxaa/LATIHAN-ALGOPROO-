#include <stdio.h>

struct data{
	char nama[105];
	int nilai;
	char nim[102];
};

int main(){
	FILE *mbek; 
	mbek = fopen("testdata.in", "r");
	int n, t, sum, mean, counter;
	
	fscanf(mbek, "%d", &t);
	fgetc(mbek);
	struct data wle[t];
	for (int tc = 1; tc <= t; tc++){
		mean = 0;
		n = 0;
		sum = 0;
		counter++;
		while (fscanf(mbek, "%[^#]#%[^#]#%d\n", wle[n].nim, wle[n].nama, &wle[n].nilai)==3){
			sum += wle[n].nilai;
			n++;
		}
		
		mean = sum/n;
		
		for (int i = 0 ; i < n ; i++){
			if (mean < wle[i].nilai){
				counter++;
			}
		}
		
		printf("Case #%d:\n", tc);
		printf("%d\n", counter);
		
		for (int i = 0 ; i < n ; i++){
			if (mean < wle[i].nilai){
				printf("%s %s %d\n", wle[i].nim, wle[i].nama, wle[i].nilai);
			}
		}
		
	}
	
}

