#include <stdio.h>
#include <algorithm>

using namespace std;

int pos, neg, zero, one;

int main() {
	// ������, �ѹ� ���ų� ���� �ʰų�.
	// 0,1�� ���� �ʴ°� �׻� �̵��̴�.
	// 2�̻��� ���� 0,1�� �ƴ� ����.

	int n, map[10001];
	int res = 0;
	scanf("%d", &n);
	for (int i = 0; i != n; i++) {
		scanf("%d", &map[i]);
		if (map[i] == 0) {
			zero++;
		}
		else if (map[i] == 1) {
			one++;
		}
		else if (map[i] > 0) {
			pos++;
		}
		else {
			neg++;
		}
	}
	sort(map, map + n);
	for (int i = 0; i != neg / 2; i++) {
		res += (map[i * 2] * map[i * 2 + 1]);
	}
	if (neg % 2 == 1) {
		if (zero == 0)
			res += map[neg - 1];
	}
	res += one;
	if (pos % 2 == 1) {
		res += map[neg + zero + one];
		for (int i = neg + zero + one+1; i < neg + zero + one + pos; i+=2) {
			res += (map[i] * map[i+1]);
		}
	}
	else {
		for (int i = neg + zero + one; i < neg + zero + one + pos; i+=2) {
			res += (map[i] * map[i + 1]);
		}
	}

	printf("%d", res);
}