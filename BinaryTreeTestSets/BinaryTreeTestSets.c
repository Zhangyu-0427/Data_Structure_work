#define _CRT_SECURE_NO_WARNINGS 1
typedef char BinTreeData;

#include <stdio.h>
#include <stdlib.h>

// ����������Ľ��ṹ������ṹ��
typedef struct BinaryTreeNode {
	BinTreeData val; // ������

	// ָ����������������ָ����
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;

}BTNode;

typedef struct SeqStack {
	BTNode* top;
	BTNode* bottom;
	int SeqStackCapacity;
}SqStack; // ����˳��ջ�Ĵ洢�ṹ

typedef struct QueueNode {
	BTNode* val;
	struct QueueNode* next;
}QNode;

typedef struct {
	QNode* head;
	QNode* tail;
}LQueue;

/*-----------------��������ʵ�ֲ������--------------------*/
//  ��ʼ������
void InitQueue(LQueue* q);

//  ��Ӳ���
void QueuePush(LQueue* q, BTNode* val);

//  ����һ�����н��
QNode* BuyNewNode(BTNode* val);

//  ���Ӳ���
void QueuePop(LQueue* q, QNode* ret);

//  �ж϶ӿ�
int QueueEmpty(LQueue* q);

/*----------����ջʵ�ַǵݹ����������----------------*/
//  ��ʼ��˳��ջ
void InitStack(SqStack* s);

//  ��ջ����
void StackPush(SqStack* s, BTNode* data);

//  ��ջ����
void StackPop(SqStack* s);

//  �ж�ջ��
int StackEmpty(SqStack* s);

//  ��ȡջ��Ԫ��
BTNode* StackGetTop(SqStack* s);


/*---------------�������Ĳ�����--------------------*/
//  ����ǰ�����й���������
BTNode* PrevOrderCreateTree(char* str, int* index);

//  ǰ�����������--�ݹ�
void PrevOrderByRecursion(BTNode* root);

//  �������������--�ݹ�
void InOrderByRecursion(BTNode* root);

//  �������������--�ݹ�
void PostOrderByRecursion(BTNode* root);

//  ǰ�����������--�ǵݹ�
void PrevOrderNoRecursion(BTNode* root);

//  �������������--�ǵݹ�
void InOrderNoRecursion(BTNode* root);

//  �����������Ҷ�ӽ��ĸ���
int BTreeLeafSize(BTNode* root);

//  ����������������� -- Ҳ�ƶ����������
int maxDepthTree(BTNode* root);

//  �������Ĳ������
void LevelOrder(BTNode* root);

int main() {
	/*
	���ԵĶ�����Ϊ��
					A
				   / \
				  B   C
				   \ / \
				   F D E
				  / \
				 G   H
	�ö�������ǰ������Ϊ��AB#FG##H##CD##E##
	*/

	char str[100] = "AB#FG##H##CD##E##";
	int i = 0;

	// ���� root ���չ����ɹ��Ķ�����������ָ��
	BTNode* root = PrevOrderCreateTree(str, &i);
	printf("���ԵĶ�����Ϊ��\n");
	printf("   A   \n");
	printf("  / \\\n");
	printf(" B   C\n");
	printf("  \\ / \\\n");
	printf("  F D E\n");
	printf(" / \\\n");
	printf("G   H\n");
	printf("1.ǰ�����-�ݹ飺");
	PrevOrderByRecursion(root);
	printf("\n\n2.�������-�ݹ飺");
	InOrderByRecursion(root);
	printf("\n\n3.�������-�ݹ飺");
	PostOrderByRecursion(root);
	printf("\n\n4.ǰ�����-�ǵݹ飺");
	PrevOrderNoRecursion(root);
	printf("\n5.�������-�ǵݹ飺");
	InOrderNoRecursion(root);
	int leafCnt = BTreeLeafSize(root);
	printf("\n6.����Ҷ�ӽ������%d\n", leafCnt);
	int treeDepth = maxDepthTree(root);
	printf("\n7. ������ȣ�%d\n", treeDepth);
	printf("\n8. ���Ĳ��������");
	LevelOrder(root);

	printf("\n\n");
	return 0;
}

//  ����ǰ�����й���������
BTNode* PrevOrderCreateTree(char* str, int* pi) {
	if (str[*pi] == '#') {
		(*pi)++;
		return NULL;
	}

	BTNode* root = (BTNode*)malloc(sizeof(BTNode));
	if (root == NULL) {
		printf("�ڴ����ʧ��\n");
		exit(0);
	}

	root->val = str[*pi];
	(*pi)++;
	root->left  = PrevOrderCreateTree(str, pi);
	root->right = PrevOrderCreateTree(str, pi);

	return root;
}

//  ǰ�����������--�ݹ�
void PrevOrderByRecursion(BTNode* root) {
	if (root == NULL) {
		return;
	}
	printf("%c ", root->val);
	PrevOrderByRecursion(root->left);
	PrevOrderByRecursion(root->right);
}

//  �������������--�ݹ�
void InOrderByRecursion(BTNode* root) {
	if (root == NULL) {
		return;
	}
	InOrderByRecursion(root->left);
	printf("%c ", root->val);
	InOrderByRecursion(root->right);
}

//  �������������--�ݹ�
void PostOrderByRecursion(BTNode* root) {
	if (root == NULL) {
		return;
	}
	PostOrderByRecursion(root->left);
	PostOrderByRecursion(root->right);
	printf("%c ", root->val);
}

//  ǰ�����������--�ǵݹ�
void PrevOrderNoRecursion(BTNode* root) {
	SqStack s;
	InitStack(&s);
	StackPush(&s, root);
	BTNode* cur = (BTNode*)malloc(sizeof(BTNode));
	while (!StackEmpty(&s)) {
		cur = StackGetTop(&s);
		StackPop(&s);
		if (cur != NULL) {
			printf("%c ", cur->val);
		}
		else {
			continue;
		}
		BTNode* right = cur->right;
		BTNode* left = cur->left;
		if (right) {
			StackPush(&s, right);
		}
		if (left) {
			StackPush(&s, left);
		}
	}
	printf("\n");
}

//  �������������--�ǵݹ�
void InOrderNoRecursion(BTNode* root) {
	SqStack s;
	InitStack(&s);
	BTNode* cur = root;
	while (cur != NULL || !StackEmpty(&s)) {
		if (cur) {
			StackPush(&s, cur);
			cur = cur->left;
		}
		else{
			cur = StackGetTop(&s);
			StackPop(&s);
			printf("%c ", cur->val);
			cur = cur->right;
		}
	}
	printf("\n");
}

//  ��ʼ��˳��ջ
void InitStack(SqStack* s) {
	s->bottom = (BTNode*)malloc(sizeof(BTNode) * 100);
	if (s->bottom == NULL) {
		exit(0);
	}
	s->top = s->bottom;
	s->SeqStackCapacity = 100;
}

//  ��ջ����
void StackPush(SqStack* s, BTNode* data) {
	if (s->top - s->bottom == s->SeqStackCapacity) {
		exit(0);
	}
	*(s->top) = *data;
	s->top++;
}

//  ��ջ����
void StackPop(SqStack* s) {
	if (s->top == s->bottom) {
		exit(0);
	}
	s->top--;
}

//  �ж�ջ��
int StackEmpty(SqStack* s) {
	if (s->top == s->bottom) {
		return 1;
	}
	return 0;
}

//  ��ȡջ��Ԫ��
BTNode* StackGetTop(SqStack* s) {
	if (s->top == s->bottom) {
		exit(0);
	}

	return s->top - 1;
}

//  �����������Ҷ�ӽ��ĸ���
int BTreeLeafSize(BTNode* root) {
	if (root == NULL) {
		return 0;
	}
	
	return (root->left == NULL && root->right == NULL) ? 1 : BTreeLeafSize(root->left)
		+ BTreeLeafSize(root->right);
}

//  �����������������
int maxDepthTree(BTNode* root) {
	if (root == NULL) {
		return 0;
	}

	int leftDepth = maxDepthTree(root->left);
	int rightDepth = maxDepthTree(root->right);
	return (leftDepth > rightDepth) ? leftDepth + 1 :
		rightDepth + 1;
}

//  ��ʼ������
void InitQueue(LQueue* q) {
	QNode* pHead = (QNode*)malloc(sizeof(QNode*));
	if (pHead == NULL) {
		exit(0);
	}
	pHead->next = NULL;
	q->head = pHead;
	q->tail = pHead;
}

//  ��Ӳ���
void QueuePush(LQueue* q, BTNode* val) {
	QNode* newNode = BuyNewNode(val);
	q->tail->next = newNode;
	q->tail = newNode;
}

//  ����һ�����
QNode* BuyNewNode(BTNode* val) {
	QNode* newNode = (QNode*)malloc(sizeof(QNode));
	if (newNode == NULL) {
		exit(0);
	}
	newNode->val = val;
	newNode->next = NULL;

	return newNode;
}

//  ���Ӳ���
void QueuePop(LQueue* q, QNode* ret) {
	if (QueueEmpty(q)) {
		exit(0);
	}

	QNode* pHead = q->head->next;
	*ret = *pHead;
	q->head->next = pHead->next;
	if (pHead == q->tail) {
		q->tail = q->head;
	}
}

//  �ж϶ӿ�
int QueueEmpty(LQueue* q) {
	if (q->head == q->tail) {
		return 1;
	}

	return 0;
}

//  �������Ĳ������
void LevelOrder(BTNode* root) {
	LQueue q;
	InitQueue(&q);
	if (root) {
		QueuePush(&q, root);
	}

	while (!QueueEmpty(&q)) {
		QNode cur;
		QueuePop(&q, &cur);
		printf("%c ", (&cur)->val->val);

		if ((&cur)->val->left) {
			QueuePush(&q, (&cur)->val->left);
		}
		if ((&cur)->val->right) {
			QueuePush(&q, (&cur)->val->right);
		}
	}
}