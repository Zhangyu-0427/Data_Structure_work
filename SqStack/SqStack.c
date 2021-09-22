#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

#define MAX_SZIE_SqStack 8  //����˳��ջ���������
typedef int SqStackDataType;
typedef struct
{
	SqStackDataType* top; //˳��ջ��ջ��
	SqStackDataType* base;//˳��ջ��ջ��
	int SqStackSize;      //��¼˳��ջ������
}SqStack;         //Sequence Stack ���� ˳��ջ

void SqStackInit(SqStack* s);                                    // ˳��ջ�ĳ�ʼ��
void SqStackPushBack(SqStack* s, SqStackDataType x);             // ˳��ջ����ջ����
void SqStackPopBack(SqStack* s, SqStackDataType* retTopElem);    // ˳��ջ�ĳ�ջ����
void SqStackGetTopElem(SqStack* s, SqStackDataType* retTopElem); // ��ȡ˳��ջ��ջ��Ԫ��
void SqStackPrint(SqStack* s);                                   // ��ӡջԪ��
int main()
{
	SqStack s;
	SqStackInit(&s);
	SqStackPushBack(&s, 5);
	SqStackPushBack(&s, 2);
	SqStackPushBack(&s, 9);
	SqStackPushBack(&s, 4);
	SqStackPushBack(&s, 1);
	SqStackPrint(&s);
	int top0;
	SqStackGetTopElem(&s, &top0);
	printf("top:%d\n", top0);
	int top1;
	SqStackPopBack(&s, &top1);
	printf("��ջԪ��:%d\n", top1);
	SqStackPrint(&s);
	SqStackPushBack(&s, 0);
	SqStackPrint(&s);
	SqStackPopBack(&s, &top1);
	printf("��ջԪ��:%d\n", top1);
	SqStackPopBack(&s, &top1);
	printf("��ջԪ��:%d\n", top1);
	SqStackPopBack(&s, &top1);
	printf("��ջԪ��:%d\n", top1);
	SqStackPopBack(&s, &top1);
	printf("��ջԪ��:%d\n", top1);
	SqStackPopBack(&s, &top1);
	printf("��ջԪ��:%d\n", top1);

	SqStackPushBack(&s, 56);
	SqStackPushBack(&s, 67);
	SqStackPushBack(&s, 75);
	SqStackPrint(&s);
	return 0;
}


void SqStackInit(SqStack* s)
{
	s->base = (SqStackDataType*)malloc(MAX_SZIE_SqStack * sizeof(SqStackDataType));
	if (s->base == NULL)
	{
		printf("�����ڴ�ʧ��");
		exit(0);
	}

	s->top = s->base; //��ʼ����ջ��û��Ԫ��
	s->SqStackSize = MAX_SZIE_SqStack;
}
void SqStackPushBack(SqStack* s, SqStackDataType x)
{
	if (s->top - s->base == s->SqStackSize)  // ջ�ռ�����
	{
		printf("ջ�ռ�����");
		exit(0);
	}

	*(s->top++) = x;// ��ȡ��ջ��ָ�� �ٽ����� ���ֵ
}
void SqStackPopBack(SqStack* s, SqStackDataType* retTopElem)
{
	if (s->top == s->base)  //ջΪ��
	{
		printf("ջΪ�գ��޷���ջ");
		exit(0);
	}

	*retTopElem = *(s->top-1);
	s->top--;
	if (s->top == s->base)
	{
		printf("(%d��Ϊջ�����һ��Ԫ��)\n",*retTopElem);
	}
}
void SqStackGetTopElem(SqStack* s, SqStackDataType* retTopElem)
{
	if (s->base == s->top)
	{
		printf("ջΪ�գ��޷���ȡջ��Ԫ��");
		exit(0);
	}

	*retTopElem = *(s->top-1);
}
void SqStackPrint(SqStack* s)
{
	if (s->base == s->top)
	{
		printf("ջΪ�գ�û��Ԫ�ؿɴ�ӡ");
		exit(0);
	}
	SqStackDataType* base_tmp = s->base;
	printf("ջ��-> ");
	while (base_tmp != s->top)
	{
		printf("%d ", *base_tmp);
		base_tmp++;
	}
	printf("<-ջ��\n");
}