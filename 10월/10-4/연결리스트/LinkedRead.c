#include <stdio.h>
#include <stdlib.h>
#pragma warning (disable:4996)

typedef struct _node {
	int data;
	struct _node* next;
} Node;

int main(void) {
	Node* head = NULL;
	// Node* tail = NULL; // tail �����ʹ� �Ӹ��� ��带 �߰��ϴ� ��Ŀ����� �ʼ��� �ƴϹǷ� �����մϴ�.
	Node* cur = NULL;

	Node* newNode = NULL;
	int readData;

	//�����͸� �Է¹޴� ����
	while (1) {
		printf("�ڿ��� �Է�: ");
		scanf("%d", &readData);
		if (readData < 1) {
			break;
		}

		//����� �߰����� (�Ӹ��� �߰��ϴ� ������� ����)
		newNode = (Node*)malloc(sizeof(Node));
		newNode->data = readData;

		// --- �ٽ� ���� �κ� ---
		newNode->next = head; // 1. ���ο� ��尡 ������ head(ù��° ���)�� ����Ű�� ��
		head = newNode;       // 2. ���� head�� ���ο� ��带 ����Ű�� �� (���ο� ��尡 ù��°�� ��)
		// ---------------------

		/* --- ������ �߸��� �߰� ���� ---
		// if (tail == NULL) { // ����
		// 	tail = newNode; // ����
		// } // ����
		// else { // ����
		// 	head->next = newNode; // ����
		// } // ����
		// head = newNode; // ���� (������ ������ �����)
		*/
	}
	printf("\n");

	//�Է¹��� �������� ��� ���� (head ���� ����ϵ��� ����)
	printf("�Է� ���� �������� ��ü���!\n");
	// if (tail == NULL) { // head�� �������� Ȯ���ϵ��� ����
	if (head == NULL) {
		printf("����� �ڿ����� �������� �ʽ��ϴ�.\n");
	}
	else {
		// cur = tail; // �������� head �̹Ƿ� cur�� head���� ����
		cur = head;
		// printf("%d ", cur->data); // �ݺ��� �ȿ��� �� ���� ó���ϹǷ� ����

		// while (cur->next != NULL) { // cur�� NULL�� �ƴ� ���� �ݺ��ϵ��� �����ؾ� ������ ������ ��µ�
		while (cur != NULL) {
			printf("%d ", cur->data);
			cur = cur->next;
		}
	}
	printf("\n\n");

	//�޸��� ��ü���� (head ���� �����ϵ��� ����)
	// if (tail == NULL) { // head �������� ����
	if (head == NULL) {
		return 0;	//��ü�� ��尡 �������� �ʴ´�.
	}
	else {
		// Node* delNode = tail; // head ���� ����
		// Node* delNextNode = tail->next; // head->next ���� ����
		Node* delNode = head;
		Node* delNextNode = head->next;

		printf("%d�� �����մϴ�.\n", delNode->data); // delNode->data�� ����
		free(delNode);	//ù ��° ��� ����

		while (delNextNode != NULL) {	//�� ��° ���� ��� ����
			delNode = delNextNode;
			delNextNode = delNextNode->next;

			printf("%d�� �����մϴ�.\n", delNode->data);
			free(delNode);
		}
	}
	return 0;
}