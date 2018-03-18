#include <stdio.h>
#include <string.h>
int number[10];
int checkSum() {
	int sum = 0;
	for (int i = 0; i <= 9; i++) {
		sum += number[i] * i;
	}
	return sum;
}
int main() {
	// square number example
	// In case of 3, each number count of all
	// ex) 123456789 = 1+2+3+4+5+6+7+8+9
	char c[100002];
	scanf("%s", c);
	int c_size = strlen(c);
	for (int i = 0; i != c_size; i++) {
		number[c[i] - '0']++;
	}

	if (number[0] > 0 && checkSum() == 0) {
		printf("-1\n");
		return 1;
	}
	if (number[0] == 0 || checkSum()%3!=0) {
		printf("-1\n");
	}
	else {
		for (int i = 9; i >= 0; i--) {
			for (int j = 0; j != number[i]; j++) {
				printf("%d", i);
			}
		}
		printf("\n");
	}
}
