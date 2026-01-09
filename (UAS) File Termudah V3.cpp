#include <stdio.h>
#include <math.h>


int main(){
	int x, selisih;
	int maxpos = 0;
	int minneg = 0;
	FILE *wle;
	wle = fopen ("testdata.in", "r");
	
	while (fscanf(wle, "%d", &x) != EOF){
		if (x>=0){
			if (maxpos < x){
				maxpos = x;
			}
		} else {
			if (minneg > x){
				minneg = x;
			}
		}
	}
	
	selisih = abs(maxpos - minneg);
	printf("%d\n", selisih);
}





