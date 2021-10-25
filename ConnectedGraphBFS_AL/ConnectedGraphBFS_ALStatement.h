#pragma once

#define _CRT_SECURE_NO_WARNINGS 1
#define MAX_VERTEXNUMS 70 // ��󶥵����

#include <stdio.h>
#include <stdlib.h>


typedef int VertexDataType; // �������������ݵ�����
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
	int* visited; // ͼ�ж����Ƿ񱻷��ʹ��ĵı�־����
}ALGraph;

void InitALGraph(ALGraph* graph); // ��ʼ������ͼ

void InsertVertex(ALGraph* graph, VertexDataType val); // ����ֵΪval�Ķ���

void InsertEdge(ALGraph* graph, VertexDataType val_1, VertexDataType val_2); // ������������val1��val2�ı�

int SearchVertexRetIndex(ALGraph* graph, VertexDataType val); // ��ͼ��Ѱ��ֵΪval�Ķ��������

void showALGraph(ALGraph* graph); // ��ʾ�ڽӱ��е���Ϣ

void GraphBFS_AL(ALGraph* graph, int startVertexIndex); // ������ȱ���������ͨͼ

#include "AssistQueue.h"