#pragma once

#include <stdio.h>
#include <stdlib.h>

// ͼ�Ľ�����������ΪChar
typedef char VertexDataType;
// �ߵ�Ȩֵ����ΪInt
typedef int EdgeWeightDataType;

typedef struct {
	VertexDataType* setsOfVertex; // һά����洢�����ֵ
	EdgeWeightDataType** AdjacencyMatrix; // ��ά�����ʾ�ڽӾ���
	int numsOfVertex; // ����ĸ���
	int numsOfEdge;  // �ߵ�����
	int MaxSizeCnt; // ���ƶ����������
}MatrixGraph; // �ڽӾ����ʾͼ�Ľṹ

void InitGraph(MatrixGraph* Graph, int n); // ��ʼ��ͼ�Ľṹ

void InsertVertex(MatrixGraph* Graph, VertexDataType vertex); // ��ͼ�в��붥��

void InsertEdge(MatrixGraph* Graph, int v1, int v2, EdgeWeightDataType weight); // ��Ӷ�������ϵ

void ShowMatrix(MatrixGraph* Graph); // ��ʾͼ���ڽӾ����ʾ