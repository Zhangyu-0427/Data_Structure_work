#pragma once

#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZEOFVERTEX 70
// ͼ�Ľ�����������ΪChar
typedef char VertexDataType;
// �ߵ�Ȩֵ����ΪInt
typedef int EdgeWeightDataType;

typedef struct {
	VertexDataType lowAdjVex; // ����С�����ڽӵĶ����ֵ
	EdgeWeightDataType lowEdgeWeight; // ��С�ߵ�Ȩֵ
}closedge;

typedef struct {
	VertexDataType* setsOfVertex; // һά����洢�����ֵ
	EdgeWeightDataType** AdjacencyMatrix; // ��ά�����ʾ�ڽӾ���
	closedge* flag; // �������
	int numsOfVertex; // ����ĸ���
	int numsOfEdge;  // �ߵ�����
	int MaxSizeCnt; // ���ƶ����������
}MatrixGraph; // �ڽӾ����ʾͼ�Ľṹ

void InitGraph(MatrixGraph* Graph, int n); // ��ʼ��ͼ�Ľṹ

void InsertVertex(MatrixGraph* Graph, VertexDataType vertex); // ��ͼ�в��붥��

void InsertEdge(MatrixGraph* Graph, int v1, int v2, EdgeWeightDataType weight); // ��Ӷ�������ϵ

void ShowMatrix(MatrixGraph* Graph); // ��ʾͼ���ڽӾ����ʾ

int searchVerIndex(MatrixGraph* Graph, VertexDataType verValue); // ���ڽӾ�����Ѱ��ֵΪverIndex�Ķ��������

int Min(MatrixGraph* Graph); // �ڸ���������Ѱ����С�ߣ�Ŀ������Ӷ���

void MST_Prim(MatrixGraph* Graph, VertexDataType vertexValue); // ����ͼ���ڽӾ�����ʵ��Prim�㷨