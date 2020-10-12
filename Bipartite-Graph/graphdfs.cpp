#include "graphdfs.h"
#include <iostream>


Graph::Graph(int number_V) {
	for (int i = 0; i < number_V; i++)
		V.push_back(i);
	adj = new std::list<int>[1024];
}

void Graph::addVertex(int v) {
	V.push_back(v);
}

void Graph::addEdge(int v, int w) {
	adj[v].push_back(w);
	adj[w].push_back(v);
}

void Graph::deleteVertex(int v) {
	for (auto it = adj[v].begin(); it != adj[v].end(); it++) {
		adj[*it].remove(v);
	}
	adj[v].erase(adj[v].begin(), adj[v].end());
	V.remove(v);
}

void Graph::deleteEdge(int v, int w) {
	adj[v].remove(w);
	adj[w].remove(v);
}

void Graph::printAdj() {
	for (auto i : V) {
		std::cout << i << " ->  ";
		for (auto it : adj[i])
			std::cout << it << " ";
		std::cout << "\n";
	}
}

void Graph::DFSRec(int v, bool* visited) {
	if (visited[v] == false)
		std::cout << v << " ";
	visited[v] = true;

	for (auto it = adj[v].begin(); it != adj[v].end(); it++)
		if (!visited[*it])
			DFSRec(*it, visited);
}


void Graph::DFS(int v) {
	bool* visited = new bool[V.size()];
	for (int i = 0; i < V.size(); i++)
		visited[i] = false;
	visited[v] = true;
	std::cout << v << " ->  ";
	DFSRec(v, visited);
	std::cout << std::endl;
	delete visited;
}


void Graph::BFS(int v) {
	bool* visited = new bool[V.size()];
	for (int i = 0; i < V.size(); i++)
		visited[i] = false;

	std::list<int> queue;
	visited[v] = true;
	queue.push_back(v);
	std::cout << queue.front() << " ->  ";

	while (!queue.empty()) {
		for (auto it = adj[queue.front()].begin(); it != adj[queue.front()].end(); it++) {
			if (!visited[*it]) {
				visited[*it] = true;
				queue.push_back(*it);
			}
		}
		if (queue.front() != v)
			std::cout << queue.front() << " ";
		queue.pop_front();
	}
	delete visited;
	std::cout << std::endl;
}



bool Graph::isEdge(int a, int b) 
{
	for (auto it : adj[a]) {
		if (it == b)
			return true;
	}
	return false;
}


bool Graph::isVertex(int a)
{
	for (auto i : V) {
		if (i == a)
			return true;
	}
	return false;
}


bool Graph::isBipartite()
{
	int* colors = new int[V.size()];
	for (int i = 0; i < V.size(); ++i)
		colors[i] = -1;

	//std::list<int> queue;
	std::queue<int> queue;
	colors[V.front()] = true;
	queue.push(V.front());
	std::cout << queue.front() << " ->  ";

	while (!queue.empty()) {
		int u = queue.front();
		std::cout << queue.front() << " ";
		queue.pop();

		if (isEdge(u, u) == 1)
			return false;
		for (auto v : V)
		{
			if (isEdge(u,v) && colors[v] == -1)
			{
				colors[v] = 1 - colors[u];
				queue.push(v);
			}
			else if (isEdge(u, v) && colors[v] == colors[u])
				return false;
		}
	}
	delete colors;
	std::cout << std::endl;
	return true;
}



Graph Graph::Gsquared()
{
	Graph tmp(V.size());
	list<int> comp;
	int k = 0;
	for (int i = 0; i < V.size(); i++) {
		for (auto it : adj[i]) {
			tmp.adj[i].push_back(it);
			//comp[i].push_back(*it);
		}
	}
	for (auto v : V) {
		for (auto it : adj[v]) {

			for (int k = v + 1; k < V.size(); k++) {
				if (it == k)
					continue;
				for (auto cp : adj[k]) {
					if (it == cp) {
						if (tmp.isEdge(v, k))
							continue;
						else
							tmp.addEdge(v, k);
					}

				}
			}
		}
	}
	return tmp;
}