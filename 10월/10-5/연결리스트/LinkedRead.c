#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

typedef struct _node {
	int data;
	struct _node* next;
} Node;

int main(void) {
	Node* head = NULL;
	Node* tail = NULL;
	Node* cur = NULL;

	Node* newNode = NULL;
	int readData;

	//더미 노드 생성 및 초기화
	head = (Node*)malloc(sizeof(Node));
	head->next = NULL;
	tail = head;

	while (1) {
		printf("자연수 입력:");
		scanf("%d", &readData);
		if (readData < 1) {
			break;
		}
		
		//노드의 추가과정
		newNode = (Node*)malloc(sizeof(Node));
		newNode->data = readData;
		newNode->next = NULL;

		//더미노드를 활용한 노드 추가
		tail->next = newNode;
		tail = newNode;
	}
	printf("\n");

	printf("입력 받은 데이터의 전체출력\n");

	if (head->next == NULL) {
		printf("저장된 자연수가 존재하지 않습니다\n");
	}
	else {

		//cur시작점을 더미 노드 다음으로 설정
		cur = head->next;
		while (cur != NULL) {
			printf("%d ", cur->data);
			cur = cur->next;
		}
	}
	printf("\n\n");

	//메모리 해체
	Node* delNode = head;
	Node* delNextNode = NULL;

	while (delNode != NULL) {
		delNextNode = delNode->next;

		if (delNode != head) {
			printf("%d를 삭제합니다\n", delNode->data);
		}
		free(delNode);
		delNode = delNextNode;
	}
	return 0;
}