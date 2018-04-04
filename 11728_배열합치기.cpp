#include <stdio.h>
#include <algorithm>
using namespace std;
int k[2000002];
int main() {
	int n, m;
	scanf("%d %d", &n, &m);

	for (int i = 0; i != n; i++) {
		scanf("%d", &k[i]);
	}
	for (int i = n; i != n+m; i++) {
		scanf("%d", &k[i]);
	}
	sort(k, k + n + m);
	for (int i = 0; i != n + m; i++) printf("%d ", k[i]);
}