#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char VertexDataType; // �������������ݵ�����
typedef int EdgeWeightDataType; // �ߵ�Ȩֵ����

// �߽��(�Ľṹ)
typedef struct GraphEdgeNode {
	int adjVertexIndex; // �ڽӽ�������
	struct GraphEdgeNode* p_nextEdge; // ��һ���ߵĵ�ַ
	EdgeWeightDataType infoOfEdge; // �ߵ�Ȩֵ
	char* edgeTitle; // �ߵı�ʶ
}EdgeNode;

// ����(�Ľṹ)
typedef struct GraphVertexNode {
	VertexDataType* val;
	EdgeNode* p_firstAdjEdge; // ָ���һ���ڽӸö���ı�
}VertexNode;

// �ڽӱ�����ʾ��ͼ����������Ϣ
typedef struct {
	VertexNode* setsOfVertex; // ÿ����������ʾ�Ĺ�ϵ��
	int vertexNums; // ͼ�ж�����
	int edgeNums;  // ͼ�������ڵĹ�ϵ(��)�ĸ���
	int* indegree; // indegree[i] ��ʾ����Ϊi�Ķ�������
	int* topo; // ��¼������������������ж��������
	int* happen_earliest; // happen_earliest[i] ��ʾ����Ϊi���¼����緢����ʱ��
	int* happen_late; // happen_late[i] ��ʾ����Ϊi���¼���ٷ�����ʱ��
}ALGraph;

typedef struct SqStack {
	VertexNode* bottom; // ջ��ָ��
	VertexNode* top; // ջ��ָ��
	int capacityOfSqStack;
}SqStack; // ����ջ -- ������Ϊ0�Ķ��㣨����


void BuildALGraph(ALGraph* graph); // �����ڽӱ���ʼ��AOV-��

int SearchVertexRetIndex(ALGraph* graph, VertexDataType* val); // ��ͼ��Ѱ��ֵΪval�Ķ��������

void showALGraph(ALGraph* graph); // ��ʾ�ڽӱ��е���Ϣ

void Topo_sort(ALGraph* graph); // ��AOE-��������������

void CriticalPath(ALGraph* graph); // ���AOE-���Ĺؼ�·��

void insertVertex(ALGraph* graph, VertexDataType* val); // ���붥��

void insertEdge(ALGraph* graph, VertexDataType* from_Vertex, VertexDataType* to_Vertex, EdgeWeightDataType weight, char* edgeTitle); // �����

void SqStackInit(SqStack* s); // ˳��ջ�ĳ�ʼ��

void SqStackPushBack(SqStack* s, VertexNode x); // ˳��ջ����ջ����

void SqStackPopBack(SqStack* s, VertexNode* retTopElem); // ˳��ջ�ĳ�ջ����

int SqStackEmpty(SqStack* s); // �ж�ջ�Ƿ�Ϊ��
