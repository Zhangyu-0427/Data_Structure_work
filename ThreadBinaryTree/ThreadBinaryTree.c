#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

typedef char TBNodeData; // ������������洢����������

typedef struct ThreadBinaryTreeNode{
	TBNodeData val; // ������

	struct ThreadBianryTreeNode* left, * right; // ָ����

	int LTag;
	int RTag; // ������־��
}TBTreeNode;

TBTreeNode* prev = NULL;
// �������� & ���岿��
TBTreeNode* CreateTree(char* s, int* pi) {
	if (s[*pi] == '#') {
		(*pi)++;
		return NULL;
	}

	TBTreeNode* root = (TBTreeNode*)malloc(sizeof(TBTreeNode));
	if (root == NULL) {
		exit(0);
	}
	root->val = s[*pi];
	(*pi)++;
	root->LTag = 0;
	root->RTag = 0;
	root->left = CreateTree(s, pi);
	root->right = CreateTree(s, pi);

	return root;
}

void InThreading(TBTreeNode* root) { // ������������жԶ���������������
	if (root) {
		InThreading(root->left);
		if (root->left == NULL) {
			root->LTag = 1;
			root->left = prev;
		}
		if (prev && prev->right == NULL) {
			prev->RTag = 1;
			prev->right = root;
		}
		prev = root;
		InThreading(root->right);
	}
}

// ����������������
void InOrderTree(TBTreeNode* root) {
	while (root) {
		while (root->LTag == 0) {
			root = root->left;
		}

		printf("%c ", root->val);
		while (root->RTag == 1 && root->right != NULL) {
			root = root->right;
			printf("%c ", root->val);
		}

		root = root->right;
	}
}

void InOrder(TBTreeNode* root) {
	if (root == NULL) {
		return;
	}

	InOrder(root->left);
	printf("%c ", root->val);
	InOrder(root->right);
}

int main() {

	char str[100];
	scanf("%s", str);

	int i = 0;
	TBTreeNode* root = CreateTree(str, &i);
	//InOrder(root);
	InThreading(root);
	InOrderTree(root);
	return 0;
}