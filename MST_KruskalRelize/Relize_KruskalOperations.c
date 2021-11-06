
#pragma once

#include "Kruskal_MST_Statement.h"

// ��ʼ��ͼ�Ľṹ
void InitGraph(MatrixGraph* Graph, int n) {
	Graph->setsOfVertex = (VertexDataType*)malloc(sizeof(VertexDataType) * n);
	Graph->AdjacencyMatrix = (EdgeWeightDataType**)malloc(sizeof(int*) * n);
	for (int i = 0; i < n; i++) {
		Graph->AdjacencyMatrix[i] = (EdgeWeightDataType*)malloc(sizeof(EdgeWeightDataType) * n);
	}
	if (Graph->AdjacencyMatrix == NULL) {
		exit(0);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			Graph->AdjacencyMatrix[i][j] = 2147483647;
		}
	}


	Graph->vertexSet = (int*)malloc(sizeof(int) * n);
	Graph->Edges = (Edge*)malloc(sizeof(Edge) * n * (n - 1) / 2); // ����ͼ���n * (n - 1) / 2����
	Graph->numsOfEdge = 0;
	Graph->numsOfVertex = 0;
	Graph->MaxSizeCnt = n;
}

// ��ͼ�в��붥��
void InsertVertex(MatrixGraph* Graph, VertexDataType vertex) {
	int i = Graph->numsOfVertex;
	Graph->setsOfVertex[i] = vertex; // ¼�붥�����Ϣ
	Graph->vertexSet[i] = i; // ��ʼʱ��ÿ���������ͨ��������Ϊ�Լ�

	(Graph->numsOfVertex)++; // ����ĸ�������
}

// ��Ӷ�������ϵ
void InsertEdge(MatrixGraph* Graph, int v1, int v2, EdgeWeightDataType weight) {
	Graph->AdjacencyMatrix[v1][v2] = weight;
	Graph->AdjacencyMatrix[v2][v1] = weight;
	Graph->Edges[Graph->numsOfEdge].weight = weight;
	Graph->Edges[Graph->numsOfEdge].head = Graph->setsOfVertex[v1];
	Graph->Edges[Graph->numsOfEdge].tail = Graph->setsOfVertex[v2];

	Graph->numsOfEdge++;
}

// ��ʾͼ���ڽӾ����ʾ
void ShowMatrix(MatrixGraph* Graph) {
	printf("\n\n\n");
	for (int i = 0; i < Graph->numsOfVertex; i++) {
		printf("       [");
		for (int j = 0; j < Graph->numsOfVertex; j++) {
			if (j == 0) {
				if (Graph->AdjacencyMatrix[i][j] == 2147483647) printf("00 ");
				else printf("%02d ", Graph->AdjacencyMatrix[i][j]);
				continue;
			}
			if (j != Graph->numsOfVertex - 1) {
				if (Graph->AdjacencyMatrix[i][j] == 2147483647) printf("00 ");
				else printf("%02d ", Graph->AdjacencyMatrix[i][j]);
			}
			else {
				if (Graph->AdjacencyMatrix[i][j] == 2147483647) printf("00");
				else printf("%02d", Graph->AdjacencyMatrix[i][j]);
			}
		}
		printf("]");
		printf("\n");
	}
}

// ���ڽӾ�����Ѱ��ֵΪverIndex�Ķ��������
int searchVerIndex(MatrixGraph* Graph, VertexDataType verValue) {
	for (int i = 0; i < Graph->numsOfVertex; i++) {
		if (verValue == Graph->setsOfVertex[i]) {
			return i;
		}
	}

	return -1;
}

// ΪEdges���鰴�ߵ�Ȩֵ��С���д�С��������
void sort_Edges(MatrixGraph* Graph) {
	for (int i = 0; i < Graph->numsOfEdge - 1; i++) {
		for (int j = 0; j < Graph->numsOfEdge - i - 1; j++) {
			if (Graph->Edges[j].weight > Graph->Edges[j + 1].weight) {
				Edge tmp = Graph->Edges[j];
				Graph->Edges[j] = Graph->Edges[j + 1];
				Graph->Edges[j + 1] = tmp;
			}
		}
	}
}

// ����Kruskal�㷨����MST
void Kruskal_MSTRelize(MatrixGraph* Graph) {
	sort_Edges(Graph);

	MatrixGraph KruskalMST;
	InitGraph(&KruskalMST, Graph->numsOfVertex);

	for (int i = 0; i < Graph->numsOfVertex; i++)
		InsertVertex(&KruskalMST, Graph->setsOfVertex[i]);

	int cnt = 1;
	for (int i = 0; i < Graph->numsOfEdge; i++) {
		int v1 = searchVerIndex(Graph, Graph->Edges[i].head);
		int v2 = searchVerIndex(Graph, Graph->Edges[i].tail);

		int v1_Adj = Graph->vertexSet[v1];
		int v2_Adj = Graph->vertexSet[v2];

		if (v1_Adj != v2_Adj) {
			InsertEdge(&KruskalMST, v1, v2, Graph->Edges[i].weight);
			printf("The two vertices of the %d selected edge are: %c %c\n", cnt++ , Graph->Edges[i].head, Graph->Edges[i].tail);
			for (int j = 0; j < Graph->numsOfVertex; j++) {
				if (Graph->vertexSet[j] == v2_Adj) Graph->vertexSet[j] = v1_Adj;
			}
		}
	}

	printf("\n\nThe MST generated with the Kruskal algorithm is:\n");
	ShowMatrix(&KruskalMST);
}