#include <iostream>

#include "graph.h"

Graph::Graph(int vertices)
{
	size = vertices;

	for (int i = 0; i < vertices; i++) {
		//cout << "test" << endl;
		graph[i].push_back(i);
		graph[i].resize(1);
	}
}

void Graph::addEdge(int src, int dest)
{
	graph[src].push_back(dest);
	graph[dest].push_back(src);
}

void Graph::removeEdge(int v, int w)
{
	if (is_vertex(v) == false || is_vertex(w) == false) {
		cout << "There is no vertex " << v << " or " << w << endl;
		return;
	}
	list<int>::iterator it;
	for (it = next(graph[v].begin()); it != graph[v].end(); it++) {
		if (*it == w) {
			graph[v].remove(w);
			graph[w].remove(v);
			return;
		}
	}
	cout << "There is no edge (" << v << ", " << w << ")" << endl;
}

void Graph::addVertex(int v)
{
	//check if graph contains v
	if (is_vertex(v) == true) {
		cout << "Graph already contains vertex " << v << endl;
		return;
	}
	//if not add it
	graph[v].push_back(v);
	graph[v].resize(1);
}

void Graph::removeVertex(int ver)
{
	if (size < 1) {
		cout << "Graph is empty" << endl;
		return;
	}

	if (is_vertex(ver) == false) {
		cout << "There is no vertex " << ver << endl;
		return;
	}

	//delete vertex
	list<int>::iterator it;
	for (it = next(graph[ver].begin()); it != graph[ver].end(); it++) {
		graph[*it].remove(ver);
		//graph[w].remove(v);
	}
	graph[ver].clear();
}


bool Graph::is_vertex(int a)
{
	for (int i = 0; i < size; i++) {
		if (graph[i].size() == 0)
			continue;
		if (graph[i].front() == a) {
			return true;
		}
	}
	return false;
}


void Graph::printGraph()
{
	for (int v = 0; v < size; v++)
	{
		if (graph[v].size() == 0)
			continue;
		cout << graph[v].front() << ": ";
		if (graph[v].size() == 1) {
			cout << endl;
			continue;
		}
		else {
			list<int>::iterator it = next(graph[v].begin());
			while (it != graph[v].end()) {
				cout << " -> " << *it;
				it++;
			}
		}
		cout << endl;
	}
}


Graph Graph::Gsquared(Graph& g)
{
	Graph tmp(g.size);
	list<int> comp;
	//int val = 0;
	int k = 0;
	for (int i = 0; i < g.size; i++) {
		list<int>::iterator it; 
		for (it = next(g.graph[i].begin()); it != g.graph[i].end(); it++) {
			tmp.graph[i].push_back(*it);
			//comp[i].push_back(*it);

		}
	}

	for (int j = 0; j < g.size; j++) {
		list<int>::iterator it, cp;
		for (it = next(g.graph[j].begin()); it != g.graph[j].end(); it++) {
			if ( j + 1 < g.size)
				k = j + 1;
			
			for (cp = next(g.graph[k].begin()); cp != g.graph[k].end(); cp++) {
				if (*it == k)
					break;
				else if (*it == *cp)
					tmp.addEdge(j, k);
			}
			
			
		}
	}

	return tmp;
}