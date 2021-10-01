#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 10

typedef int SqStackData;
typedef struct
{
	SqStackData* top;
	SqStackData* base;
	int Size;
}SqStack;

void SqStackInit(SqStack* s); //  ˳��ջ�ĳ�ʼ��
void SqStackPushBack(SqStack* s, SqStackData x); // ˳��ջ��ѹջ
void SqStackPopBack(SqStack* s, SqStackData* retData); // ˳��ջ�ĳ�ջ

int main()
{
	SqStack s;
	SqStackInit(&s);

	int reception_Num = 0, remainDer = 0, tmp_Num = 0;
	scanf("%d", &reception_Num);
	tmp_Num = reception_Num;
	while (reception_Num)
	{
		remainDer = reception_Num % 8;
		SqStackPushBack(&s, remainDer); // ��ÿһ��ȡ��ĵĽ��ѹ��ջ��
		reception_Num /= 8;
	}
	printf("%d�İ˽���Ϊ��", tmp_Num);
	while ((&s)->top != (&s)->base)
	{
		SqStackData ret = 0;
		SqStackPopBack(&s, &ret);
		printf("%d", ret);
	}

	return 0;
}


void SqStackInit(SqStack* s)
{
	s->base = (SqStackData*)malloc(sizeof(SqStack) * MAX_STACK_SIZE);
	if (s->base == NULL)
	{
		printf("�����ڴ�ʧ��");
		exit(0);
	}
	s->top = s->base; // ��ʼ����ջ�������� Ϊ��ջ״̬
	s->Size = 0;
}


void SqStackPushBack(SqStack* s, SqStackData x)
{
	if (s->top - s->base == MAX_STACK_SIZE) // ջ����
		exit(0);

	*(s->top) = x;
	s->top++;
	s->Size++;
}

void SqStackPopBack(SqStack* s, SqStackData* retData)
{
	if (s->top == s->base) // ��ջ״̬�����ݿɳ�ջ
		exit(0);

	*retData = *(s->top-1);
	s->top--;
	s->Size--;
}