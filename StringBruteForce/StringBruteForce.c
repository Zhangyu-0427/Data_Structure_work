#define _CRT_SECURE_NO_WARNINGS 1
#define MAXLEN 132
#include <stdio.h>
#include <stdlib.h>
typedef struct
{
	char* chs; // ���洮��һά����
	int length;       // ���洮�ĳ���
}SString;

int StringBF(SString S, SString T, int pos); // ��������ģʽƥ�䣨BF�㷨��
int main()
{
	SString S;
	S.chs ="chagjadjd\0";
	S.length = 9;

	SString T;
	T.chs = "agjk\0";
	T.length = 4;
	
	int pos = StringBF(S, T, 2);
	printf("%s����%s��ƥ��ĵ�һ��λ����%d\n", S.chs, T.chs, pos);

	return 0;
}

int StringBF(SString S, SString T, int pos) // ��������ģʽƥ�䣨BF�㷨��
{
	if (0 > pos || pos >= S.length)
	{
		printf("pos�ķ�Χ���Ϸ�");
		return -1; // ���ش�������-1
	}

	int i = pos, j = 0; //  i �� j ��ʾ��ǰ����S��ģʽ��T�д��Ƚ��ַ���λ�ã�0��1��2.......)
	while (i < S.length && j < T.length) // ����(S��T)��δ�Ƚϵ���β��
	{
		if (S.chs[i] == T.chs[j]) // �����ȽϺ���ַ�
		{
			i++;
			j++;
		}
		else  // ���������ݵ��´�����ƥ���״̬
		{
			i = i - j + 1;
			j = 0;
		}
	}
	if (i == S.length && j < T.length)
	{
		return -1;
	}
	else
	{
		return i - T.length;
	}
}