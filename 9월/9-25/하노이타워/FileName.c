#include <stdio.h>

void Hanoi(int num, char from, char by, char to);

int main(void) {
	//막대 a의 원반 n개를 막대 b를 경유하여 막대 c로 옮기기
	Hanoi(5, 'A', 'B', 'C');
	return 0;
}

void Hanoi(int num, char from, char by, char to) {
	if (num == 1) {	//이동할 원반의 개수가 1개라면
		printf("원반1을 %c에서 %c로 이동\n", from, to);
	}
	else {
		Hanoi(num - 1, from, to, by);
		printf("원반%d를 %c 에서 %c로 이동\n", num, from, to);
		Hanoi(num - 1, by, from, to);
	}
}