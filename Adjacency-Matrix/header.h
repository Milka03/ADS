#pragma once


#include<iostream>
#include <list>
#include <queue>
#define MAXSIZE 100
using namespace std;


class Graph {
private:

	//int vertexcount;
	int size;
	double matrix[MAXSIZE][MAXSIZE];

	

public:
	Graph(int number_V);
	//~Graph();
	//Graph(const Graph& g);

	bool addVertex(int v);
	void addEdge(int src, int dest, double weight);

	void deleteVertex(int v);
	void deleteEdge(int src, int dest);
	void printGraph();

	bool isVertex(int v);

	bool isTournament();

};