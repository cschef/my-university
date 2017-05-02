#include <iostream>
using namespace std;

struct ENode {
	int adjVex;
	ENode *nextArc;
};

class Graph {
public:
	Graph(int vSize, int eSize);
	void show();
	void DFS();
protected:
	ENode **a;
	int v, e;
	void DFS_Traverse(int u, int *visited);
};

Graph::Graph(int vSize, int eSize) {
	v = vSize;
	e = eSize;
	a = new ENode * [v];
	for(int i=0; i<v; i++) {
		a[i] = NULL;
	}
	for(int i=0; i<e; i++) {
		int m, n;
		ENode *p;
		p = new ENode;
		cout << "Arc[" << i << "]: ";
		cin >> m >> n;
		p->adjVex = n;
		p->nextArc = a[m];
		a[m] = p;
		p = new ENode;
		p->adjVex = m;
		p->nextArc = a[n];
		a[n] = p;
	}
}

void Graph::show() {
	ENode *p;
	for(int i=0; i<v; i++) {
		p = a[i];
		cout << "a[" << i << "]";
		while(p) {
			cout << "->" << p->adjVex;
			p = p->nextArc;
		}
		cout << endl;
	}
}

void Graph::DFS() {
	int *visited = new int [v];
	for(int i=0; i<v; i++) {
		visited[i] = -1;
	}
	cout << "DFS: ";
	for(int i=0; i<v; i++) {
		if(visited[i] == -1)
			DFS_Traverse(i, visited);
	}
	cout << endl;
}

void Graph::DFS_Traverse(int u, int *visited) {
	cout << " " << u;
	for(ENode *w=a[u]; w; w=w->nextArc) {
		int v = w->adjVex;
		if(visited[u] == -1)
			DFS_Traverse(u, visited);
	}
}

int main() {
	int v, e;
	cout << "v=";
	cin >> v;
	cout << "e=";
	cin >> e;
	Graph g(v, e);
	g.show();
	g.DFS();
	return 0;
}
