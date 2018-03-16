#include <stdio.h>
#include <algorithm>
using namespace std;

int n, res = 0, p[1001];
int main() {
	// The less time a person has spent in front of him, the less likely he or she will be able to handle it in less time.
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &p[i]);

	// sort
	sort(p, p + n);

	for (int i = 0; i < n; i++)
		res += (p[i] * (n - i));

	printf("%d", res);
}