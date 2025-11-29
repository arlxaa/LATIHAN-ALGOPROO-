#include <stdio.h>

int tillOne(int x){
	if (x==1){
		return 1;
	}
	if (x %2==0){
		return tillOne(x/2);
	} else {
		return tillOne(x+1) + tillOne(x-1);
	}
}

int main(){
	int n, x;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++){
		scanf("%d", &x);
		printf("Case #%d: ", i);
		int ans = tillOne(x);
		printf("%d\n", ans);
	}
}
