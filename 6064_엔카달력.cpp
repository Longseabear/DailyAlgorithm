#include <stdio.h>

long long uclid(long long a, long long b) {
	if (b == 0) {
		return a;
	}
	return uclid(b, a%b);
}
long long minMultiple(long long a, long long b) {
	return a*b / uclid(a, b);
}
int main() {
	int testCase;
	scanf("%d", &testCase);
	while (testCase--) {
		int n, m, x, y;
		scanf("%d %d %d %d", &n, &m, &x, &y);

		long long deltaX = n - x;
		long long deltaY = m - y;
		long long finalYear = minMultiple(n, m);
		long long res = -1;

		for (int i = 1; n*i - deltaX <= finalYear; i++) {
			if ((double)(n*i - deltaX + deltaY) / m == (int)((n*i - deltaX + deltaY) / m)) {
				res = n*i- deltaX;
			}
		}
		printf("%d\n", res);
	}
}