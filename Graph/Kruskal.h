#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include "MGraph.h"
#define MAXVEX 100
using namespace std;


typedef struct 
{
	int begin;
	int end;
	int weight;
}Edge;
namespace Kruscal
{
	vector<Edge> GraphToSortedEdges(MGraph* G)
	{
		vector<Edge> ret;
		Edge edge;
		for (int i = 0; i < G->numVertexes; i++)
		{
			for (int j = 0; j <= i; j++)
			{
				if (G->arc[i][j] >= 1)
				{
					edge.begin = j;
					edge.end = i;
					edge.weight = G->arc[i][j];
					ret.push_back(edge);
				}
			}
		}
		sort(ret.begin(), ret.end(), [](Edge &e1, Edge &e2) {return e1.weight < e2.weight; });
		return ret;
	}

	int Find(int* parent, int f)
	{
		while (parent[f] > 0)
		{
			f = parent[f];
		}
		return f;
	}

	void miniSpan_Kruskal(MGraph* G)
	{
		int n, m;
		vector<Edge> edges;
		int parent[MAXVEX];
		edges = GraphToSortedEdges(G);
		for (int i = 0; i < G->numVertexes; i++)
		{
			parent[i] = 0;
		}
		for (int i = 0; i < G->numEdges; i++)
		{
			n = Find(parent, edges[i].begin);
			m = Find(parent, edges[i].end);

			if (n != m)
			{
				parent[n] = m;
				cout << edges[i].begin << "," << edges[i].end << " " << edges[i].weight << endl;
			}
		}
	}
}