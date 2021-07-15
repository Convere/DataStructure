#pragma once
#include <iostream>
using namespace  std;

//typedef char VertexType;
typedef int EdgeType;
#define MAXVEX 100

typedef struct EdgeNode
{
	int adjvex;
	EdgeType weight;
	struct EdgeNode* next;
}EdgeNode;

typedef struct VertexNode
{
	VertexType data;
	EdgeNode* firstedge;
}VertexNode,AdjList[MAXVEX];

typedef struct 
{
	AdjList adjList;
	int numVertexes, numEdges;
}GraphAdjList;

void CreatALGraph(GraphAdjList* G)
{
	int i,j,k;
	EdgeNode* e;
	cout << "请输入顶点数和边数：" << endl;
	cin >> G->numVertexes >> G->numEdges;
	cout << "请输入顶点信息：" << endl;
	for (i = 0; i < G->numVertexes;i++)
	{
		cin >> G->adjList[i].data;
		G->adjList[i].firstedge = nullptr;
	}

	for (k = 0; k < G->numEdges;k++)
	{
		cout << "输入边上的顶点序号：" << endl;
		cin >> i >> j;
		e = (EdgeNode*)malloc(sizeof(EdgeNode));
		e->adjvex = j;
		e->next = G->adjList[i].firstedge;
		G->adjList[i].firstedge = e;

		e = (EdgeNode*)malloc(sizeof(EdgeNode));
		e->adjvex = i;
		e->next = G->adjList[j].firstedge;
		G->adjList[j].firstedge = e;
	}
}
