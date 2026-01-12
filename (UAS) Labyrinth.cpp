#include <stdio.h>

char lab[15][15];
int possible(int x, int y){
	if (x < 0 || x >= 10 || y < 0 || y>=10){
		return 0;
	}
	if (lab[x][y] == '#' || lab[x][y] =='V'){
		return 0;
	}
	

	if (lab[x][y] == 'E'){
		return 1;
	}
	lab[x][y] = 'V';
	if (possible(x+1, y)==1) return 1;
	if (possible(x-1, y)==1) return 1; 
	if (possible(x, y+1)==1) return 1;
	if (possible(x, y-1)==1) return 1;
	
}

int main(){
	FILE *wle;
	wle = fopen("testdata.in", "r");
	int xstart, ystart;
	for (int i = 0 ; i < 10 ; i++){
		fscanf(wle, "%[^\n]", lab[i]);
		fgetc(wle);
		
		for (int j = 0 ; j <10 ; j++){
			if (lab[i][j] == 'S'){
				xstart = i;
				ystart = j;
			}
		}
	}
	
	int labirin = possible(xstart, ystart); 
	if (labirin ==1 ){
		printf("BERHASIL\n");
	} else{
		printf("GAGAL\n");
	}
	
}

