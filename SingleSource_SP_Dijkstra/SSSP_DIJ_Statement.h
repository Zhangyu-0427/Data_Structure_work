#pragma once

#include <stdio.h>
#include <stdlib.h>
#define Override_MAX_INT 20020427

// ͼ�Ľ�����������ΪChar
//typedef int VertexDataType;
// �ߵ�Ȩֵ����ΪInt
typedef int EdgeWeightDataType;

typedef struct {
	int* setsOfVertex; // һά����洢�����ֵ
	EdgeWeightDataType** AdjacencyMatrix; // ��ά�����ʾ�ڽӾ���
	int* flag_IsSpOfVertex; // ��¼��Դ�㵽���������Ƿ��Ѿ���ȷ�����·��
	int* indexOfForward; // ��¼Դ�㵽������������·���ϸö����ֱ��ǰ��
	int* spOfVertex; // ��¼Դ�㵽������������·���ĳ���
	int numsOfVertex; // ����ĸ���
	int numsOfEdge;  // �ߵ�����
	int MaxSizeCnt; // ���ƶ����������
}MatrixGraph; // �ڽӾ����ʾͼ�Ľṹ

void InitGraph(MatrixGraph* Graph, int n); // ��ʼ��ͼ�Ľṹ

void InsertVertex(MatrixGraph* Graph, int vertex); // ��ͼ�в��붥��

void InsertEdge(MatrixGraph* Graph, int v1, int v2, EdgeWeightDataType weight); // ��Ӷ�������ϵ

void ShowMatrix(MatrixGraph* Graph); // ��ʾͼ���ڽӾ����ʾ

void SSSP_DIJ(MatrixGraph* Graph, int v0); // DIJkstra�㷨���SSSP����
