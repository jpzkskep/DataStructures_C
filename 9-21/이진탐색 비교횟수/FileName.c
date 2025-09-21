#include <stdio.h>

int Bsearch(int ar[], int len, int target) {
	int first = 0;
	int last = len - 1;
	int mid;
	int opCount = 0;	//비교연산 횟수 기록
	while (first <= last) {
		mid = (first + last) / 2;
		if (target == ar[mid]) {
			return mid;
		}
		else {
			if (target > ar[mid]) {
				first = mid + 1;
			}
			else {
				last = mid - 1;
			}
		}
		opCount += 1;
	}
	printf("비교연산횟수: %d\n", opCount);	//탐색 실패시 연산 횟수 출력
	return -1;
}

int main(void) {
	int arr1[500] = { 0 };
	int arr2[5000] = { 0 };
	int arr3[50000] = { 0 };
	int idx;
	idx = Bsearch(arr1, sizeof(arr1) / sizeof(int), 1);
	if (idx == -1) {
		printf("탐색 실패\n");
	}
	else {
		printf("타겟 저장 인덱스:%d\n", idx);
	}
	idx = Bsearch(arr2, sizeof(arr2) / sizeof(int), 1);
	if (idx == -1) {
		printf("탐색 실패\n");
	}
	else {
		printf("타겟 저장 인덱스:%d\n", idx);
	}
	idx = Bsearch(arr3, sizeof(arr3) / sizeof(int), 1);
	if (idx == -1) {
		printf("탐색 실패\n");
	}
	else {
		printf("타겟 저장 인덱스:%d\n", idx);
	}
	return 0;
}