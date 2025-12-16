#include <stdio.h>
#include <string.h>

struct yutub{
	char judul[1010];
	char artis[1010];
	int view;
};

void bubbleSort(struct yutub arr[], int kanan){
	struct yutub temp;
	for (int i = 0 ; i < kanan-1; i++){
		for (int j = 0 ; j < kanan-1-i ; j++){
			if (arr[j].view < arr[1+j].view){
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			} 
		}
	}
	
	for (int j = 0 ; j < kanan-1; j++){
		for (int i = 0; i < kanan-j-1 ; i++){
		if (arr[i].view == arr[i+1].view){
			if(strcmp(arr[i].judul, arr[i+1].judul)>0){
				temp = arr[i];
				arr[i] = arr[i+1];
				arr[i+1] = temp;
			}
		}
	}
	}
}



int main(){
	FILE *wle;
	wle = fopen("testdata.in", "r");
	int n=0;
	struct yutub yt[105];
	while(fscanf(wle, "%[^#]#%[^#]#%d\n", yt[n].judul, yt[n].artis, &yt[n].view)!= EOF){
		n++;
	}
	
	bubbleSort(yt, n);
	
	for (int i = 0 ; i < n ; i++){
		printf("%s by %s - %d\n", yt[i].judul, yt[i].artis, yt[i].view);
	}
}
