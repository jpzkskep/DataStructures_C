#include <stdio.h>

void Hanoi(int num, char from, char by, char to);

int main(void) {
	//���� a�� ���� n���� ���� b�� �����Ͽ� ���� c�� �ű��
	Hanoi(5, 'A', 'B', 'C');
	return 0;
}

void Hanoi(int num, char from, char by, char to) {
	if (num == 1) {	//�̵��� ������ ������ 1�����
		printf("����1�� %c���� %c�� �̵�\n", from, to);
	}
	else {
		Hanoi(num - 1, from, to, by);
		printf("����%d�� %c ���� %c�� �̵�\n", num, from, to);
		Hanoi(num - 1, by, from, to);
	}
}