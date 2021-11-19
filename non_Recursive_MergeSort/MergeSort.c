#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

// �ǵݹ�ʱһ����Ҫ��������ֵ
void MergeSortNonR(int* nums, int n)
{
	// ����һ���������飬�����ÿ�ι鲢�Ľ��
	int* tmp = (int*)malloc(sizeof(int) * n);

	int gap = 1; // ��ʼʱ�鲢��ÿ�����ݵĸ���
	while (gap < n)
	{
		// �ֳ�[i,  i + gap - 1]  [i + gap, i + 2 * gap - 1]
		for (int i = 0; i < n; i += 2 * gap)
		{
			// ��ȡ������Ҫ�鲢����������
			int begin1 = i, end1 = i + gap - 1;
			int begin2 = i + gap, end2 = i + 2 * gap - 1;

			// �鲢��������������ܲ����ڣ���������
			if (begin2 >= n)
			{
				break;
			}

			// �鲢�������Ұ���������ˣ���������
			if (end2 >= n)
			{
				end2 = n - 1;
			}

			int index = i;
			while (begin1 <= end1 && begin2 <= end2)
			{
				if (nums[begin1] < nums[begin2])
				{
					tmp[index++] = nums[begin1++];
				}
				else 
				{
					tmp[index++] = nums[begin2++];
				}
			}

			// �ϲ�
			while (begin1 <= end1)
			{
				tmp[index++] = nums[begin1++];
			}
			while (begin2 <= end2)
			{
				tmp[index++] = nums[begin2++];
			}
			// �ϲ�����

			// ������ȥ
			for (int j = i; j <= end2; j++)
			{
				nums[j] = tmp[j];
			}
		}

		gap *= 2;
		// 1 2 3 4 5 6 7 8 9 -- gap = 1
		// 12   34   56   78 -- gap = 2
		// 1 2 3 4   5 6 7 8 -- gap = 4
	}
	free(tmp);
}
int main()
{
	int nums[] = { 1, 5, 9, 6, 3, 0, 7, 9, 10, 11, 20, 2 };

	MergeSortNonR(nums, sizeof(nums) / sizeof(int));
	for (int i = 0; i < sizeof(nums) / sizeof(int); i++) printf("%d ", nums[i]);
	return 0;
}