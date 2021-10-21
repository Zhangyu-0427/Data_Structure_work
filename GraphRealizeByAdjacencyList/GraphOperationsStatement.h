#pragma once
#define MAX_VERTEXNUMS 70 // ��󶥵����

#include <stdio.h>
#include <stdlib.h>

typedef char VertexDataType; // �������������ݵ�����
typedef int EdgeWeightDataType; // �ߵ�Ȩֵ����

// �߽��(�Ľṹ)
typedef struct GraphEdgeNode {
	int adjVertexIndex; // �ڽӽ�������
	struct GraphEdgeNode* p_nextEdge; // ��һ���ߵĵ�ַ
	EdgeWeightDataType infoOfEdge; // �ߵ���Ϣ
}EdgeNode;

// ����(�Ľṹ)
typedef struct GraphVertexNode {
	VertexDataType val;
	EdgeNode* p_firstAdjEdge; // ָ���һ���ڽӸö���ı�
}VertexNode;

// �ڽӱ�����ʾ��ͼ����������Ϣ
typedef struct {
	VertexNode* setsOfVertex; // ÿ����������ʾ�Ĺ�ϵ��
	int vertexNums; // ͼ�ж�����
	int edgeNums;  // ͼ�������ڵĹ�ϵ(��)�ĸ���
}ALGraph;

void BuildALGraph(ALGraph* graph); // �����ڽӱ���������ͼ

int SearchVertexRetIndex(ALGraph* graph, VertexDataType val); // ��ͼ��Ѱ��ֵΪval�Ķ��������

void showALGraph(ALGraph* graph); // ��ʾ�ڽӱ��е���Ϣ

