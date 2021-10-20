#define _CRT_SECURE_NO_WARNINGS 1

#include "StatementGraphStructure.h"

// ��ʼ��ͼ�Ľṹ
void InitGraph(MatrixGraph* Graph, int n) {
	Graph->setsOfVertex = (VertexDataType*)malloc(sizeof(VertexDataType) * n);
	Graph->AdjacencyMatrix = (EdgeWeightDataType**)malloc(sizeof(int*) * n);
	for (int i = 0; i < n; i++) {
		Graph->AdjacencyMatrix[i] = (EdgeWeightDataType*)malloc(sizeof(EdgeWeightDataType) * n);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			Graph->AdjacencyMatrix[i][j] = 0;
		}
	}
	Graph->numsOfEdge = 0;
	Graph->numsOfVertex = 0;
	Graph->MaxSizeCnt = n;
}

// ��ͼ�в��붥��
void InsertVertex(MatrixGraph* Graph, VertexDataType vertex) {
	if (Graph->numsOfVertex <= Graph->MaxSizeCnt) {
		Graph->setsOfVertex[Graph->numsOfEdge] = vertex;
		Graph->numsOfVertex++;
	}
}

// ��Ӷ�������ϵ
void InsertEdge(MatrixGraph* Graph, int v1, int v2, EdgeWeightDataType weight) {
	Graph->AdjacencyMatrix[v1][v2] = weight;
	Graph->AdjacencyMatrix[v2][v1] = weight;
	Graph->numsOfEdge++;
}

// ��ʾͼ���ڽӾ����ʾ
void ShowMatrix(MatrixGraph* Graph) {
	printf("\n\n\n");
	for (int i = 0; i < Graph->numsOfVertex; i++) {
		printf("       [ ");
		for (int j = 0; j < Graph->numsOfVertex; j++) {
			if (j != Graph->numsOfVertex - 1) {
				printf("%d ", Graph->AdjacencyMatrix[i][j]);
			}
			else {
				printf("%d ", Graph->AdjacencyMatrix[i][j]);
			}
		}
		printf("]");
		printf("\n");
	}
}