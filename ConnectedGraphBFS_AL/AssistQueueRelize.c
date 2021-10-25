#define _CRT_SECURE_NO_WARNINGS 1

#include "ConnectedGraphBFS_ALStatement.h"

// ��ʼ����ʽ����
void InitLQueue(LQueue* queue) {
	queue->head = (LQueueNode*)malloc(sizeof(LQueueNode));
	if (queue->head == NULL) {
		exit(0);
	}
	queue->head->next = NULL;
	queue->tail = queue->head;
}

// ���е���Ӳ���
void push(LQueue* queue, VertexNode* val) {
	LQueueNode* newNode = (LQueueNode*)malloc(sizeof(LQueueNode));
	if (newNode == NULL) {
		exit(0);
	}
	newNode->val = val;
	newNode->next = NULL;

	queue->tail->next = newNode;
	queue->tail = newNode;
}

// ���еĳ��Ӳ���
void pop(LQueue* queue, VertexNode* retVertex) {
	if (QueueEmpty(queue)) {
		exit(0);
	}
	LQueueNode* pHead = queue->head->next;

	*retVertex = *(pHead->val);
	queue->head->next = pHead->next;
	
	if (queue->tail == pHead) {
		queue->tail = queue->head;
	}

	free(pHead);
}

// �ж϶����Ƿ�Ϊ��
int QueueEmpty(LQueue* queue) {
	if (queue->head == queue->tail) {
		return 1;
	}

	return 0;
}