//eltit a si sihT problem


#include <stdio.h>

void cetak(char kata[], int index){
	if (kata[index] =='\0'){
		return;
	}
	cetak(kata, index+1);
	printf("%c", kata[index]);
}

int main(){
	int n;
	char kalimat[1010];
	scanf("%d", &n);
	for (int i = 1; i <= n; i++){
		scanf("%[^\n]", kalimat);
		printf("Case #%d: ", i);
		cetak(kata, 0);
	}
}
