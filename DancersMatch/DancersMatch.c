#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	char name[10];
	int sex; // ˵���� 0-��ʾŮ����1-��ʾ�к�
}Person;   // ���屾����һ���˵Ľṹ

typedef struct LQueueNode
{
	Person data;
	struct LQueueNode* next;
}LQueueNode;  // ������ʽ�����н��Ľṹ

typedef struct
{
	LQueueNode* head;
	LQueueNode* tail;
}LinkQueue;  // ������ʽ���еĽṹ

LQueueNode* BuyNewLQueueNode(char* name, int sex); // ����һ���½��   Ps:������ʹ�øú��� ����Ӳ�����Ƕ��ʹ��
void LinkQueueInit(LinkQueue* q); // ��ʼ����ʽ����
void LinkQueuePushBack(LinkQueue* q, char* name, int sex); // ��ʽ���е���Ӳ���
void LinkQueuePopFront(LinkQueue* q, char** retName, int* retSex); // ��ʽ���еĳ��Ӳ���

int main()
{
	LinkQueue male;
	LinkQueue female;
	LinkQueueInit(&male);
	LinkQueueInit(&female);
	int cnt = 0;
	Person Persons[7] = { {"����", 1},
		              {"�Ժ�", 0},
	               {"С��", 1},
	            {"����", 0},
			 {"����", 1},
	      {"����", 0},
		{"С��", 0}};

	for (int i = 0; i < 7; i++) // ��Ϣ¼��
	{
		if (Persons[i].sex == 0) // �Ա�ΪŮ
		{
			LinkQueuePushBack(&female, Persons[i].name, Persons[i].sex);
		}
		else  // �Ա�Ϊ��
		{
			LinkQueuePushBack(&male, Persons[i].name, Persons[i].sex);
		}
	}

	while (male.head != male.tail && female.head != female.tail)
	{
		cnt++;
		
		char* maleName = (char*)malloc(sizeof(char) * 10);
		char* femaleName = (char*)malloc(sizeof(char) * 10);
		if (maleName == NULL || femaleName == NULL)
		{
			printf("�����ڴ�ʱ����");
			exit(0);
		}
		
		int maleSex;
		int femaleSex;
		LinkQueuePopFront(&male, &maleName, &maleSex);
		LinkQueuePopFront(&female, &femaleName, &femaleSex);
		printf("��%d�ԣ��У�%s, Ů��%s\n", cnt, maleName, femaleName);
	}
	if (female.head == female.tail)
	{
		printf("��һ��������ʼʱ,�������ƥ��Ȩ���ǣ���ͬѧ,%s\n", male.head->next->data.name);
	}
	else
	{
		printf("��һ��������ʼʱ,�������ƥ��Ȩ���ǣ�Ůͬѧ,%s\n", female.head->next->data.name);
	}
	return 0;
}

LQueueNode* BuyNewLQueueNode(char* name, int sex) // ����һ���½��
{
	LQueueNode* newNode = (LQueueNode*)malloc(sizeof(LQueueNode));
	if (newNode == NULL)
	{
		printf("�����ڴ�ʧ��");
		return NULL;
	}

	strcpy(newNode->data.name, name);
	newNode->data.sex = sex;
	newNode->next = NULL;
}

void LinkQueueInit(LinkQueue* q) // ��ʼ����ʽ����
{
	LQueueNode* newNode = (LQueueNode*)malloc(sizeof(LQueueNode));
	if (newNode == NULL)
	{
		printf("�����ڴ�ʧ��");
		exit(0);
	}

	newNode->next = NULL;
	q->head = newNode;
	q->tail = newNode;
}
void LinkQueuePushBack(LinkQueue* q, char* name, int sex) // ��ʽ������Ӳ���
{
	LQueueNode* newNode = BuyNewLQueueNode(name, sex);
	q->tail->next = newNode;
	q->tail = newNode;
}
void LinkQueuePopFront(LinkQueue* q, char** retName, int* retSex) // ��ʽ���еĳ��Ӳ���
{
	if (q->head == q->tail)
	{
		printf("�ö��пռ�Ϊ�գ��޷�����");
		exit(0);
	}

	LQueueNode* nowPhead = q->head->next;
	strcpy(*retName, nowPhead->data.name);
	*retSex = nowPhead->data.sex;

	q->head->next = nowPhead->next; // ע��������ȷ��
	if (nowPhead == q->tail)
	{
		q->tail = q->head;
	}
	free(nowPhead);
}