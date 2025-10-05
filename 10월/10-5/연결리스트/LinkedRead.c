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

	//���� ��� ���� �� �ʱ�ȭ
	head = (Node*)malloc(sizeof(Node));
	head->next = NULL;
	tail = head;

	while (1) {
		printf("�ڿ��� �Է�:");
		scanf("%d", &readData);
		if (readData < 1) {
			break;
		}
		
		//����� �߰�����
		newNode = (Node*)malloc(sizeof(Node));
		newNode->data = readData;
		newNode->next = NULL;

		//���̳�带 Ȱ���� ��� �߰�
		tail->next = newNode;
		tail = newNode;
	}
	printf("\n");

	printf("�Է� ���� �������� ��ü���\n");

	if (head->next == NULL) {
		printf("����� �ڿ����� �������� �ʽ��ϴ�\n");
	}
	else {

		//cur�������� ���� ��� �������� ����
		cur = head->next;
		while (cur != NULL) {
			printf("%d ", cur->data);
			cur = cur->next;
		}
	}
	printf("\n\n");

	//�޸� ��ü
	Node* delNode = head;
	Node* delNextNode = NULL;

	while (delNode != NULL) {
		delNextNode = delNode->next;

		if (delNode != head) {
			printf("%d�� �����մϴ�\n", delNode->data);
		}
		free(delNode);
		delNode = delNextNode;
	}
	return 0;
}