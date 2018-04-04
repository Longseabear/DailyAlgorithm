#include <stdio.h>

char map[100][100];
int check(int idx_x, int idx_y, int size) {
	int value = map[idx_y][idx_x];
	for (int i = idx_y; i != idx_y + size; i++) {
		for (int j = idx_x; j != idx_x + size; j++) {
			if (map[i][j] != value) return -1;
		}
	}
	return value;
}
void dnq(int idx_x, int idx_y, int size) {
	int res;
	printf("(");

	// 왼쪽 위
	if ((res = check(idx_x, idx_y, size / 2)) >= 0) {
		printf("%d", res);
	}
	else {
		dnq(idx_x, idx_y, size / 2);
	}
	// 오른쪽 위
	if ((res = check(idx_x + size / 2, idx_y, size / 2)) >= 0) {
		printf("%d", res);
	}
	else {
		dnq(idx_x + size / 2, idx_y, size / 2);
	}
	// 왼쪽 아래
	if ((res = check(idx_x, idx_y + size / 2, size / 2)) >= 0) {
		printf("%d", res);
	}
	else {
		dnq(idx_x, idx_y + size / 2, size / 2);
	}
	// 오른쪽 아래
	if ((res = check(idx_x + size / 2, idx_y + size / 2, size / 2)) >= 0) {
		printf("%d", res);
	}
	else {
		dnq(idx_x + size / 2, idx_y + size / 2, size / 2);
	}
	printf(")");
}
int main() {
	int n, res;
	char c;
	scanf("%d", &n);
	scanf("%c", &c);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%c", &map[i][j]);
			map[i][j] -= '0';
		}
		scanf("%c", &c);
	}
	if ((res = check(1, 1 , n)) >= 0) {
		printf("%d", res);
	}
	else {
		dnq(1, 1, n);
	}
}