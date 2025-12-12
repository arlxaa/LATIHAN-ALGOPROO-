#include <stdio.h>
#include <string.h>

int main(){
	FILE *wle;
	wle = fopen("testdata.in", "r");
	
	int t, n, a, b;
	fscanf(wle, "%d", &t); fgetc(wle);
	for (int tc = 1; tc <= t; tc++){
		fscanf(wle, "%d %d %d", &n, &a, &b); fgetc(wle);

		char x[n];
		
	
		fscanf(wle, "%s", x); fgetc(wle);


		int duration = 0, counter = 0;
		for (int i = 0 ; i <= n; i++){
			if (x[i] == '1'){
				duration++;
			} else{
				if (duration >= a && duration <= b){
					counter++;
				}
				duration = 0;
			}
		}
		printf("Case #%d: %d\n", tc, counter);
	}
	
}

