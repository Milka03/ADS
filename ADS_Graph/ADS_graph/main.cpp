#include <iostream>
#include <algorithm>
#include <list>
#include <vector>
#include <iomanip>
#include <iterator> 
#include "graph.h"

using namespace std;

int main()
{
	Graph mygraph(6);
	Graph G(6);

	mygraph.addEdge(0, 5);
	mygraph.addEdge(1, 2);
	mygraph.addEdge(2, 3);
	mygraph.addEdge(3, 4);
	mygraph.addEdge(4, 5);
	mygraph.addEdge(1, 4);
	mygraph.addEdge(1, 5);

	mygraph.printGraph();
	cout << endl;
	cout << "Remove edge (1, 3)" << endl;
	mygraph.removeEdge(1, 3);
	cout << endl;
	cout << "Remove edge (1, 2)" << endl;
	mygraph.removeEdge(1, 2);
	mygraph.printGraph();
	cout << endl;

	cout << "Remove vertex 3" << endl;
	mygraph.removeVertex(3);
	mygraph.printGraph();
	cout << endl;
	cout << "Add vertex 4" << endl;
	mygraph.addVertex(4);
	cout << endl;
	cout << "Add vertex 3" << endl;
	mygraph.addVertex(3);
	mygraph.printGraph();
	cout << endl << endl << "G suared:" << endl;
	

	G.addEdge(0, 5);
	G.addEdge(1, 2);
	G.addEdge(2, 3);
	G.addEdge(3, 4);
	G.addEdge(4, 5);
	G.addEdge(1, 4);
	G.addEdge(1, 5);

	Graph H = mygraph.Gsquared(G);
	H.printGraph();


	system("pause");
	return 0;
}