#pragma once
#include "MGraph.h"

void shortestPath_Floyd(MGraph* G, vector<vector<int>> *P, vector<vector<int>> *D)
{
	int v, k, w;
	for (v = 0; v < G->numVertexes; v++)
	{
		for (w = 0; w < G->numVertexes; w++)
		{
			(*D)[v][w] = G->arc[v][w];
			(*P)[v][w] = w;
		}
	}
	for ( k = 0; k < G->numVertexes; k++)
	{
		for (size_t v = 0; v <  G->numVertexes; v++)
		{
			for ( w = 0; w <  G->numVertexes; w++)
			{
				if ((*D)[v][w] > (*D)[v][k] + (*D)[k][w])
				{
					(*D)[v][w] = (*D)[v][k] + (*D)[k][w];
					(*P)[v][w] = (*P)[v][k];
				}
			}
		}
	}
	for (v = 0; v < G->numVertexes; v++)
	{
		for (w = v + 1; w < G->numVertexes;w++)
		{
			cout << "v[" << v << "] " << "w[" << w << "] weight: " << (*D)[v][w];
			k = (*P)[v][w];
			cout << " path: " << v;
			while (k != w)
			{
				cout << " -> " << k;
				k = (*P)[k][w];
			}
			cout << " -> " << w << endl;
		}
		cout << endl;
	}
}