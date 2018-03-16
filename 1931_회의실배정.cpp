#include <stdio.h>
#include <algorithm>

using namespace std;
typedef struct node {
	int start;
	int end;

	bool operator < (const struct node& a) const {
		if (end == a.end)
			return start < a.start;
		return end < a.end;
	}
}Node;
int currentEnd = -1;
int res;
Node nodes[100001];

int main() {
	int n;

	scanf("%d", &n);

	// Suppose it is the best year if I work on the meeting that ends earliest.
	// using Proof by contradiction, If one optimum condition is selected, then the maximum damage should be equal to 1. 
	for (int i = 0; i != n; i++) {
		scanf("%d %d", &nodes[i].start, &nodes[i].end);
	}

	// sort based to ends earliest.
	sort(nodes, nodes + n);

	for (int i = 0; i != n; i++) {
		if (nodes[i].start >= currentEnd) {
			res++;
			currentEnd = nodes[i].end;
		}
	}
	printf("%d\n", res);
}