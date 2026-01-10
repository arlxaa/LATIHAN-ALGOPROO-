#include <stdio.h>
#include <string.h>

struct data{
	char tanggal[51];
	char jammulai[51];
	char jamslese[51];
	char kegiatan[51];
};

void merge(struct data arr[], int left, int mid, int right){
	int i = left;
	int j = mid+1;
	int k = 0;
	int tempsize = right - left + 1;
	struct data temp[tempsize];
	
	while (i <= mid && j <= right){
		if (strcmp (arr[i].tanggal, arr[j].tanggal)<0){
			temp[k] = arr[i];
			i++;
			
		} else if (strcmp(arr[i].tanggal, arr[j].tanggal)>0){
			temp[k] = arr[j];
			j++;
		} else{
			//dari jam mulaiinyah
			if (strcmp (arr[i].jammulai, arr[j].jammulai) <= 0){
				temp[k] = arr[i];
				i++;
			} else{
				temp[k] = arr[j];
				j++;
			}
		}
		k++;
	}
	
	while (i <= mid){
		temp[k] = arr[i];
		i++;
		k++;
	}
	
	while (j <= right){
		temp[k] = arr[j];
		k++;
		j++;
	}
	
	for (int omg = 0 ; omg < tempsize ; omg++){
		arr[omg+left] = temp[omg];
	}
	
}

void mergeSort(struct data arr[], int left, int right){
	if (left >= right){
		return;
	}
	int mid = left + (right-left)/2;
	mergeSort(arr, left, mid);
	mergeSort(arr, mid+1, right);
	merge(arr, left, mid, right);
}

int binarysearch(struct data arr[], int left, int right, char date[], char jamtanya[]){
	int pos = -1;
	while (left <= right){
		int mid = left + (right-left)/2;
		
		if (strcmp(date, arr[mid].tanggal) == 0){
			//bandingin jammulai
			if (strcmp(jamtanya, arr[mid].jammulai)>=0 && strcmp(jamtanya, arr[mid].jamslese) < 0){
				pos = mid;
				right = mid-1;
				
			} else if (strcmp(jamtanya, arr[mid].jammulai)>0){
				left = mid+1;
				
			}else{
				right = mid-1;
			}
			
		} else if (strcmp(date, arr[mid].tanggal) < 0){
			right = mid - 1;
		} else{
			left = mid + 1;
		}
	}
	return pos;
}

int main(){
	int a, b;
	char date[51];
	char jamtanya[51];
	
	FILE *mbek;
	mbek = fopen("testdata.in", "r");
	
	fscanf(mbek, "%d", &a);
	fgetc(mbek);
	
	struct data wle[a];
	
	for (int i = 0; i < a; i++){
		fscanf(mbek, "%[^#]#%[^-]-%[^#]#%[^\n]", wle[i].tanggal, wle[i].jammulai, wle[i].jamslese, wle[i].kegiatan);
		fgetc(mbek);
	}
	
	mergeSort(wle, 0, a-1);
	
	fscanf(mbek, "%d", &b);
	fgetc(mbek);

	
	for (int i = 0 ; i < b ; i++){
		fscanf(mbek, "%[^#]#%s", date, jamtanya);
		fgetc(mbek);
		int position = binarysearch(wle, 0, a-1, date, jamtanya);
	
		if (position == -1){
			printf("free\n");
		} else{
			printf("%s\n", wle[position].kegiatan);
		}
	}
	
	
	
}


