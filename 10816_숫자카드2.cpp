#include <stdio.h>
#include <algorithm>

using namespace std;
int a[500001];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i != n; i++) {
		scanf("%d", &a[i]);
	}
	sort(a, a + n);
	int m;
	scanf("%d", &m);
	for (int i = 0; i != m; i++) {
		int val;
		scanf("%d", &val);

		int* one = lower_bound(a, a + n, val);
		int* two = upper_bound(a, a + n, val);
		printf("%d ", two - one);
	}
}