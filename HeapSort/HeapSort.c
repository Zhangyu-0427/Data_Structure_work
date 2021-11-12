#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

void Swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

// ����ǰ��ſ���ʹ�����µ����㷨������Ϊ���
// ��������������Ϊ�ѣ���Ѻ�С��
void AdjustDown(int* nums, int numsSize, int rootIndex) {
	int parent = rootIndex;
	int child = 2 * parent + 1; // Ĭ��Ϊ����

	while (child < numsSize) {
		// �Һ��Ӵ������ӣ�ѡ���Һ���
		if (child + 1 < numsSize && nums[child + 1] > nums[child]) {
			child += 1;
		}

		// ���е���
		if (nums[parent] < nums[child]) {
			Swap(&nums[parent], &nums[child]);
			parent = child;
			child = parent * 2 + 1;
		}
		else {
			break;
		}
	}
}


// ������� 
// С�ѽ���
void HeapSort(int* nums, int numsSize) {
	// �����һ����Ҷ�ӽ�㿪ʼ�������Ͻ���
	for (int i = (numsSize - 2) / 2; i >= 0; i--) {
		AdjustDown(nums, numsSize, i);
	}

	// ���򴴽���ѣ���Ϊÿһ�ν�δ��������ݵ����ֵ�Ƶ��������һ����
	// ��������ȥ�Ѿ������������ݣ��������ݾ�ֻ����Ҫ�����µ�������ת
	// ��Ϊ���
	int end = numsSize - 1;
	while (end > 0) {
		// �����ֵ�Ƶ�����
		Swap(&nums[0], &nums[end]);
		// �Խ�����������ȥ�Ѿ��Ƶ������������ݽ������µ���
		AdjustDown(nums, end, 0);
		end--;
	}
}

void TestHeapSort() {
	int nums[10];
	FILE* pF;
	if ((pF = fopen("sortdatas.txt", "r")) == NULL) {
		printf("�ļ���ʧ�ܣ�");
		exit(0);
	}

	for (int i = 0; i < 10; i++) {
		fscanf(pF, "%d", &nums[i]);
	}

	HeapSort(nums, sizeof(nums) / sizeof(int));
	for (int i = 0; i < sizeof(nums) / sizeof(int); i++) {
		printf("%d ", nums[i]);
	}
}

int main() {
	TestHeapSort();
	return 0;
}