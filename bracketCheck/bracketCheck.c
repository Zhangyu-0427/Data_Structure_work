#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

typedef char CheckBracketElem;
typedef struct
{
	CheckBracketElem* top;
	CheckBracketElem* base;
	int size;
}SqStack;

void SqStackInit(SqStack* s); // ��ʼ��˳��ջ
void SqStackPushBack(SqStack* s, CheckBracketElem x); // ˳��ջ����ջ����
void SqStackPopBack(SqStack* s, CheckBracketElem* retData); // ˳��ջ�ĳ�ջ����
CheckBracketElem SqStackGetTop(SqStack* s); // ���ջ��Ԫ��

int main()
{
	SqStack s;
	SqStackInit(&s);
	CheckBracketElem* Brackets = "((((()))))";
	CheckBracketElem CheckElem = 0;
	int braLen = strlen(Brackets);

	for (int i = 0; i < braLen; i++)
	{
		if (Brackets[i] == '(' || Brackets[i] == '[' || Brackets[i] == '{')
		{ // �������š� ֱ����ջ
			SqStackPushBack(&s, Brackets[i]);
		}
		else
		{
			if ((&s)->top == (&s)->base)
			{
				printf("�����ű��ʽ��ƥ��");
				return 0;
			}
			SqStackPopBack(&s, &CheckElem);
			if (Brackets[i] == ')')
			{
				if (CheckElem == '(')
				{
					continue;
				}
				else
				{
					printf("�����ű��ʽ��ƥ��");
					return 0;
				}
			}
			if (Brackets[i] == ']')
			{
				if (CheckElem == '[')
				{
					continue;
				}
				else
				{
					printf("�����ű��ʽ��ƥ��");
					return 0;
				}
			}
			if (Brackets[i] == '}')
			{
				if (CheckElem == '{')
				{
					continue;
				}
				else
				{
					printf("�����ű��ʽ��ƥ��");
					return 0;
				}
			}
		}
	}
	if ((&s)->base == (&s)->top)
		printf("�����ű��ʽƥ��");
	else
		printf("�����ű��ʽ��ƥ��");
	return 0;
}

void SqStackInit(SqStack* s) // ��ʼ��˳��ջ
{
	s->base = (CheckBracketElem*)malloc(sizeof(CheckBracketElem) * 20);
	if (s->base == NULL)
	{
		printf("�ڴ�����ʧ��");
		exit(0);
	}

	s->top = s->base;
	s->size = 20;
}

void SqStackPushBack(SqStack* s, CheckBracketElem x) // ˳��ջ����ջ����
{
	if (s->top - s->base == s->size)
	{
		printf("ջ�ռ��������޷�������ջ����");
		exit(0);
	}

	*(s->top) = x;
	s->top++;
}

void SqStackPopBack(SqStack* s, CheckBracketElem* retData) // ˳��ջ�ĳ�ջ����
{
	if (s->base == s->top)
	{
		printf("ջ�ռ�Ϊ�գ��޷����г�ջ");
		exit(0);
	}

	*retData = *(s->top - 1);
	s->top--;
}

CheckBracketElem SqStackGetTop(SqStack* s) // ���ջ��Ԫ��
{
	if (s->base == s->top)
	{
		printf("ջΪ�գ��޷���ȡԪ��");
		exit(0);
	}

	return *(s->top - 1);
}