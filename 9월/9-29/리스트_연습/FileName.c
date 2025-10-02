#include <stdio.h>
#include "ArrayList.h"
int main(void) {
	//ArrayList 생성 및 초기화
	List list;
	int data;
	ListInit(&list);
	int sum = 0;

	//정수 1부터 9까지 리스트에 저장
	for (int i = 1; i <= 9; i++) {
		LInsert(&list, i);
	}
	//리스트에 저장된 값을 순차적으로 참조하여 그 합을 계산하여 출력

	if (LFirst(&list, &data)) {
		sum += data;
		printf("%d ", data);
		while (LNext(&list, &data)) {
			sum += data;
			printf("%d ", data);
		}
	}
	printf("\n\n");

	//리스트 저장된 값중 2의배수와 3의배수 모두 삭제

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
	//삭제후 리스트에 저장된 데이터 전체 출력

	if (LFirst(&list, &data)) {
		printf("%d ", data);
		while (LNext(&list, &data)) {
			printf("%d ", data);
		}
	}
	printf("\n\n");
	return 0;
}