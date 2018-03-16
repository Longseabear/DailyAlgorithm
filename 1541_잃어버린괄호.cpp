#include <stdio.h>
#include <math.h>
int main() {
	int num, res=0;
	char c, check = 0;
	// If meet a negative number, can subtract all number (grid)
	while (scanf("%d", &num) != EOF) {
		if (check == 0 && num < 0) 
			check = 1, res += num;
		else if(check==1) 
			res -= abs(num);
		else 
			res += num;
	}
	printf("%d", res);
}