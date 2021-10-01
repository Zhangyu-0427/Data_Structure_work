#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <stdlib.h>

// ��������ʽ���е������������
typedef int LqueueDatatype;

typedef struct queueNode
{
	LqueueDatatype data;
	struct queueNode* next;
}LqueueNode; // ��ʽ���еĽ��

typedef struct
{
	LqueueNode* head;
	LqueueNode* tail;
}LinkQueue; // ��ʽ����

LqueueNode* BuyNewQueueNode(LqueueDatatype x); // ����һ���½�㲢����
void LinkQueueInit(LinkQueue* q); // ��ʽ���еĳ�ʼ�� 
void LinkQueuePushBack(LinkQueue* q, LqueueDatatype x); // ��ʽ���е���Ӳ���
void LinkQueuePopFront(LinkQueue* q, LqueueDatatype* retData); // ��ʽ���еĳ��Ӳ���
void LinkQueuePrint(LinkQueue* q); // ��ӡ��ʽ����
LqueueDatatype LinkQueueGetTop(LinkQueue* q); // ��ȡ��ͷԪ��

int main()
{
	LinkQueue q;
	LqueueDatatype ret = 0;
	LinkQueueInit(&q);
	LinkQueuePushBack(&q, 5);
	LinkQueuePushBack(&q, 7);
	LinkQueuePushBack(&q, 1);
	LinkQueuePushBack(&q, 6);
	LinkQueuePushBack(&q, 2);
	LinkQueuePrint(&q);
	LinkQueuePopFront(&q, &ret);
	LinkQueuePrint(&q); 
	printf("%d\n", ret);
	return 0;
}

LqueueNode* BuyNewQueueNode(LqueueDatatype x) // ����һ���½�㲢����
{
	LqueueNode* newNode = (LqueueNode*)malloc(sizeof(LqueueNode));
	newNode->data = x;
	newNode->next = NULL;
	return newNode;
}
void LinkQueueInit(LinkQueue* q) // ��ʼ����ʽ����
{
	// ����һ����㽫����Ϊͷָ���βָ��Ľ��
	LqueueNode* newNode = (LqueueNode*)malloc(sizeof(LqueueNode));
	newNode->next = NULL;
	// ��ֵ����
	q->head = q->tail = newNode;
}

void LinkQueuePushBack(LinkQueue* q, LqueueDatatype x) // ��ʽ���е���Ӳ���
{
	LqueueNode* newNode = BuyNewQueueNode(x);
	q->tail->next = newNode;
	q->tail = newNode;
}

void LinkQueuePopFront(LinkQueue* q, LqueueDatatype* retData) // ��ʽ���еĳ��Ӳ���
{
	if (q->head == q->tail)
	{
		printf("����ʧ�ܣ�Ŀǰ������������");
		return;
	}
	LqueueNode* pHeadNow = q->head->next; // ���浱ǰ�����еĶ�ͷ���
	*retData = pHeadNow->data; // ���浱ǰ��ͷ��������

	// �������ɾ������
	q->head->next = pHeadNow->next;

	// ���ɾ���Ľ��Ϊ��ǰ���������һ�����ʱ
	// ��ʱ��β���Ҳ��Ҫ�ı�
	if (q->tail = pHeadNow)
	{
		q->tail = q->head;
	}
	free(pHeadNow);
}

void LinkQueuePrint(LinkQueue* q) // ��ӡ��ʽ����
{
	LqueueNode* phead = q->head->next;
	while (phead)
	{
		printf("%d->", phead->data);
		phead = phead->next;
	}
	printf("NULL\n");
}
LqueueDatatype LinkQueueGetTop(LinkQueue* q) // ��ȡ��ͷԪ��
{
	if (q->head == q->tail)
	{
		printf("��ǰ������������");
		exit(0);
	}

	return q->head->next->data;
}