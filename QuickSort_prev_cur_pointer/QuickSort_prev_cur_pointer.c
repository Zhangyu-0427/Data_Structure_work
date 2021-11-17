#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

void swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

// ǰ��ָ��������
void QuickSort(int* nums, int left, int right) {
	if (left >= right) {
		return;
	}

	int prev = left, cur = left;
	int keyi = prev;

	// ǰ��ָ��Ļ��͵�����Ҫ�жϵ�curָ����� ����Ҫ�ټӸ�while ������������
	while (cur <= right) {
		if (nums[cur] < nums[keyi] && ++prev != cur) {
			swap(&nums[prev], &nums[cur]);
		}
		cur++;
	}

	swap(&nums[keyi], &nums[prev]);
	keyi = prev;

	QuickSort(nums, left, keyi - 1);
	QuickSort(nums, keyi + 1, right);
}

int main() {
	int nums[] = { 1, 5, 9, 7, 6, 8, 1, 3, 6, 5, 9, 7, 16 };
	QuickSort(nums, 0, sizeof(nums) / sizeof(int) - 1);

	for (int i = 0; i < sizeof(nums) / sizeof(int); i++) printf("%d ", nums[i]);
	return 0;
}