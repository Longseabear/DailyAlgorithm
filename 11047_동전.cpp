#include <stdio.h>

int main() {
	int n, k;
	int coin[11];
	int coinCount = 0;

	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &coin[i]);
	}

	// - Can use greed algorithm ( because of condition )
	// - You can fill it from the largest coin.
	do {
		int eachCoins = k / coin[n];
		coinCount += eachCoins;
		k = k - coin[n] * eachCoins;
	} while (--n);
	printf("%d", coinCount);
}