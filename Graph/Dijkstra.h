#pragma once
#include "MGraph.h"

void shortestPath_Dijkstra(MGraph* G, int v0, vector<int> *P, vector<int> *D)
{
	int v, w, k, min;
	vector<int> final;
	for (int v = 0; v < G->numVertexes; v++)
	{
		final.push_back(0);
		(*P)[v] = 0;
		(*D)[v] = G->arc[v0][v] ;
	}
	(*D)[v0] = 0;
	final[v0] = 1;
	//开始主循环 每次求得v0到某个顶点v的最短路径
	for (v = 1; v < G->numVertexes; v++)
	{
		min = INFINITY;
		for (w = 0; w < G->numVertexes;w++)
		{
			if (!final[w] && (*D)[w] < min)
			{
				k = w;
				min = (*D)[w];
			}
		}
		final[k] = 1;
		for (w = 0; w < G->numVertexes;w++)
		{
			if (!final[w]&&(min+G->arc[k][w] < (*D)[w]))
			{
				(*D)[w] = min + G->arc[k][w];
				(*P)[w] = k;
			}
		}
	}
	for (int i = 0; i < D->size();i++)
	{
		cout << (*D)[i] << " ";
	}
	cout << endl;
}