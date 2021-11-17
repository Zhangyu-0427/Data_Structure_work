#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

// �ڶ����ݽ��п��������ʱ��
// ���������������߽ӽ�����Ļ�
// ���ŵ�Ч�ʻ��ĺܲ�
// ���ǽ�������ȡ���������������
int getMidIndex(int* nums, int left, int right) {
	if (left >= right) return -1;

	int mid = (left + right) >> 1;

	if (nums[left] > nums[mid]) // mid left
	{
		if (nums[mid] < nums[right])         // mid right left
		{       
			return right;
		}
		else if (nums[left] > nums[right])   // right mid left
		{  
			return mid;
		}
		else {                               // mid left right
			return left;
		}
	}
	else                        // left mid
	{ 
		if (nums[mid] > nums[right])        // left right mid 
		{
			return right;
		}
		else if (nums[left] > nums[right])  // right left mid 
		{
			return left;
		}
		else                                // left mid right 
		{
			return mid;
		}
	}
}

void InsertSort(int* nums, int numsSize) {
	for (int i = 0; i < numsSize - 1; i++) {
		int end = i;
		int tmp = nums[end + 1];
		while (end >= 0) {
			if (nums[end] > tmp) {
				nums[end + 1] = nums[end];
				end--;
			}
			else break;
		}
		nums[end + 1] = tmp;
	}
}

void QuickSort(int* nums, int left, int right) {
	// ����[1, 2]��������return 
	if (left >= right)
		return;
	// left �� right ��������������������䣬��Ϊ��Ҫ�ݹ�������
	// ������Ҫ����left��right����������begin��end�����������������������

	// ʹ������ߵ�ֵʼ��Ϊ�м�ֵ
	int index = getMidIndex(nums, left, right);
	swap(&nums[left], &nums[index]);

	int begin = left, end = right;
	int key = nums[left]; // ÿһ��ȡ����ߵ�ֵΪkey
	int pivot = left; // ��λ�����������ֵ

	while (begin < end) {
		// �ұ���С���ŵ����
		while (begin < end && nums[end] >= key) {
			end--;
		}// �������� nums[right] < key ---- �ŵ����
		
		nums[pivot] = nums[end];
		pivot = end;
		// ����Ҵ󣬷ŵ��ұ�
		while (begin < end && nums[begin] <= key) {
			begin++;
		}// �������� nums[left] > key ---- �ŵ��ұ�
		nums[pivot] = nums[begin];
		pivot = begin;
	}
	// ��ʱ left == right ��ѡһ����ֵ����
	pivot = begin;
	nums[pivot] = key;

	// ��ʱ [left, right] ���ֳ� [left, pivot - 1] pivot [pivot + 1, right]
	// �ݹ����QuickSort����

	// ���п���ʱ�����Ҫ����������ݱȽ��������Ȼ�ݹ���õĻ������Ӳ���Ҫ��ջ֡����
	// �������Ƕ�С��������ʹ�������������Ż�����

	// �Ż�ǰ
	//QuickSort(nums, left, pivot - 1);
	//QuickSort(nums, pivot + 1, right);

	// �Ż���-----���С������Ż�
	if (pivot - 1 - left + 1 > 10)
	{
		QuickSort(nums, left, pivot - 1);
	}
	else
	{
		InsertSort(nums + left, pivot - 1 - left + 1);
	}

	if (right - (pivot + 1) + 1 > 10)
	{
		QuickSort(nums, pivot + 1, right);
	}
	else
	{
		InsertSort(nums + pivot + 1, right - (pivot + 1) + 1);
	}
}

void TestQuickSort() {
	int nums[10];
	FILE* pF;
	if ((pF = fopen("sortdatas.txt", "r")) == NULL) {
		printf("�ļ���ʧ��\n");
		exit(0);
	}
	else {
		for (int i = 0; i < 10; i++) {
			fscanf(pF, "%d", &nums[i]);
		}
	}

	QuickSort(nums, 0, sizeof(nums) / sizeof(int) - 1);
	for (int i = 0; i < 10; i++) {
		printf("%d ", nums[i]);
	}
}
int main() {
	TestQuickSort();
	return 0;
}