#pragma once

#include <stdio.h>
#include <stdlib.h>

typedef int LinkStackDataType;
typedef struct LinkStackNode
{
	LinkStackDataType data;
	struct LinkStackNode* next;
}LinkStackNode;

void LinkstackInit(LinkStackNode** phead); // ��ʽջ�ĳ�ʼ��
LinkStackNode* BuyNewLinkStackNode(LinkStackDataType val); // ����һ����ʽջ�Ľ�� ���������ַ
void LinkStackPushFront(LinkStackNode** pphead, int val); // ��ʽջ��ѹջ����
void LinkStackPopFront(LinkStackNode** pphead);  // ��ʽջ�ĳ�ջ����
void LinkStackGetTopElem(LinkStackNode* phead, LinkStackDataType* retData);  // ��ȡ��ʽջ��ջ��Ԫ��
void LinkStackPrint(LinkStackNode* phead);  // ��ӡջ�е�����
void LinkStackClear(LinkStackNode** pphead); // ���ջ�е�����
