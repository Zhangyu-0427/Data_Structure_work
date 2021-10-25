#define _CRT_SECURE_NO_WARNINGS 1

#include "ConnectedGraphBFS_ALStatement.h"

// ��ʼ������ͼ
void InitALGraph(ALGraph* graph) {
	graph->setsOfVertex = (VertexNode*)malloc(sizeof(VertexNode) * MAX_VERTEXNUMS);
	graph->edgeNums = 0;
	graph->vertexNums = 0;

	graph->visited = (int*)malloc(sizeof(int) * MAX_VERTEXNUMS);
}

// ����ֵΪval�Ķ���
void InsertVertex(ALGraph* graph, VertexDataType val) {
	graph->setsOfVertex[graph->vertexNums].val = val;
	graph->setsOfVertex[graph->vertexNums].p_firstAdjEdge = NULL;
	graph->visited[graph->vertexNums] = 0;// ��ʼ������ʱ�Ľ��δ������
	graph->vertexNums++;

}

// ��ͼ��Ѱ��ֵΪval�Ķ��������
int SearchVertexRetIndex(ALGraph* graph, VertexDataType val) {

	for (int i = 0; i < graph->vertexNums; i++) {
		if (graph->setsOfVertex[i].val == val) {
			return i;
		}
	}

	return -1;
}

// ������������val1��val2�ı�
void InsertEdge(ALGraph* graph, VertexDataType val_1, VertexDataType val_2) {
	int v1Index = 0;
	int v2Index = 0;

	v1Index = SearchVertexRetIndex(graph, val_1);
	v2Index = SearchVertexRetIndex(graph, val_2);


	// ����ͼ��Ҫ������һ�������������������㣬����ϵX->Y��ͬʱ��Ҳ��Ҫ��ϵY->X

	// ͷ����������ÿ��������ڽӹ�ϵ

	// X->Y
	EdgeNode* newEdgeNode0 = (EdgeNode*)malloc(sizeof(EdgeNode));
	if (newEdgeNode0 == NULL) {
		exit(0);
	}
	newEdgeNode0->adjVertexIndex = v2Index;
	newEdgeNode0->p_nextEdge = graph->setsOfVertex[v1Index].p_firstAdjEdge;
	graph->setsOfVertex[v1Index].p_firstAdjEdge = newEdgeNode0;

	// Y->X
	EdgeNode* newEdgeNode1 = (EdgeNode*)malloc(sizeof(EdgeNode));
	if (newEdgeNode1 == NULL) {
		exit(0);
	}
	newEdgeNode1->adjVertexIndex = v1Index;
	newEdgeNode1->p_nextEdge = graph->setsOfVertex[v2Index].p_firstAdjEdge;
	graph->setsOfVertex[v2Index].p_firstAdjEdge = newEdgeNode1;

	graph->edgeNums++;
}

// ��ʾ�ڽӱ��е���Ϣ
void showALGraph(ALGraph* graph) {
	EdgeNode* cur = NULL;
	printf("��ǰͼ���ڽӱ��״̬��\n");
	for (int i = 0; i < graph->vertexNums; i++) {
		printf("Adjacency List[%d]: %d => ", i, graph->setsOfVertex[i].val);
		cur = graph->setsOfVertex[i].p_firstAdjEdge;
		while (cur != NULL) {
			printf("%d->", graph->setsOfVertex[cur->adjVertexIndex].val);
			cur = cur->p_nextEdge;
		}
		printf("NULL\n");
	}
}

// ������ȱ���������ͨͼ
void GraphBFS_AL(ALGraph* graph, int startVertexIndex) {
	// ÿһ�ε��ù�����ȱ����㷨��Ҫ����֮ǰ����ʱ�������������ѱ����ʹ��ı�־
	memset(graph->visited, 0, MAX_VERTEXNUMS);
	printf("\n��ֵΪ%d�Ķ��㿪ʼ������ȱ����ý��Ϊ��", graph->setsOfVertex[startVertexIndex].val);
	LQueue queue;
	InitLQueue(&queue);
	push(&queue, &(graph->setsOfVertex[startVertexIndex].val)); // ���Ƚ�Ԫ�������BFS�����õ�

	VertexNode* retVal = (VertexNode*)malloc(sizeof(VertexNode));
	EdgeNode* cur = (EdgeNode*)malloc(sizeof(EdgeNode));

	while (!QueueEmpty(&queue)) {
		pop(&queue, retVal);
		if (retVal == NULL) {
			exit(0);
		}
		cur = retVal->p_firstAdjEdge; // cur �� retVal�����Ͳ�һ�� �ڸ�cur��ֵʱ�Ǹ��϶����Ķ���ĵ�һ����֮����ϵ�ıߵĵ�ַ
		if (graph->visited[SearchVertexRetIndex(graph, retVal->val)] == 0) {
			printf("%d ", retVal->val);
			graph->visited[SearchVertexRetIndex(graph, retVal->val)] = 1; // ��¼�ö����ѱ����ʹ�
		}
		while (cur) {
			if (graph->visited[cur->adjVertexIndex] == 0) { // ���������ʹ��Ķ��㲻����ջ�����ű�����һ����
				push(&queue, &(graph->setsOfVertex[cur->adjVertexIndex].val));
			}

			cur = cur->p_nextEdge;
		}
	}
}