#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

// ��ֱ��ѡ�������㷨�����Ż�
void Optimize_SelectSort(int* nums, int numsSize) {
	int left = 0, right = numsSize - 1;

	while (left < right) {
		int min_i = left, max_i = right;
		for (int i = left; i <= right; i++) {
			if (nums[i] > nums[max_i])
				max_i = i;
			if (nums[i] < nums[min_i])
				min_i = i;
		}

		swap(&nums[left], &nums[min_i]);

		// �����С�Ļ���������ߵ�ͬʱ���ֵҲ�������
		// ���ʱ����뽫max_i����Ϊmin_i�����λ�ô���������
		// "left(max_i) <-> min_i" ---> "left(min) min_i(max)"
		// ���ʱ��Ҫ���� max_i = min_i �ſ�������max_i���ʵ��������������ֵ
		// ���������Сֵ
		if (max_i == left) {
			max_i = min_i;
		}
		swap(&nums[right], &nums[max_i]);
		++left;
		--right;
	}
}

void TestSelectSort() {
	int nums[10];
	FILE* pF;

	if ((pF = fopen("sortdatas.txt", "r")) == NULL) {
		printf("�ļ���ʧ��\n");
	}
	else {
		for (int i = 0; i < sizeof(nums) / sizeof(int); i++) {
			fscanf(pF, "%d", &nums[i]);
		}
	}

	Optimize_SelectSort(nums, sizeof(nums) / sizeof(int));
	for (int i = 0; i < sizeof(nums) / sizeof(int); i++) {
		printf("%d ", nums[i]);
	}
}

int main() {
	TestSelectSort();
	return 0;
}