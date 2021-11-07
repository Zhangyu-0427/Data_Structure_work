#define _CRT_SECURE_NO_WARNINGS 1

#include "SSSP_DIJ_Statement.h"

// ��ʼ���������Ľṹ
void InitGraph(MatrixGraph* Graph, int n) {
	Graph->setsOfVertex = (int*)malloc(sizeof(int) * n);
	memset(Graph->setsOfVertex, 0, sizeof(int) * n);
	Graph->AdjacencyMatrix = (EdgeWeightDataType**)malloc(sizeof(int*) * n);
	for (int i = 0; i < n; i++) {
		Graph->AdjacencyMatrix[i] = (EdgeWeightDataType*)malloc(sizeof(EdgeWeightDataType) * n);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			Graph->AdjacencyMatrix[i][j] = Override_MAX_INT;
		}
	}

	// flag_IsSpOfVertex[i] ��ʾԴ�㵽����Ϊi�Ķ����Ƿ�ȷ������̾��롣  
	// ��ʼ����false --- 0��
	Graph->flag_IsSpOfVertex = (int*)malloc(sizeof(int) * n);
	memset(Graph->flag_IsSpOfVertex, 0, sizeof(int) * n);

	// indexOfForward[i] ��ʾԴ�㵽����Ϊi�Ķ�������·���ϣ�����i��ֱ��ǰ�� ��
	// ��ʼ����-1��
	Graph->indexOfForward = (int*)malloc(sizeof(int) * n);
	memset(Graph->indexOfForward, -1, sizeof(int) * n);

	// spOfVertex ��ʾԴ�㵽������������·����
	// ��ʼ�� ������---Override_MAX_INT�� 
	Graph->spOfVertex = (int*)malloc(sizeof(int) * n);
	memset(Graph->spOfVertex, Override_MAX_INT, sizeof(int) * n);

	Graph->numsOfEdge = 0;
	Graph->numsOfVertex = 0;
	Graph->MaxSizeCnt = n;
}

// ���������в��붥��
void InsertVertex(MatrixGraph* Graph, int vertex) {
		if (Graph->numsOfEdge >= Graph->MaxSizeCnt) exit(0);
		int i = Graph->numsOfVertex;
		Graph->setsOfVertex[i] = vertex;
		Graph->numsOfVertex++;
}

// ��Ӷ�������ϵ
void InsertEdge(MatrixGraph* Graph, int v1, int v2, EdgeWeightDataType weight) {
	Graph->AdjacencyMatrix[v1][v2] = weight;
	Graph->numsOfEdge++;
}

// ��ʾ���������ڽӾ���
void ShowMatrix(MatrixGraph* Graph) {
	printf("\n\n\n");
	for (int i = 0; i < Graph->numsOfVertex; i++) {
		printf("       [");
		for (int j = 0; j < Graph->numsOfVertex; j++) {
			if (j != Graph->numsOfVertex - 1) {
				if(Graph->AdjacencyMatrix[i][j] == Override_MAX_INT) printf("00 ");
				else printf("%02d ", Graph->AdjacencyMatrix[i][j]);
			}
			else {
				if (Graph->AdjacencyMatrix[i][j] == Override_MAX_INT) printf("00");
				else printf("%02d", Graph->AdjacencyMatrix[i][j]);
			}
		}
		printf("]");
		printf("\n");
	}
}

// DIJkstra�㷨���SSSP����
void SSSP_DIJ(MatrixGraph* Graph, int v0) {
	int n = Graph->numsOfVertex;

	// ��ʼ����������	
	for (int i = 0; i < n; i++) {
		Graph->flag_IsSpOfVertex[i] = 0;
		Graph->spOfVertex[i] = Graph->AdjacencyMatrix[v0][i];

		if (Graph->spOfVertex[i] < Override_MAX_INT) Graph->indexOfForward[i] = v0;
		else Graph->indexOfForward[i] = -1;
	}

	Graph->flag_IsSpOfVertex[v0] = 1;
	Graph->spOfVertex[v0] = 0;

	// ÿһ��Ѱ�ҵ�ǰ��ת�㵽�����������̾��룬v0�����ɵ�һ�ε���ת��

	
	for (int i = 0; i < n; i++) {

		int minWeightEdgeDesIndex = 0;
		int min_FLag = Override_MAX_INT;
		for (int j = 0; j < n; j++) {
			if (!Graph->flag_IsSpOfVertex[j] && Graph->spOfVertex[j] < min_FLag) {
				minWeightEdgeDesIndex = j;
				min_FLag = Graph->spOfVertex[j];
			}
		}
		Graph->flag_IsSpOfVertex[minWeightEdgeDesIndex] = 1;

		for (int j = 0; j < n; j++) {
			int flag = (Graph->spOfVertex[minWeightEdgeDesIndex] + Graph->AdjacencyMatrix[minWeightEdgeDesIndex][j]) < Graph->spOfVertex[j];
			if (!Graph->flag_IsSpOfVertex[j] && flag) {
				Graph->spOfVertex[j] = Graph->spOfVertex[minWeightEdgeDesIndex] +
					Graph->AdjacencyMatrix[minWeightEdgeDesIndex][j];
				Graph->indexOfForward[j] = minWeightEdgeDesIndex;
			}
				
		}
	}
	// ��ӡ��Դ�㵽ÿ���������̾���

	for (int i = 0; i < n; i++) {
		if (i == v0) continue;
		printf("Դ��%d������%d�����·��Ϊ��%02d. ��ѡ���·��Ϊ��", Graph->setsOfVertex[i], Graph->setsOfVertex[v0], 
			Graph->spOfVertex[i]);

		int l = i;
		printf("( %d", Graph->setsOfVertex[l]);
		while (l) {
			l = Graph->indexOfForward[l];
			printf(", %d", Graph->setsOfVertex[l]);
		}
		printf(" )\n");
	}
}