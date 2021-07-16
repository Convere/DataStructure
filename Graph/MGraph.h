#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

#define file 1
#define cmd 0

using namespace std;
typedef int VertexType;
typedef int EdgeType;

#define MAXVEX 100
#define INFINITY 65535
typedef struct 
{
	VertexType vexs[MAXVEX];
	EdgeType arc[MAXVEX][MAXVEX];
	int numVertexes, numEdges;
}MGraph;

void CreatMGraph(MGraph* G)
{
#ifdef cin



	int  k, w;
	cout << "请输入顶点和边数：" << endl;
	cin >> G->numVertexes >> G->numEdges;
	cout << "请输入顶点列表：" << endl;
	char vex = 0; int index1 = 0, index2 = 0;
	while (cin >> vex)
	{
		
		char c = getchar();
		G->vexs[index1++] = vex - '0';
		if (c == '\n')
		{
			cout << "输入顶点列表完成,";
			break;
		}
	}
	for (int i = 0; i < G->numVertexes;i++)
	{
		for (int j = 0; j < G->numVertexes;j++)
		{
			if (i == j)
				G->arc[i][j] = 0;
			else
				G->arc[i][j] = INFINITY;
		}
	}
	index1 = 0;
	cout << "请输入边信息：" << endl;
	int ivex;
	while (cin >> index1 >> index2 >> ivex)
	{
		G->arc[index1][index2] = ivex;
		G->arc[index2][index1] = G->arc[index1][index2];
	}
#endif // cin
#ifdef file

	string fileName = "D://mtrix.txt";
	string str;
	ifstream inFile(fileName.c_str());
	getline(inFile, str);
	G->numVertexes = stoi(str.c_str());
	getline(inFile, str);
	G->numEdges = stoi(str.c_str());
	int vex = 0; int index1 = 0, index2 = 0;
	getline(inFile, str);
	stringstream stream(str);
	while (stream >> str)
	{
		G->vexs[index1++] = stoi(str.c_str());
	}
		
	for (int i = 0; i < G->numVertexes; i++)
	{
		for (int j = 0; j < G->numVertexes; j++)
		{
			if (i == j)
				G->arc[i][j] = 0;
			else
				G->arc[i][j] = INFINITY;
		}
	}
	string number;
	index1 = 0;
	while (getline(inFile, str))
	{
		stringstream sstream(str);
		sstream >> number;
		index1 = stoi(number.c_str());
		sstream >> number;
		index2 = stoi(number.c_str());
		sstream >> number;
		G->arc[index1][index2] = stoi(number.c_str());
		G->arc[index2][index1] = G->arc[index1][index2];
	}
#endif // file
}

void CreatDMGraph(MGraph* G)
{
	int  k, w;
	cout << "请输入顶点和边数：" << endl;
	cin >> G->numVertexes >> G->numEdges;
	cout << "请输入顶点列表：" << endl;
	char vex = 0; int index1 = 0, index2 = 0;
	while (cin >> vex)
	{

		char c = getchar();
		G->vexs[index1++] = vex - '0';
		if (c == '\n')
		{
			cout << "输入顶点列表完成,";
			break;
		}

	}
	for (int i = 0; i < G->numVertexes; i++)
	{
		for (int j = 0; j < G->numVertexes; j++)
		{
			if (i == j)
				G->arc[i][j] = 0;
			else
				G->arc[i][j] = INFINITY;
		}
	}
	index1 = 0;
	cout << "请输入边信息：" << endl;
	int ivex;
	while (cin >> index1 >> index2 >> ivex)
	{
		G->arc[index1][index2] = ivex;
		//G->arc[index2][index1] = G->arc[index1][index2];
	}
}

void printMGraph(MGraph *G)
{
	cout << "[";
	for (int i = 0; i < G->numVertexes;i++)
	{
		if (i == G->numVertexes -1)
		{
			cout << G->vexs[i];
		}
		else
			cout << G->vexs[i] << ",";
	}
	cout << "]" << endl;
	cout << "***********************" << endl;
	for (int i = 0; i < G->numVertexes; i++)
	{
		for (int j = 0; j < G->numVertexes; j++)
		{
			cout<< G->arc[i][j] << " ";
		}
		cout << endl;
	}
}