#define _CRT_SECURE_NO_WARNINGS 1
#define MAX_SQSTACK_SIZE 50

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef char SqStackData;
typedef int SqStackDataOperNum;
typedef struct
{
	SqStackData* top;
	SqStackData* base;
	int MaxSqStackCapacity;
}SqStack; // �ַ���ջ - ��������
typedef struct
{
	SqStackDataOperNum* top;
	SqStackDataOperNum* base;
	int MaxNumSize;
}SqOperNumStack; // ����ջ - ��Ų�����


void SqStackInit(SqStack* s); // ˳��ջ�ĳ�ʼ��
void SqStackPushBack(SqStack* s, SqStackData x); // ˳��ջ����ջ
void SqStackPopBack(SqStack* s, SqStackData* retData); // ˳��ջ�ĳ�ջ
SqStackData SqStackGetTop(SqStack* s); // ��ȡջ��Ԫ��
void SqStackRemovetop(SqStack* s); // ɾ��ջ��Ԫ��

void SqOperNumStackInit(SqOperNumStack* s); // ��ʼ��
void SqOperNumStackPushBack(SqOperNumStack* s, SqStackDataOperNum x); // ˳��ջ����ջ
void SqOperNumStackPopBack(SqOperNumStack* s, SqStackDataOperNum* retData); // ˳��ջ�ĳ�ջ
void SqOperNumStackRemovetop(SqOperNumStack* s); // ɾ��ջ��Ԫ��

char assertPriority(SqStackData operator0, SqStackData operator1); // �ж����������������ȼ�
SqStackDataOperNum fourOperations(SqStackDataOperNum a, SqStackData operator, SqStackDataOperNum b); // ��Ԫ������������

int main()
{
	SqStack s;
	SqStackData res = 0;
	
	SqStackInit(&s);
	// ��ջ����
	SqStackPushBack(&s, 'h');
	SqStackPushBack(&s, 'p');
	SqStackPushBack(&s, 't');
	SqStackPushBack(&s, 'e');
	SqStackPushBack(&s, 'l');
	SqStackPushBack(&s, 'b');
	// ɾ��ջ��Ԫ��
	SqStackRemovetop(&s);
	SqStackRemovetop(&s);
	while ((&s)->top != (&s)->base)
	{
		SqStackPopBack(&s, &res);
		printf("%c ", res);
	}
	printf("\n");
	// ���϶�ջ�Ĳ��Գɹ� 
	
	// ������������ʽ��ֵ���㷨
	SqStackData str[] = "(7*5)+9*3-2/2"; // (7*5) + 9 * 3 - 2 = 61
	int strLen = strlen(str), i = 0;

	SqOperNumStack OperNum; // ��Ų�������ջ
	SqStack Operator; // ��Ų�������ջ
	
	//��ʼ��ջ
	SqOperNumStackInit(&OperNum);
	SqStackInit(&Operator);

	while(i < strLen)
	{
		SqStackData oper = 0;
		SqStackDataOperNum top = 0, afterTop = 0;
		
		if (str[i] != '*' && str[i] != '/' && str[i] != '+' && str[i] != '-' && str[i] != '(' && str[i] != ')')
		{
			SqStackDataOperNum num = (int)(str[i] - '0');
			SqOperNumStackPushBack(&OperNum, num);
			i++;
		}
		else  // �����˲�����
		{
			if ((&Operator)->base == (&Operator)->top) // ��Ų�������ջΪ��ʱ��ֱ�ӽ�����Ĳ�������ջ
			{
				SqStackPushBack(&Operator, str[i]); // str[i] Ϊ������
				i++;
			}
			else // ������ջ���������
			{
				switch (assertPriority(SqStackGetTop(&Operator), str[i]))
				{
				case '<':  // ���������������Ĳ��������ȼ�����ջ���Ĳ�����ʱ,ֱ�ӽ�����ջ
					SqStackPushBack(&Operator, str[i]);
					i++;
					break;							    
				case '>':  // �෴�򵯳�ջ�������������Ӧ�����㣬�ٽ�������ѹ��OperNumջ��
					SqStackPopBack(&Operator, &oper); // oper Ϊ������Ҫ��������������
					SqOperNumStackPopBack(&OperNum, &top);
					SqOperNumStackPopBack(&OperNum, &afterTop);
					SqOperNumStackPushBack(&OperNum, fourOperations(top, oper, afterTop));
					break;
				case '=':
					SqStackRemovetop(&Operator);
					i++;
					break;
				}
			}
		}

		if (i == strLen)
		{
			while (Operator.base != Operator.top)
			{
				SqStackPopBack(&Operator, &oper); // oper Ϊ������Ҫ��������������
				SqOperNumStackPopBack(&OperNum, &top);
				SqOperNumStackPopBack(&OperNum, &afterTop);
				SqOperNumStackPushBack(&OperNum, fourOperations(afterTop, oper, top));
			}
		}
	}
	int result = 0;
	if (Operator.base == Operator.top)
		printf("%d", *(OperNum.top-1));
	else
	{
		result = fourOperations(*(OperNum.top - 2), *(Operator.top - 1), *(OperNum.top - 1));
		printf("%d", result);
	}
	
	return 0;
}

void SqStackInit(SqStack* s)
{
	s->base = (SqStackData*)malloc(sizeof(SqStackData) * MAX_SQSTACK_SIZE);
	if (s->base == NULL)
		exit(0);

	//�����ڴ�ɹ� ��ʼ��ջ�Ŀռ�
	s->top = s->base;
	s->MaxSqStackCapacity = MAX_SQSTACK_SIZE;
}

void SqStackPushBack(SqStack* s, SqStackData x)
{
	if (s->top - s->base == s->MaxSqStackCapacity)
		exit(0);

	//�ɽ�����ջ����
	*(s->top) = x;
	s->top++;
}

void SqStackPopBack(SqStack* s, SqStackData* retData)
{
	if (s->base == s->top)
		exit(0);

	// �ɽ��г�ջ����
	*retData = *(s->top - 1);
	s->top--;
}
SqStackData SqStackGetTop(SqStack* s) // ��ȡ������ջ�е�ջ��Ԫ��
{
	if(s->base != s->top)
		return *(s->top - 1);
}

void SqStackRemovetop(SqStack* s)
{
	if (s->base == s->top)
		exit(0);

	// �ɽ��г�ջ����
	s->top--;
}

void SqOperNumStackInit(SqOperNumStack* s) // ��ʼ��
{
	s->base = (SqStackDataOperNum*)malloc(sizeof(SqStackDataOperNum) * MAX_SQSTACK_SIZE);
	if (s->base == NULL)
		exit(0);

	s->top = s->base;
	s->MaxNumSize = MAX_SQSTACK_SIZE;
}
void SqOperNumStackPushBack(SqOperNumStack* s, SqStackDataOperNum x) // ˳��ջ����ջ
{
	if (s->top - s->base == s->MaxNumSize)
		exit(0);

	*(s->top) = x;
	s->top++;
}
void SqOperNumStackPopBack(SqOperNumStack* s, SqStackDataOperNum* retData) // ˳��ջ�ĳ�ջ
{
	if (s->base == s->top)
		exit(0);

	*retData = *(s->top - 1);
	s->top--;
}
void SqOperNumStackRemovetop(SqOperNumStack* s) // ɾ��ջ��Ԫ��
{
	if (s->base == s->top)
		exit(0);

	s->top--;
}

char assertPriority(SqStackData operator0, SqStackData operator1) // �ж������֮������ȼ�
{
	if (operator0 == '+' || operator0 == '-')
	{
		if (operator1 == '+' || operator1 == '-' || operator1 == ')')
			return '>';
		else
			return '<';
	}
	else if (operator0 == '*' || operator0 == "/")
	{
		if (operator1 == '+' || operator1 == '-' || operator1 == ')' || operator1 == '/' || operator1 == '*')
			return '>';
		else
			return '<';
	}
	else if (operator0 == '(')
	{
		if (operator1 == ')')
			return '=';
		else
			return '<';
	}
	else
		return '>';
}

SqStackDataOperNum fourOperations(SqStackDataOperNum a, SqStackData operator, SqStackDataOperNum b)
{
	if (operator == '+')
		return a + b;
	if (operator == '-')
		return a - b;
	if (operator == '*')
		return a * b;
	if (operator == '/')
		return a / b;
}
