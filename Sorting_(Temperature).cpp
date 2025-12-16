#include <stdio.h>
#include <string.h>

struct data{
	char kota[1010];
	char jenis;
	double der;
	double tem;
	
};

void bubbleSort(struct data arr[], int kanan){
	struct data temp;
	for (int i = 0; i < kanan-1 ; i++){
		for (int j = 0 ; j < kanan-1-i; j++){
			if (arr[j].tem > arr[j+1].tem){
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
	
	for (int i = 0; i < kanan-1 ; i++){
		for (int j = 0 ; j < kanan-1-i; j++){
			if (arr[j].tem == arr[j+1].tem){
				if (strcmp(arr[j].kota, arr[j+1].kota)>0){
					temp = arr[j];
					arr[j] = arr[j+1];
					arr[j+1] = temp;
				}
			}
		}
	}
}

int main(){
	FILE *wle;
	wle = fopen("testdata.in", "r");
	int n = 0;
	struct data wel[105];
	
	while (fscanf(wle, "%[^#]#%lf#%c\n", wel[n].kota, &wel[n].der, &wel[n].jenis)!=EOF){
		if (wel[n].jenis == 'F'){
			wel[n].tem = (wel[n].der - 32.00)*5.00/9.00;
		} else {
			wel[n].tem = wel[n].der;
		}
		n++;
		
	}
	
	bubbleSort(wel, n);
	
	for (int i = 0 ; i < n ; i++){
		printf("%s is %.2lf%c\n", wel[i].kota, wel[i].der, wel[i].jenis);
	}
	
	
	
}
