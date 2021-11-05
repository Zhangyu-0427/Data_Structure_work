#pragma once

#include "Prim_MST_Statement.h"
	
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

	Graph->flag = (closedge*)malloc(sizeof(closedge) * n);
	Graph->numsOfEdge = 0;
	Graph->numsOfVertex = 0;
	Graph->MaxSizeCnt = n;
}

// ��ͼ�в��붥��
void InsertVertex(MatrixGraph* Graph, VertexDataType vertex) {
	int i = Graph->numsOfVertex;
	if (i < Graph->MaxSizeCnt) {
		Graph->setsOfVertex[i] = vertex;
		(Graph->numsOfVertex)++;
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
				printf("%02d ", Graph->AdjacencyMatrix[i][j]);
			}
			else {
				printf("%02d ", Graph->AdjacencyMatrix[i][j]);
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

int Min(MatrixGraph* Graph) {
	int min = 100, minIndex = 0;
	for (int i = 0; i < Graph->numsOfVertex; i++) {
		if ((Graph->flag[i].lowEdgeWeight != 0) && (Graph->flag[i].lowEdgeWeight < min)) {
			min = Graph->flag[i].lowEdgeWeight;
			minIndex = i;
		}
	}

	return minIndex;
}

// ����ͼ���ڽӾ�����ʵ��Prim�㷨
void MST_Prim(MatrixGraph* Graph, VertexDataType vertexValue) {
	MatrixGraph retGraph;
	InitGraph(&retGraph, Graph->numsOfVertex);

	int initIndex = searchVerIndex(Graph, vertexValue);

	// ��ʼ��flag���飬�Ա�ѡ��Ķ�����Ϊһ�������ļ��ϣ����������е㿴������һ������
	for (int i = 0; i < Graph->numsOfVertex; i++) {
		InsertVertex(&retGraph, Graph->setsOfVertex[i]);
		if (i == initIndex) { // ��ѡ��ĵ�ĵ���ѡ��ĵ��ޱߣ�Ȩֵ��Ϊ0
			Graph->flag[i].lowEdgeWeight = 0;
		}
		else {
			// �����㵽����ѡ��ĵ�֮���Ȩֵ�����ɵ��ڽӾ���ɵ�
			// ���ڴ�ʱ��ѡ��ĵ�Ϊһ�������ļ��ϣ��ҵ�ǰ״ֻ̬��
			// ��һ��Ԫ�أ����������㵽���ڽӾ��󵽿����Ǳ�ѡ���
			// �㣬��Ϊ����Ҫѡ��һ��������Ȩֵ�ıߣ����������뵱
			// ǰ��ѡ��ĵ����ڽӵ�
			Graph->flag[i].lowAdjVex = vertexValue;
			Graph->flag[i].lowEdgeWeight = Graph->AdjacencyMatrix[initIndex][i];
		} 
	}
	int weights = 0;
	for (int i = 1; i < Graph->numsOfVertex; i++) {
		int minWeightEdgeIndex = Min(Graph);

		// ����С�������Ķ���ֵ��from��
		VertexDataType vertex_0 = Graph->flag[minWeightEdgeIndex].lowAdjVex;
		// ��ѡ�����С��ָ��Ķ��㣨to��
		VertexDataType vertex_1 = Graph->setsOfVertex[minWeightEdgeIndex];

		// �������űߵõ���ѡ�������������ͼ�е����������¼��뵽��Ҫ�������С��������
		int i_1 = searchVerIndex(Graph, vertex_0);
		int i_2 = searchVerIndex(Graph, vertex_1);

		// �𲽹�����С������
		InsertEdge(&retGraph, i_1, i_2, Graph->flag[minWeightEdgeIndex].lowEdgeWeight);
		// �ۼ�ÿ��ѡ������űߵ�Ȩֵ
		weights += Graph->flag[minWeightEdgeIndex].lowEdgeWeight;

		printf("The %d times two vertices selected are��%c %c\n", i, vertex_0, vertex_1);
		(Graph->flag)[minWeightEdgeIndex].lowEdgeWeight = 0;
		// �Ե�ǰѡ�����СȨֵ�ı�ָ��Ķ���Ϊ��׼������flag����
		for (int i = 0; i < Graph->numsOfVertex; i++) {
			int edge_0 = Graph->AdjacencyMatrix[minWeightEdgeIndex][i];
			int edge_1 = Graph->flag[i].lowEdgeWeight;
			if (edge_0 < edge_1) { 
				/*              ----����flag����----
				 ���׼���Ƚϣ������׼ֵС��flag�����д����ŵĵ���Ӧ�����Ȩֵ����
				 ����flag�����е���Ӧ�Ķ������СȨֵ(��̰��˼���֪��flag���鴢��
				 �����ѹ�����Ĳ�����С�������е�δ��ѡ��Ķ������СȨֵ��Ϊ��׼ֵ
				 */
				(Graph->flag)[i].lowAdjVex = vertex_1;
				(Graph->flag)[i].lowEdgeWeight = edge_0;
			}
		}
	}
	printf("\n");
	// ��ӡ��С���������ڽӾ���
	printf("MST generated with Prim is��\n");
	for (int i = 0; i < retGraph.numsOfVertex; i++) {
		for (int j = 0; j < retGraph.numsOfVertex; j++) {
			if (j == 0) {
				printf("\t   [");
			}
			if (retGraph.AdjacencyMatrix[i][j] == 2147483647) {
				// ��ֱ����ͨ�������㣺����֮���Ȩֵ
				printf("00 ");
			}
			else {
				printf("%02d ", retGraph.AdjacencyMatrix[i][j]);
				
			}
			if (j == retGraph.numsOfVertex - 1) {
				printf("]");
			}
			
		}
		printf("\n");
	}
	printf("Minimum Cost Spanning is: %d", weights);
}