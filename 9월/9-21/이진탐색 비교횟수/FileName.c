#include <stdio.h>

int Bsearch(int ar[], int len, int target) {
	int first = 0;
	int last = len - 1;
	int mid;
	int opCount = 0;	//�񱳿��� Ƚ�� ���
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
	printf("�񱳿���Ƚ��: %d\n", opCount);	//Ž�� ���н� ���� Ƚ�� ���
	return -1;
}

int main(void) {
	int arr1[500] = { 0 };
	int arr2[5000] = { 0 };
	int arr3[50000] = { 0 };
	int idx;
	idx = Bsearch(arr1, sizeof(arr1) / sizeof(int), 1);
	if (idx == -1) {
		printf("Ž�� ����\n");
	}
	else {
		printf("Ÿ�� ���� �ε���:%d\n", idx);
	}
	idx = Bsearch(arr2, sizeof(arr2) / sizeof(int), 1);
	if (idx == -1) {
		printf("Ž�� ����\n");
	}
	else {
		printf("Ÿ�� ���� �ε���:%d\n", idx);
	}
	idx = Bsearch(arr3, sizeof(arr3) / sizeof(int), 1);
	if (idx == -1) {
		printf("Ž�� ����\n");
	}
	else {
		printf("Ÿ�� ���� �ε���:%d\n", idx);
	}
	return 0;
}