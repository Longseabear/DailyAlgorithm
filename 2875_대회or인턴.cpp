#include <stdio.h>
#define MIN(a,b) ((a)<(b)?(a):(b))
int main() {
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	int maxNum = MIN(n / 2, m);
	int remain = n - maxNum * 2;
	remain += (m - maxNum);
	k -= remain;
	while (k > 0) { 
		maxNum--;
		k -= 3;
	}
	printf("%d", maxNum);
}