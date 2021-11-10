#define _CRT_SECURE_NO_WARNINGS 1

#include "Topo_sortingStatement.h"

// �����ڽӱ���������ͼ
void BuildALGraph(ALGraph* graph) {
	graph->setsOfVertex = (VertexNode*)malloc(sizeof(VertexNode) * 70);
	graph->topo = (int*)malloc(sizeof(int) * 70);
	graph->indegree = (int*)malloc(sizeof(int) * 70);
	memset(graph->indegree, 0, sizeof(int) * 70);
	memset(graph->topo, 0, sizeof(int) * 70);
	graph->edgeNums = 0;
	graph->vertexNums = 0;
}

// ��ͼ��Ѱ��ֵΪval�Ķ��������
int SearchVertexRetIndex(ALGraph* graph, VertexDataType* val) {

	for (int i = 0; i < graph->vertexNums; i++) {
		if (!strcmp(graph->setsOfVertex[i].val, val)) {
			return i;
		}
	}

	return -1;
}

// ��ʾ�ڽӱ��е���Ϣ
void showALGraph(ALGraph* graph) {
	EdgeNode* cur = NULL;
	printf("AOV-�����ڽӱ�\n\n");
	for (int i = 0; i < graph->vertexNums; i++) {
		printf("	%s->", graph->setsOfVertex[i].val);
		cur = graph->setsOfVertex[i].p_firstAdjEdge;
		while (cur != NULL) {
			printf("%s->", graph->setsOfVertex[cur->adjVertexIndex].val);
			cur = cur->p_nextEdge;
		}
		printf("NULL\n");
	}
	printf("\n\n");
}

// ���붥��
void insertVertex(ALGraph* graph, VertexDataType* val){
	int i = graph->vertexNums;
	graph->setsOfVertex[i].val = val;
	graph->setsOfVertex[i].p_firstAdjEdge = NULL;
	graph->vertexNums++;
}

// �����
void insertEdge(ALGraph* graph, VertexDataType* from_Vertex, VertexDataType* to_Vertex, EdgeWeightDataType weight) {
	VertexDataType* v1 = (VertexDataType*)malloc(sizeof(VertexDataType) * 3);
	VertexDataType* v2 = (VertexDataType*)malloc(sizeof(VertexDataType) * 3);
	int v1Index = 0; strcpy(v1, from_Vertex);
	int v2Index = 0; strcpy(v2, to_Vertex);

	v1Index = SearchVertexRetIndex(graph, v1);
	v2Index = SearchVertexRetIndex(graph, v2);

	EdgeNode* newEdgeNode0 = (EdgeNode*)malloc(sizeof(EdgeNode));
	newEdgeNode0->adjVertexIndex = v2Index;
	newEdgeNode0->infoOfEdge = weight;
	newEdgeNode0->p_nextEdge = graph->setsOfVertex[v1Index].p_firstAdjEdge;
	graph->setsOfVertex[v1Index].p_firstAdjEdge = newEdgeNode0;
}

// ��AOV-��������������
void Topo_sort(ALGraph* graph) {
	// ����graph�е�indegree�����¼ÿ����������
	for (int i = 0; i < graph->vertexNums; i++) {
		EdgeNode* cur = graph->setsOfVertex[i].p_firstAdjEdge;
		while (cur) {
			int j = cur->adjVertexIndex;
			graph->indegree[j]++;
			cur = cur->p_nextEdge;
		}
	}

	// ��ʼ������ջ
	SqStack s;
	SqStackInit(&s);

	for (int i = 0; i < graph->vertexNums; i++) {
		if (!graph->indegree[i]) {
			SqStackPushBack(&s, graph->setsOfVertex[i]);
		}
	}

	int cnt_inputed_Vertex = 0; // ���ü�������¼�Ѿ�����Ķ�����
	while (!SqStackEmpty(&s)) {
		VertexNode top_Vertex;
		SqStackPopBack(&s, &top_Vertex);

		int top_Vertex_index = SearchVertexRetIndex(graph, top_Vertex.val);
		graph->topo[cnt_inputed_Vertex] = top_Vertex_index;
		cnt_inputed_Vertex++;

		EdgeNode* p_fristAdjEdgeOfTop_vertex = top_Vertex.p_firstAdjEdge;
		while (p_fristAdjEdgeOfTop_vertex) {
			int indexOfAdjVertex = p_fristAdjEdgeOfTop_vertex->adjVertexIndex;
			graph->indegree[indexOfAdjVertex]--;
			if (graph->indegree[indexOfAdjVertex] == 0) {
				SqStackPushBack(&s, graph->setsOfVertex[indexOfAdjVertex]);
			}
			p_fristAdjEdgeOfTop_vertex = p_fristAdjEdgeOfTop_vertex->p_nextEdge;
		}
	}
	if (cnt_inputed_Vertex < graph->vertexNums) {
		printf("AOV-ͼ���л����޷�������������\n");
	}
	else {
		printf("AOV-ͼ���������������һ��Ϊ��\n");
		for (int i = 0; i < graph->vertexNums; i++) {
			printf("%s ", graph->setsOfVertex[graph->topo[i]]);
		}
	}
}

// ˳��ջ�ĳ�ʼ��
void SqStackInit(SqStack* s) {
	s->bottom = (VertexNode*)malloc(sizeof(VertexNode) * 70);
	if (!s->bottom) exit(0);
	s->top = s->bottom;
	s->capacityOfSqStack = 70;
}

// ˳��ջ����ջ����
void SqStackPushBack(SqStack* s, VertexNode x) {
	if (s->top - s->bottom == 70) {
		exit(0);
	}

	*(s->top) = x;
	s->top++;

}

// ˳��ջ�ĳ�ջ����
void SqStackPopBack(SqStack* s, VertexNode* retTopElem) {
	if (SqStackEmpty(s)) exit(0);

	*retTopElem = *(s->top - 1);
	s->top--;
}

// �ж�ջ�Ƿ�Ϊ��
int SqStackEmpty(SqStack* s) {
	if (s->bottom == s->top) return 1;

	return 0;
}