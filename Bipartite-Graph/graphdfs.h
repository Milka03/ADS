#pragma once
#include<iostream>
#include <list>
#include <queue>
using namespace std;

class Graph {
private:
	std::list<int> V;
	std::list<int>* adj;

	void DFSRec(int v, bool* visited);

public:
	Graph(int number_V);
	void addVertex(int v);
	void addEdge(int v, int w);
	void deleteVertex(int v);
	void deleteEdge(int v, int w);
	void printAdj();

	bool isVertex(int v);
	bool isEdge(int a, int b);
	void DFS(int v);	// Depth First Search
	void BFS(int v);	// Breadth First Search
	
	bool isBipartite();
	Graph Gsquared();
	
};