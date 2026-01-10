#include <stdio.h>

int VF(int n){
	if (n == 1){
		return 1;
	} 
	if (n == 2){
		return 1;
	}
	else {
		return VF(n-VF(n-1)) + VF(n-VF(n-2));
	}
}

int main(){
	int t, n, mbek;
	
	scanf("%d", &t);
	
	for (int tc = 0 ; tc < t; tc++){
		scanf("%d", &n);
		int ans = 0;
		for (int i = 1 ; i <= n ; i++){
			mbek = VF(i);
			ans += mbek;
		}
		printf("Case #%d: %d\n", tc+1, ans);
	}
}
