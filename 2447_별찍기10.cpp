#include <stdio.h>

char map[6562][6562];

void draw(int x, int y, int size) {
	if (size == 1) {
		map[y][x] = 1;
		return;
	}
	for (int i = 0; i != 3; i++) {
		for (int j = 0; j != 3; j++) {
			if (i == 1 && j == 1)
				continue;
			draw(x + j*(size/3), y + i*(size/3), size / 3);
		}
	}
}
int main() {
	int n;
	scanf("%d", &n);
	draw(1, 1, n);
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			printf("%c", map[i][j] == 1 ? '*' : ' ');
		}
		printf("\n");
	}
}