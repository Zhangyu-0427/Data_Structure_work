#pragma once

#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZEOFVERTEX 70
// ͼ�Ľ�����������ΪChar
typedef char VertexDataType;
// �ߵ�Ȩֵ����ΪInt
typedef int EdgeWeightDataType;

typedef struct {
	VertexDataType head; // �ߵ���ʼ�� from
	VertexDataType tail; // �ߵĵ��յ� to
	EdgeWeightDataType weight; // ���ϵ�Ȩֵ
}Edge; // ����ߵ���Ϣ

typedef struct {
	VertexDataType* setsOfVertex; // һά����洢�����ֵ
	EdgeWeightDataType** AdjacencyMatrix; // ��ά�����ʾ�ڽӾ���
	Edge* Edges; // ����Ȩֵ��С��һЩ�ߵ���Ϣ
	int* vertexSet; // ÿ���������ͨ����
	int numsOfVertex; // ����ĸ���
	int numsOfEdge;  // �ߵ�����
	int MaxSizeCnt; // ���ƶ����������
}MatrixGraph; // �ڽӾ����ʾͼ�Ľṹ

void InitGraph(MatrixGraph* Graph, int n); // ��ʼ��ͼ�Ľṹ

void InsertVertex(MatrixGraph* Graph, VertexDataType vertex); // ��ͼ�в��붥��

void InsertEdge(MatrixGraph* Graph, int v1, int v2, EdgeWeightDataType weight); // ��Ӷ�������ϵ

void ShowMatrix(MatrixGraph* Graph); // ��ʾͼ���ڽӾ����ʾ

int searchVerIndex(MatrixGraph* Graph, VertexDataType verValue); // ���ڽӾ�����Ѱ��ֵΪverIndex�Ķ��������

void sort_Edges(MatrixGraph* Graph); // ΪEdge���鰴�ߵ�Ȩֵ��С���д�С��������

void Kruskal_MSTRelize(MatrixGraph* Graph); // ����Kruskal�㷨����MST
