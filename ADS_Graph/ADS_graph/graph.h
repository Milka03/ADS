#pragma once

#ifndef GRAPH_HEADER
#define GRAPH_HEADER

#include <iostream>
#include <list>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <iterator> 
#define MAXVAL 1024

using namespace std;

//typedef vector<int> Vertex;


class Graph
{
	int size;
	list<int> graph[MAXVAL];

public:
	Graph(int vertices);
	~Graph() {};
	void addEdge(int src, int dest);
	void removeEdge(int v, int w);
	void addVertex(int v);
	void removeVertex(int ver);

	bool is_vertex(int a);

	void printGraph();

	Graph Gsquared(Graph& g);
};




#endif /* GRAPH_HEADER */