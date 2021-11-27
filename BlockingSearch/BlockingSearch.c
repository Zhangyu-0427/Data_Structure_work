#define _CRT_SECURE_NO_WARNINGS 1
#define pages 1000

/*
* ����һ�����ҳ���������� [1, 1000]
*/
#include <stdio.h>
#include <assert.h>

// ������
typedef struct
{
	int maxValue; // ��ѡ���е����ؼ���
	int left;     // �����ڵ��������˵�
	int right;    // �����ڵ�������Ҷ˵�
}IndexTable;


// ֻ��Ϊ�˲��Էֿ���ҡ�һ����������Ҫ�Լ�д
IndexTable* InitIndexTable()
{
	//  ���ٴ�СΪ4�������������ռ�
	IndexTable* res = (IndexTable*)malloc(sizeof(IndexTable) * 4);

	// ����������Ϣ��Ĭ���������ؼ������ϸ������
	for (int i = 0; i < 4; i++) {
		res[i].maxValue = 250 * (i + 1);
		res[i].left  = i * 250;
		res[i].right = 250 * (i + 1) - 1;
	}

	return res;
}

int BlockingSearch(int* nums, IndexTable* table, int tableSize, int targetVal)
{
	// 1. �Ȳ��ҿ�
	int begin = 0, end = tableSize - 1;
	int mid = (begin + end) / 2;
	
	int targetBlock = 0;
	// ���ڶ��ַ��ҿ飬�߽���������֣���Ҫ����
	// 1. begieԽ�磻2. endԽ�硣
	while (begin <= end)
	{
		if (table[mid].maxValue < targetVal)
		{
			begin = mid + 1;
		}
		else if (table[mid].maxValue > targetVal)
		{
			end = mid - 1;
		}
		else
		{
			targetBlock = mid;
			break;
		}

		mid = (begin + end) / 2;
	}
	// 
	if (begin > end)
	{
		// һ����������Ǳ�Ȼ����begin���в���Ŀ��ֵ
		targetBlock = begin;
		// beginԽ��
		// targetVal�����������������еĹؼ�ֵ�����Ǳ�Ȼ�Ҳ����ġ�
		if (begin > tableSize - 1) return -1; 
		// endԽ��
		// tagetgetVal��ȻС�����еĹؼ�ֵ�����ǲ���ȷ����Ȼ�Ҳ�������Ϊ�ؼ�ֵ�����ÿ������������ֵ��
		if (end < 0) targetBlock = begin;
	}

	// 2. ���ڿ��ڵ�Ԫ��������ģ������ڿ��ڽ���˳�����
	for (int i = table[targetBlock].left; i < table[targetBlock].right; i++)
	{
		if (nums[i] == targetVal) return i;
	}

	return -1;
}

int main()
{
	int index[pages];
	int val = 0;
	FILE* pF = NULL;
	assert(pF = fopen("pagesRandom.txt", "r"));

	for (int i = 0; i < pages; i++) assert(fscanf(pF, "%d", &index[i]));
	IndexTable* table = InitIndexTable();
	printf("����������Ҫ���ҵĹؼ��ֵ�ֵ��");
	assert(scanf("%d", &val));
	int res = BlockingSearch(index, table, 4, val);


	// if(res) �����䲻����ôд����C������0Ϊ�٣���0Ϊ�棬���Զ��ڸ�����˵����ҲΪ��
	if (res >= 0)
	{
		printf("%d��ԭ�����е������ǣ�%d\n", val, res);
	}
	else
	{
		printf("ԭ��������Ŀ��ֵ%d\n", val);
	}
	return 0;
}