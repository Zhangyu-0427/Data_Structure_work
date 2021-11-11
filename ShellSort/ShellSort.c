#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>


void ShellSort(int* nums, int numsSize) {
	int gap = numsSize;
	
	// gap > 1 �Ķ���Ԥ����
	while (gap > 1) {
		gap = gap / 2; // ����Ԥ����ļ��

		// ���������ֱ�Ӳ�������gap = 1����ԭ�ͽ��иĶ�	
		for (int i = 0; i < numsSize - gap; i++) {
			int end = i;
			int tmp = nums[end + gap];
			while (end >= 0) {
				if (nums[end] > tmp) {
					nums[end + gap] = nums[end];
					end -= gap;
				}
				else break;
			}
			nums[end + gap] = tmp;
		}
	}
}

void TestShellSort() {
	int nums[] = { 2, 4, 1, 0, -6, 7, 3, 3, 4, 10 };
	ShellSort(nums, sizeof(nums) / sizeof(int));
	for (int i = 0; i < sizeof(nums) / sizeof(int); i++) {
		printf("%d ", nums[i]);
	}
	printf("\n");
}

int main() {
	TestShellSort();
	return 0;
}