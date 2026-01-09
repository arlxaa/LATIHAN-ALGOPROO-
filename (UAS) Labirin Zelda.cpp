#include <stdio.h>

int main() {
    int D;
    long long N; 
    scanf("%d %lld", &D, &N);

    // Loop Luar: Mengulang proses sebanyak D kali
    for (int i = 0; i < D; i++) {
        
        long long totalSementara = 0;
        
        // Loop Dalam: Menghitung 1 + 2 + ... + N secara manual
        // Contoh: Kalau N=3, dia loop 1+2+3
        for (long long j = 1; j <= N; j++) {
            totalSementara += j;
        }
        
        // Update N dengan hasil total yang baru
        N = totalSementara;
    }

    printf("%lld\n", N);
    return 0;
}
