#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>


typedef char BTDataType;

typedef struct BinaryTreeNode
{
	struct BinaryTreeNode* LeftNode;
	struct BinaryTreeNode* RightNode;
	BTDataType val;
}BTNode;

// ������ʽ���еĽ��
typedef BTNode* LQueueData; // �����������ĵ�ַ��Ϊ���е�ֵ

typedef struct LQueueNode
{
	LQueueData val;
	struct LQueueNode* next;
}LQueueNode;

// ������ʽ����
typedef struct
{
	LQueueNode* Head;
	LQueueNode* Tail;
}LinkQueue;

// �������н�㲢������ָ��
LQueueNode* BuyNewLqueueNode(LQueueData val) {
	LQueueNode* newNode = (LQueueNode*)malloc(sizeof(LQueueNode));
	if (newNode == NULL) {
		exit(0);
	}

	newNode->val = val;
	newNode->next = NULL;
}
// ��ʼ����ʽ����
void InitLinkQueue(LinkQueue* s) {
	LQueueNode* pHead = (LQueueNode*)malloc(sizeof(LQueueNode));
	if (pHead == NULL) {
		exit(0);
	}
	pHead->next = NULL;

	s->Head = pHead;
	s->Tail = pHead;
}
// �����п�
int LQueueEmpty(LinkQueue* s) {
	if (s->Head == s->Tail) {
		return 1;
	}
	return 0;
}
// ���
void LQueuePush(LinkQueue* s, LQueueData val) {
	LQueueNode* newNode = BuyNewLqueueNode(val);
	if (newNode == NULL) {
		exit(0);
	}
	(s->Tail)->next = newNode;
	s->Tail = newNode;
}
// ���Ӳ���
void LQueuePop(LinkQueue* s, LQueueNode* retNode) {
	if (LQueueEmpty(s)) {
		return;
	}

	LQueueNode* pHead = s->Head->next;
	*retNode = *pHead;
	s->Head->next = pHead->next;
	if (pHead == s->Tail) {
		s->Tail = s->Head;
	}
}

void TreeSize(BTNode* root, int* size) {
	if (root == NULL) {
		return;
	}

	(*size)++;
	TreeSize(root->LeftNode, size);
	TreeSize(root->RightNode, size);

	// ����:: ---
	//return root == NULL ? 0 : TreeSize(root-LeftNode) + TreeSize(root->Right) + 1;
}

// ������Ҷ�ӵĸ���

int TreeLeafSize(BTNode* root) {
	/*return (root->LeftNode == NULL && root->RightNode == NULL) ? 1 : TreeLeafSize(root->LeftNode)
		+ TreeLeafSize(root->RightNode);*/

	if (root == NULL) {
		return 0;
	}

	if (root->LeftNode == NULL && root->RightNode == NULL) {
		return 1;
	}

	return TreeLeafSize(root->LeftNode) + TreeLeafSize(root->RightNode);
}

// ��α��� ������ȱ��� һ���õ�����
void LevelOrder(BTNode* root) {
	LinkQueue q;
	InitLinkQueue(&q);
	if (root) {
		LQueuePush(&q, root);
	}

	while (!LQueueEmpty(&q)) {
		LQueueNode retNode;
		LQueuePop(&q, &retNode);
		printf("%c", retNode.val->val);

		if ((&retNode)->val->LeftNode) {
			LQueuePush(&q, (&retNode)->val->LeftNode);
		}

		if ((&retNode)->val->RightNode) {
			LQueuePush(&q, (&retNode)->val->RightNode);
		}
	}

	printf("\n");
}


int main()
{
	BTNode* A = (BTNode*)malloc(sizeof(BTNode));
	A->LeftNode = NULL;
	A->RightNode = NULL;
	A->val = 'A';

	BTNode* B = (BTNode*)malloc(sizeof(BTNode));
	B->LeftNode = NULL;
	B->RightNode = NULL;
	B->val = 'B';

	BTNode* C = (BTNode*)malloc(sizeof(BTNode));
	C->LeftNode = NULL;
	C->RightNode = NULL;
	C->val = 'C';

	BTNode* D = (BTNode*)malloc(sizeof(BTNode));
	D->LeftNode = NULL;
	D->RightNode = NULL;
	D->val = 'D';

	BTNode* E = (BTNode*)malloc(sizeof(BTNode));
	E->LeftNode = NULL;
	E->RightNode = NULL;
	E->val = 'E';

	A->LeftNode = B;
	A->RightNode = C;
	B->LeftNode = D;
	B->RightNode = E;

	int sizeA = 0;
	TreeSize(A, &sizeA);
	printf("\nA TreeSize is %d\n", sizeA);

	int sizeB = 0;
	TreeSize(B, &sizeB);
	printf("B TreeSize is %d\n", sizeB);

	printf("A TreeLeafSize is %d\n", TreeLeafSize(A));
	printf("B TreeLeafSize is %d\n", TreeLeafSize(B));

	LevelOrder(A);
	LevelOrder(C);
	return 0;
}