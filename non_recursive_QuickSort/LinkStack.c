#define _CRT_SECURE_NO_WARNINGS 1
#include "LinkStack.h"

void LinkstackInit(LinkStackNode** phead) // ��ʽջ�ĳ�ʼ��
{
	*phead = NULL;
}

LinkStackNode* BuyNewLinkStackNode(LinkStackDataType val) // ����һ����ʽջ�Ľ�� ���������ַ
{
	LinkStackNode* newNode = (LinkStackNode*)malloc(sizeof(LinkStackNode));
	if (newNode == NULL)
	{
		printf("�����ڴ�ʧ��");
		exit(0);
	}
	newNode->data = val;
	newNode->next = NULL;
	return newNode;
}

void LinkStackPushFront(LinkStackNode** pphead, int val) // ��ʽջ��ѹջ����
{
	LinkStackNode* newNode = BuyNewLinkStackNode(val);
	if (*pphead == NULL)
	{
		*pphead = newNode;
	}
	else
	{
		//������ͷ�弴Ϊ��ʽջ��ѹջ
		newNode->next = *pphead;
		*pphead = newNode;
	}
}

void LinkStackPopFront(LinkStackNode** pphead)  // ��ʽջ�ĳ�ջ����
{
	if (*pphead == NULL)
	{
		printf("ջ�������ݣ��޷���ջ\n");
		exit(0);
	}

	LinkStackNode* nextNode = (*pphead)->next;
	//�������ͷɾ��Ϊ��ʽջ�ĳ�ջ����
	free(*pphead);
	*pphead = nextNode;
}

void LinkStackGetTopElem(LinkStackNode* phead, LinkStackDataType* retData)  // ��ȡ��ʽջ��ջ��Ԫ��
{
	if (phead == NULL)
	{
		printf("ջ�������ݣ��޷�����Ԫ��\n");
		return;
	}
	else
	{
		*retData = phead->data;
	}
}

void LinkStackPrint(LinkStackNode* phead)  // ��ӡջ�е�����
{
	if (phead == NULL)
	{
		printf("ջ�ռ���û������\n");
	}
	else
	{
		printf("ջ��:->");
		while (phead != NULL)
		{
			printf("%d ", phead->data);
			phead = phead->next;
			if(phead == NULL)
				printf("<-ջ��\n");
		}
	}
}

void LinkStackClear(LinkStackNode** pphead) // ���ջ�е�����
{
	LinkStackNode* delete_tmp = NULL;
	while (*pphead)
	{
		delete_tmp = *pphead;
		(*pphead) = (*pphead)->next;
		free(delete_tmp);
	}
	*pphead = NULL;
}