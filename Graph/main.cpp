#include <iostream>
#include <queue>
#include <stack>
#include <iterator>
#include "MGraph.h"
#include "GraphAdjList.h"
#include "Kruskal.h"
#include "Dijkstra.h"
#include "Floyd.h"
#define MAX 100

bool visited[MAX];
void DFS(MGraph* G, int i)
{
	int j;
	visited[i] = true;
	cout << G->vexs[i] << " ";
	for (j = 0; j < G->numVertexes;j++)
	{
		if (G->arc[i][j] >= 1 && !visited[j])
			DFS(G, j);
	}
}
void DFSTraverse(MGraph* G)//深度优先遍历
{
	int i;
	for (i = 0; i < G->numVertexes; i++)
		visited[i] = false;
	for (i = 0; i < G->numVertexes; i++)
		if (!visited[i])
			DFS(G, i);
	cout << endl;
}
void DFSTraverse_stack(MGraph* G)//深度优先遍历栈实现
{
	int i;
	for (i = 0; i < G->numVertexes; i++)
		visited[i] = false;
	stack<int> S;
	
	for (int j = 0; j < G->numVertexes; j++)
	{
		if (!visited[j])
		{
			visited[j] = true;
			cout << G->vexs[j] << " ";
			S.push(j);

			while (!S.empty())
			{
				for (i = 0; i < G->numVertexes;)
				{
					int top = S.top();
					if (!visited[i] && G->arc[top][i] >= 1)
					{
						cout << G->vexs[i] << " ";
						S.push(i);
						visited[i] = true;

						i = 0;
					}
					else
					{
						i++;
					}
				}
				S.pop();
			}
		}
	}
	cout << endl;
}

//邻接表深度优先
void DFS(GraphAdjList* G, int i)
{
	EdgeNode* p;
	visited[i] = true;
	cout << G->adjList[i].data << " "; 
	p = G->adjList[i].firstedge;
	while (p)
	{
		if (!visited[p->adjvex])
			DFS(G, p->adjvex);
		p = p->next;
	}
}

void DFSTraverse(GraphAdjList* GL)//深度优先遍历
{
	int i;
	for (i = 0; i < GL->numVertexes; i++)
		visited[i] = false;
	//for (i = 0; i < GL->numVertexes; i++)
	//	if (!visited[i])
	//		DFS(GL, i);
	DFS(GL, 3);
}

void BFStraverse(MGraph* G)//广度优先算法邻接矩阵
{
	int i, j;
	queue<int> Q;
	for (i = 0; i < G->numVertexes;i++)
	{
		visited[i] = false;
	}
	for (i = 0; i < G->numVertexes;i++)
	{
		if (!visited[i])
		{
			visited[i] = true;
			cout << G->vexs[i] << " ";
			Q.push(i);
			while (!Q.empty())
			{
				int first = Q.front();
				Q.pop();
				for (j = 0; j < G->numVertexes;j++)
				{
					if (G->arc[first][j] == 1 && !visited[j])
					{
						visited[j] = true;
						cout << G->vexs[j] << " ";
						Q.push(j);
					}
				}
			}
		}
	}
	cout << endl;
}
void BFSTraverse(GraphAdjList* GL)
{
	int i;
	EdgeNode* e;
	queue<int> Q;
	for (i = 0; i < GL->numVertexes;i++)
	{
		visited[i] = false;
	}

	for (i = 0; i < GL->numVertexes; i++)
	{
		if (GL->adjList[i].data == 1 && !visited[i])
		{
			visited[i] = true;
			cout << GL->adjList[i].data << " ";
			Q.push(GL->adjList[i].data);
			
			while (!Q.empty())
			{
				i = Q.front();
				Q.pop();
				e = GL->adjList[i].firstedge;
				while (e)
				{
					if (!visited[e->adjvex])
					{
						visited[e->adjvex] = true;
						cout << GL->adjList[e->adjvex].data << " ";
						Q.push(e->adjvex);
					}
					e = e->next;
				}
			}
		}
	}
}
void MIniSpanTree_Prim(MGraph* G)
{
	
}
vector<Edge> GraphToSortedEdges(MGraph G)
{
	vector<Edge> ret;
	Edge edge;
	for (int i = 0; i < G.numVertexes; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (G.arc[i][j] >= 1)
			{
				edge.begin = i;
				edge.end = j;
				edge.weight = G.arc[i][j];
				ret.push_back(edge);
			}
		}
	}
	sort(ret.begin(), ret.end(), [](Edge &e1, Edge &e2) {return e1.weight < e2.weight; });
	return ret;
}

int main()
{
	MGraph* mGraph = new MGraph;
	CreatMGraph(mGraph);//无向图
	//CreatDMGraph(mGraph);//有向图
	//cout << "********DFS*******" << endl;
	//DFSTraverse(mGraph);
	//DFSTraverse_stack(mGraph);
	//printMGraph(mGraph);
	//cout << "********BFS*******" << endl;
	//BFStraverse(mGraph);
	//Kruscal::miniSpan_Kruskal(mGraph);//求最小生成树
	vector<int> D_P(mGraph->numVertexes),D_D(mGraph->numVertexes);
	vector<vector<int>> F_P(mGraph->numVertexes, D_P), F_D(mGraph->numVertexes, D_D);
	shortestPath_Dijkstra(mGraph, 0, &D_P, &D_D);
	shortestPath_Floyd(mGraph, &F_P, &F_D);
	system("pause");
}