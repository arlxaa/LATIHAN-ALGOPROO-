#include <stdio.h>
#include <string.h>

int main(){
	int n, length1, length2;
	char kata1[101], kata2[101];
	scanf("%d", &n); getchar();
	
	for (int tc = 1; tc <= n ; tc++){
		scanf("%s", kata1);
		length1 = strlen(kata1);
		getchar();
		
		scanf("%s", kata2);
		length2 = strlen(kata2);
		getchar();
		
		//bubblesort untuk kata2
		
		for (int i = 0 ; i < length2 ; i++){
			for (int j = 0 ; j < length2 - i - 1 ; j++){
				if (kata2[j] > kata2[j+1]){
					char temp = kata2[j];
					kata2[j] = kata2[j+1];
					kata2[j+1] = temp;
				}
			}
		}

		
		printf("Case #%d: ", tc);
		for (int i = 0 ; i < length2 ; i++){
			for (int j = 0 ; j < length1; j++){
				
				if (kata1[j] == kata2[i]){
					printf("%c", kata1[j]);	
				}
			}

		}
	printf("\n");
	}
}


