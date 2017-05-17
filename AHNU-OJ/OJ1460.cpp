/*********************************************

Minimum-Cost Spanning Tree

Time Limit:1000MS  Memory Limit:65536K
Total Submit:512 Accepted:237

Description

一个无向连通图的生成树是一个极小连通子图，它包括图中全部结点，并且有尽可能少的边。一棵生成树的代价是树中各条边上的代价之和。一个网络的各生成树中，具有最小代价的生成树称为该网络的最小代价生成树（minimum-cost spanning tree）。

Input

第一行输入结点个数n和边的个数m，以下m行输入各边的两个结点u、v及该边上的代价。

Output

如果有生成树，则输出最小生成树的代价；如果没有生成树，则输出"no spanning tree"。

Sample Input


6 10
1 2 10 
1 4 30 
1 5 45 
2 3 50 
2 5 40 
2 6 25 
3 5 35 
3 6 15 
4 6 20 
5 6 55
Sample Output


105

*********************************************/

#include <iostream>
using namespace std;

#define INFTY 32768

struct ENode {
	int adjVex;
	int weight;
	ENode *nextArc;
};

class Graph {
public:
	Graph();
	bool IsConnected();
	void Prim(int s);

	void test() {
		int i;
		cout << endl;
		for(i=0; i<vSize; i++) {
			cout << "a[" << i << "]";
			ENode *p = a[i];
			while(p) {
				cout << "->" << p->adjVex << "(" << p->weight << ")";
				p = p->nextArc;
			}
			cout << endl;
		}
	}
protected:
	ENode **a;
	int vSize, eSize;
	void DFS_Travel(int u, bool *visited);
	void Prim(int k, int *nearest, int *lowcost);
};

Graph::Graph() {
	cin >> vSize >> eSize;

	int i, u, v, w;
	ENode *p, *q;

	a = new ENode* [vSize];
	for(i=0; i<vSize; i++) a[i]=NULL;

	for(i=0; i<eSize; i++) {
		p = new ENode;
		q = new ENode;
		cin >> u >> v >> w;
		u--; v--;
		p->adjVex = u;
		q->adjVex = v;
		p->weight = q->weight = w;
		p->nextArc = a[v];
		a[v] = p;
		q->nextArc = a[u];
		a[u] = q;
	}
}

bool Graph::IsConnected() {
	bool *visited = new bool [vSize];
	for(int i=0; i<vSize; i++) {
		visited[i]=false;
	}
	DFS_Travel(0, visited);
	for(int i=0; i<vSize; i++) {
		if(visited[i] == false) {
			cout << "no spanning tree";
			return false;
		}
	}
	return true;
}

void Graph::DFS_Travel(int u, bool *visited) {
	ENode *w;
	visited[u]=true;
	for(w=a[u]; w; w=w->nextArc) {
		int v=w->adjVex;
		if(visited[v]==false)
			DFS_Travel(v, visited);
	}
}

void Graph::Prim(int s) {
	int *nearest = new int [vSize];
	int *lowcost = new int [vSize];
	Prim(s, nearest, lowcost);
	int cost=0;
	for(int j=0; j<vSize; j++) {
		cost+=lowcost[j];
	}
	cout << cost;
	delete [] nearest;
	delete [] lowcost;
}

void Graph::Prim(int k, int *nearest, int *lowcost) {
	bool *mark = new bool [vSize];
	ENode *p;
	if(k<0 || k>vSize-1) return;
	for(int i=0; i<vSize; i++) {
		nearest[i]=-1;
		mark[i]=false;
		lowcost[i]=INFTY;
	}
	lowcost[k]=0;
	nearest[k]=k;
	mark[k]=true;
	for(int i=0; i<vSize; i++) {
		for(p=a[k]; p; p=p->nextArc) {
			int j=p->adjVex;
			if(! mark[j] && lowcost[j]>p->weight) {
				lowcost[j]=p->weight;
				nearest[j]=k;
			}
		}
		int min=INFTY;
		for(int j=0; j<vSize; j++) {
			if(!mark[j] && lowcost[j]<min) {
				min=lowcost[j];
				k=j;
			}
		}
		mark[k]=true;
	}
}

int main() {
	Graph g;
	//g.test();
	if(g.IsConnected())
		g.Prim(0);
	return 0;
}