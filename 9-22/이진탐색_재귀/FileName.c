#include <stdio.h>

int Bsearch(int ar[], int first, int last, int target);

int main(void) {
	int arr[] = { 1,3,5,7,9 };
	int idx;
	idx = Bsearch(arr, 0, sizeof(arr) / sizeof(int) - 1, 7);
	if (idx == -1) {
		printf("Å½»ö ½ÇÆÐ\n");
	}
	else {
		printf("Å¸°Ù ÀúÀå ÀÎµ¦½º:%d\n", idx);
	}
	idx = Bsearch(arr, 0, sizeof(arr) / sizeof(int) - 1, 4);
	if (idx == -1) {
		printf("Å½»ö ½ÇÆÐ\n");
	}
	else {
		printf("Å¸°Ù ÀúÀå ÀÎµ¦½º:%d\n", idx);
	}
	return 0;
}

int Bsearch(int ar[], int first, int last, int target) {
	int mid;
	if (first > last) {
		return -1;	//-1¹ÝÈ¯Àº Å½»ö ½ÇÆÐ
	}
	mid = (first + last) / 2;
	if (ar[mid] == target) {
		return mid;
	}
	else if (target < ar[mid]) {
		return Bsearch(ar, first, mid - 1, target);
	}
	else {
		return Bsearch(ar, mid + 1, last, target);
	}
}