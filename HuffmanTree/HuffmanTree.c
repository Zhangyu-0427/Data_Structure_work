#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int weight;
	int parent, leftChild, rightChild;
}HTNode;

void Select(HTNode** tree, int Size, int* ret_1, int* ret_2) {
	int min = 100, secondMin = 100;
	int minIndex = 0, secondMinIndex = 0;
	for (int i = 1; i <= Size; i++) {
		if ((*tree)[i].parent == 0) {
			if ((*tree)[i].weight < min) {
				min = (*tree)[i].weight;
				minIndex = i;
			}
		}
	}

	for (int i = 1; i <= Size; i++) {
		if ((*tree)[i].parent == 0 && i != minIndex) {
			if ((*tree)[i].weight < secondMin) {
				secondMin = (*tree)[i].weight;
				secondMinIndex = i;
			}
		}
	}

	*ret_1 = minIndex;
	*ret_2 = secondMinIndex;

}

void CreateHuffmanTree(HTNode** tree, int n) {
	if (n <= 1) {
		return; // �������Ĺ�������û������
	}

	// ��ʼ����������
	int Size = 2 * n - 1;
	*tree = (HTNode*)malloc(sizeof(HTNode) * (Size + 1)); // 0 ��λ�ò�ʹ��
	for (int i = 1; i <= Size; i++) {
		(*tree)[i].parent = 0;
		(*tree)[i].leftChild = 0;
		(*tree)[i].rightChild = 0;
	}
	for (int i = 1; i <= n; i++) {
		printf("�붨���%d��Ҷ�ӽ���Ȩֵ, ��ֻ������һ��ʵ��\n", i);
		scanf_s("%d", &((*tree)[i].weight));
	}

	// ������������
	int ret_1 = 0, ret_2 = 0;
	for (int i = n + 1; i <= Size; ++i) {
		ret_1 = 0;  ret_2 = 0;
		Select(tree, i - 1, &ret_1, &ret_2);
		(*tree)[ret_1].parent = i; (*tree)[ret_2].parent = i;
		(*tree)[i].leftChild  = ret_1;
		(*tree)[i].rightChild = ret_2;
		(*tree)[i].weight = (*tree)[ret_1].weight + (*tree)[ret_2].weight;
	}
}

int main() {
	HTNode* tree = NULL;
	CreateHuffmanTree(&tree, 8);
	for (int i = 1; i <= 15; i++) {
		printf("%d\n", tree[i].weight);
	}
	return 0;
}