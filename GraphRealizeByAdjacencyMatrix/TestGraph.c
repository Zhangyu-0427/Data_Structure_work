#define _CRT_SECURE_NO_WARNINGS 1

#include "StatementGraphStructure.h"

int main() {

	MatrixGraph graph;
	InitGraph(&graph, 5);
	// ��Ӷ���
	InsertVertex(&graph, 'A'); // index 0
	InsertVertex(&graph, 'B'); // index 1
	InsertVertex(&graph, 'C'); // index 2
	InsertVertex(&graph, 'D'); // index 3
	InsertVertex(&graph, 'E'); // index 4
	// ��Ӷ����Ĺ�ϵ
	InsertEdge(&graph, 0, 1, 1);
	InsertEdge(&graph, 0, 3, 1);
	InsertEdge(&graph, 1, 2, 1);
	InsertEdge(&graph, 1, 4, 1);
	InsertEdge(&graph, 2, 3, 1);
	InsertEdge(&graph, 2, 4, 1);

	// չʾ����ͼ���ڽӾ���
	ShowMatrix(&graph);
	return 0;
}