#include "header.h"
#include <iostream>
using namespace std;


Graph::Graph(int number_V) {
	if (number_V >= MAXSIZE) {
		size = MAXSIZE;
	}
	//vertexcount = number_V;
	size = number_V;
	for (int j = 0; j < size; j++) {
		for (int k = 0; k < size; k++) {
			matrix[j][k] = 0;
		}
	}

	/*matrix = new (nothrow) double*[size];
	for (int i = 0; i < size; i++) {
		matrix[i] = new double[size];
	}
	*/
}

//Graph::~Graph() {
//
//	if (matrix) {
//		for (int i = 0; i < size; i++)
//			delete[] matrix[i];
//	}
//	delete[] matrix;
//}
//
//Graph::Graph(const Graph& g) {
//	size = g.size;
//	matrix = new (nothrow) double*[size];
//	for (int i = 0; i < size; ++i)
//		matrix[i] = new double[size];
//
//	for (int j = 0; j < size; j++) {
//		for (int k = 0; k < size; k++) {
//			matrix[j][k] = g.matrix[j][k];
//		}
//	}
//}


bool Graph::addVertex(int v) {
	
	if (size > MAXSIZE) {
		cout << "Too many vertices!" << endl;
		return false;
	}
	
	for (int i = 0; i < size; i++) {
		matrix[v-1][i] = 0;
	}
	for (int i = 0; i < size; i++) {
		matrix[i][v - 1] = 0;
	}
	return true;
}


void Graph::addEdge(int src, int dest, double weight) {
	
	matrix[src-1][dest-1] = weight;
}


void Graph::deleteVertex(int v) {
	
	if (v > size) {
		cout << "There is no vertex: " << v << endl;
	}
	if (v == size) {
		size = size - 1;
		for (int j = 0; j < size; j++) {
			matrix[j][v - 1] = -MAXSIZE;
		}
	}
	//size = size - 1;
	for (int i = 0; i < size; i++) {
		matrix[v-1][i] = -MAXSIZE;
		matrix[i][v-1] = -MAXSIZE;
	}

}


void Graph::deleteEdge(int src, int dest) {
	
	matrix[src-1][dest-1] = 0;
}


bool Graph::isVertex(int v)
{
	
	if (matrix[v - 1][0] == -MAXSIZE)
		return false;
			
	//return true;
}


void Graph::printGraph() {
	for (int i = 0; i < size; i++) {
		if (isVertex(i + 1) == false)
			continue;
		std::cout << i+1 << ":  ";
		for (int j = 0; j < size; j++) {
			if (matrix[i][j] == -MAXSIZE)
				continue;
			cout << matrix[i][j] << "    ";
		}
		cout << endl;
	}
}



bool Graph::isTournament()
{
	for (int i = 0; i < size; i++) {
		if (matrix[i][i] != 0)
			return false;
	}
	
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < i; j++) {

			if ((matrix[i][j] != 0 && matrix[j][i] == 0) || (matrix[i][j] == 0 && matrix[j][i] != 0))
				continue;
			else
				return false;
		}
	}
	return true;
}