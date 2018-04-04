#include <stdio.h>
#include <algorithm>

using namespace std;


int vector[500001];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i != n; i++) {
		scanf("%d", &vector[i]);
	}
	sort(vector, vector + n);

	int m;
	scanf("%d", &m);
	while (m--) {
		int q;
		scanf("%d", &q);
		printf("%d ",binary_search(vector, vector + n, q));
	}
}