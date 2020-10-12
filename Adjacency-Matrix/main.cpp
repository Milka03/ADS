#include<iostream>
#include "header.h"
using namespace std;

int main(void) {

	Graph g(4);
	g.addEdge(1, 2, 1);
	g.addEdge(1, 3, 1);
	g.addEdge(1, 4, 1);
	g.addEdge(2, 4, 1);
	g.addEdge(2, 3, 1);
	g.addEdge(3, 4, 1);

	//g.addEdge(2, 1, 1);
	//g.addEdge(3, 3, 1);
	cout << "Graph G:" << endl;
	g.printGraph();
	cout << endl;

	if (g.isTournament() == true)
		cout << "YES - G is a Tournament" << endl << endl;
	else
		cout << "NO - not a Tournament" << endl << endl;
	
	/*cout << endl;
	cout << "Remove edge (3, 4)" << endl;
	g.deleteEdge(3, 4);
	g.printGraph();
	cout << endl;


	cout << "Remove vertex 3" << endl;
	g.deleteVertex(3);
	g.printGraph();
	cout << endl;

	cout << "Remove vertex 4" << endl;
	g.deleteVertex(4);
	g.printGraph();
	cout << endl;
	
	cout << "Add vertex 3" << endl;
	g.addVertex(3);
	g.printGraph();
	cout << endl;

	cout << "Add vertex 4" << endl;
	g.addVertex(4);
	g.printGraph();
	cout << endl;*/



	system("pause");
	return 0;
}