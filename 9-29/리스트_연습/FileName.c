#include <stdio.h>
#include "ArrayList.h"
int main(void) {
	//ArrayList ���� �� �ʱ�ȭ
	List list;
	int data;
	ListInit(&list);
	int sum = 0;

	//���� 1���� 9���� ����Ʈ�� ����
	for (int i = 1; i <= 9; i++) {
		LInsert(&list, i);
	}
	//����Ʈ�� ����� ���� ���������� �����Ͽ� �� ���� ����Ͽ� ���

	if (LFirst(&list, &data)) {
		sum += data;
		printf("%d ", data);
		while (LNext(&list, &data)) {
			sum += data;
			printf("%d ", data);
		}
	}
	printf("\n\n");

	//����Ʈ ����� ���� 2�ǹ���� 3�ǹ�� ��� ����

	if (LFirst(&list, &data)) {
		if (data % 2 == 0 || data % 3 == 0) {
			LRemove(&list);
		}
		while (LNext(&list, &data)) {
			if (data % 2 == 0 || data % 3 == 0) {
				LRemove(&list);
			}
		}
	}
	//������ ����Ʈ�� ����� ������ ��ü ���

	if (LFirst(&list, &data)) {
		printf("%d ", data);
		while (LNext(&list, &data)) {
			printf("%d ", data);
		}
	}
	printf("\n\n");
	return 0;
}