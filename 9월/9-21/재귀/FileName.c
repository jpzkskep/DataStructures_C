#pragma warning (disable:4996)
#include <stdio.h>

void Recursive(int num) {
	if (num <= 0) return;
	printf("call %d\n", num);
	Recursive(num - 1);
}

int main(void) {
	Recursive(3);
	return 0;
}