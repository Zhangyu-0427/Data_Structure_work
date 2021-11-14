#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

void QuickSort(int* nums, int left, int right) {
	// ����[1, 2]��������return 
	if (left >= right)
		return;
	// left �� right ��������������������䣬��Ϊ��Ҫ�ݹ�������
	// ������Ҫ����left��right����������begin��end�����������������������

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
	QuickSort(nums, left, pivot - 1);
	QuickSort(nums, pivot + 1, right);
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