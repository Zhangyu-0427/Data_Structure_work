#pragma once

#include "ConnectedGraphBFS_ALStatement.h"
typedef struct LQueueNode {
	VertexNode* val; // �����д��ͼ�еĶ���
	struct LQueueNode* next;
}LQueueNode;

typedef struct {
	LQueueNode* head;
	LQueueNode* tail;
}LQueue;

void InitLQueue(LQueue* queue); // ��ʼ����ʽ����

void push(LQueue* queue, VertexNode* val); // ���е���Ӳ���

void pop(LQueue* queue, VertexNode* retVertex); // ���еĳ��Ӳ���

int QueueEmpty(LQueue* queue); // �ж϶����Ƿ�Ϊ��
