#include <iostream>
#include <queue>
#include <stack>
#include <iterator>
#include "MGraph.h"
#include "GraphAdjList.h"
#include "Kruskal.h"
#define MAX 100

using namespace std;

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
void DFSTraverse(MGraph* G)//������ȱ���
{
	int i;
	for (i = 0; i < G->numVertexes; i++)
		visited[i] = false;
	for (i = 0; i < G->numVertexes; i++)
		if (!visited[i])
			DFS(G, i);
	cout << endl;
}
void DFSTraverse_stack(MGraph* G)//������ȱ���ջʵ��
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

//�ڽӱ��������
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

void DFSTraverse(GraphAdjList* GL)//������ȱ���
{
	int i;
	for (i = 0; i < GL->numVertexes; i++)
		visited[i] = false;
	//for (i = 0; i < GL->numVertexes; i++)
	//	if (!visited[i])
	//		DFS(GL, i);
	DFS(GL, 3);
}

void BFStraverse(MGraph* G)//��������㷨�ڽӾ���
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
	edges = GraphToSortedEdges(*G);
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
void Array(int* nums,int length)
{
	for (int i = 0; i < length;i++)
	{
		*(nums++) = 3;
	}
	
}
int main()
{
	MGraph* mGraph = new MGraph;
	CreatMGraph(mGraph);//����ͼ
	//CreatDMGraph(mGraph);//����ͼ
	//cout << "********DFS*******" << endl;
	//DFSTraverse(mGraph);
	//DFSTraverse_stack(mGraph);
	//printMGraph(mGraph);
	//cout << "********BFS*******" << endl;
	//BFStraverse(mGraph);
	Kruscal::miniSpan_Kruskal(mGraph);
	system("pause");
}