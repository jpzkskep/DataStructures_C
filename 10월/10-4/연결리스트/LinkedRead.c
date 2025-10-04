#include <stdio.h>
#include <stdlib.h>
#pragma warning (disable:4996)

typedef struct _node {
	int data;
	struct _node* next;
} Node;

int main(void) {
	Node* head = NULL;
	// Node* tail = NULL; // tail 포인터는 머리에 노드를 추가하는 방식에서는 필수가 아니므로 삭제합니다.
	Node* cur = NULL;

	Node* newNode = NULL;
	int readData;

	//데이터를 입력받는 과정
	while (1) {
		printf("자연수 입력: ");
		scanf("%d", &readData);
		if (readData < 1) {
			break;
		}

		//노드의 추가과정 (머리에 추가하는 방식으로 변경)
		newNode = (Node*)malloc(sizeof(Node));
		newNode->data = readData;

		// --- 핵심 수정 부분 ---
		newNode->next = head; // 1. 새로운 노드가 현재의 head(첫번째 노드)를 가리키게 함
		head = newNode;       // 2. 이제 head는 새로운 노드를 가리키게 함 (새로운 노드가 첫번째가 됨)
		// ---------------------

		/* --- 기존의 잘못된 추가 로직 ---
		// if (tail == NULL) { // 삭제
		// 	tail = newNode; // 삭제
		// } // 삭제
		// else { // 삭제
		// 	head->next = newNode; // 삭제
		// } // 삭제
		// head = newNode; // 삭제 (역할이 완전히 변경됨)
		*/
	}
	printf("\n");

	//입력받은 데이터의 출력 과정 (head 부터 출력하도록 변경)
	printf("입력 받은 데이터의 전체출력!\n");
	// if (tail == NULL) { // head를 기준으로 확인하도록 변경
	if (head == NULL) {
		printf("저장된 자연수가 존재하지 않습니다.\n");
	}
	else {
		// cur = tail; // 시작점이 head 이므로 cur은 head부터 시작
		cur = head;
		// printf("%d ", cur->data); // 반복문 안에서 한 번에 처리하므로 삭제

		// while (cur->next != NULL) { // cur이 NULL이 아닐 동안 반복하도록 변경해야 마지막 노드까지 출력됨
		while (cur != NULL) {
			printf("%d ", cur->data);
			cur = cur->next;
		}
	}
	printf("\n\n");

	//메모리의 해체과정 (head 부터 해제하도록 변경)
	// if (tail == NULL) { // head 기준으로 변경
	if (head == NULL) {
		return 0;	//해체할 노드가 존재하지 않는다.
	}
	else {
		// Node* delNode = tail; // head 부터 시작
		// Node* delNextNode = tail->next; // head->next 부터 시작
		Node* delNode = head;
		Node* delNextNode = head->next;

		printf("%d를 삭제합니다.\n", delNode->data); // delNode->data로 변경
		free(delNode);	//첫 번째 노드 삭제

		while (delNextNode != NULL) {	//두 번째 이후 노드 삭제
			delNode = delNextNode;
			delNextNode = delNextNode->next;

			printf("%d를 삭제합니다.\n", delNode->data);
			free(delNode);
		}
	}
	return 0;
}