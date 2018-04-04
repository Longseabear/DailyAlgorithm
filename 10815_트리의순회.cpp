#include <stdio.h>
#include <algorithm>

using namespace std;
int postOrder[100001];
int inOrder[100001];

int getInOrderIndex(int inLeftIndex, int inRightIndex, int key) {
	for (int i = inLeftIndex; i <= inRightIndex; i++) {
		if (key == inOrder[i]) {
			return i;
		}
	}
	return -1;
}
int dnq(int postLeftIndex, int postRightIndex, int inLeftIndex, int inRightIndex) {
	int root = postOrder[postRightIndex];
	if (postLeftIndex > postRightIndex || inLeftIndex > inRightIndex)
		return 1;

	printf("%d ", root);

	int rootIndex = getInOrderIndex(inLeftIndex, inRightIndex, root);
	int leftNum = rootIndex - inLeftIndex;
	int rightNum = inRightIndex - rootIndex;

	//left
	dnq(postLeftIndex, postLeftIndex + leftNum - 1, inLeftIndex, rootIndex - 1);

	//right
	dnq(postRightIndex-rightNum, postRightIndex-1, rootIndex+1, inRightIndex);

	return 1;
}
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &inOrder[i]);
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", &postOrder[i]);
	}
	dnq(1, n, 1, n);
}