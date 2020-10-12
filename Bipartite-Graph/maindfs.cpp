#include<iostream>
#include "graphdfs.h"
using namespace std;

int main(void) {

	Graph g(6);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 3);
	g.addEdge(2, 3);
	g.addEdge(2, 4);
	g.addEdge(3, 5);
	g.addEdge(4, 5);
	g.addEdge(1, 5);
	g.printAdj();

	/*g.printAdj();
	cout << endl;
	cout << "Remove edge (1, 3)" << endl;
	g.deleteEdge(1, 3);
	cout << endl;
	cout << "Remove edge (1, 2)" << endl;
	g.deleteEdge(1, 2);
	g.printAdj();
	cout << endl;

	cout << "Remove vertex 3" << endl;
	g.deleteVertex(3);
	g.printAdj();
	cout << endl;
	
	cout << "Add vertex 3" << endl;
	g.addVertex(3);
	g.printAdj();*/


	cout << endl << endl << "BFS for G:" << endl;
	g.BFS(0);
	cout << "Is G bipartite?" << endl;
	if (g.isBipartite() == true) cout << "YES" << endl << endl;
	else cout << "NO" << endl << endl;
	cout << "Graph P:" << endl;
	Graph P(6);
	P.addEdge(0, 4);
	P.addEdge(0, 2);
	P.addEdge(0, 3);
	P.addEdge(2, 5);
	P.addEdge(1, 4);
	P.addEdge(3, 5);
	P.addEdge(4, 5);
	P.printAdj();

	cout << endl << "BFS for P:" << endl;
	P.BFS(0);
	cout << "Is P bipartite?" << endl;
	if (P.isBipartite() == true) cout << "YES" << endl << endl;
	else cout << "NO" << endl << endl;

	system("pause");
	return 0;
}