/*********************************************

多段图问题

Time Limit:1000MS  Memory Limit:65536K
Total Submit:405 Accepted:269

Description

多段图G=(V,E)是一个带权有向图，它具有如下特性：图中的结点被划分成k>=2个互不相交的子集Vi，1<=i<=k。其中V1和Vk分别只有一个结点，V1包含源点（source）s，Vk包含汇点（sink）t。对所有边属于E，多段图要求若u属于Vi，则v属于Vi＋1，1<=i< k，每条边的权值为c(u,v)。从s到t的路径长度是这条路径上边的权值之和，多段图问题（multistage graph problem）是求从s到t的一条长度最短的路径。

Input

第一行输入结点个数n和边的个数m，以下m行输入各有向边的两个结点u、v及该边上的代价。

Output

从s到t的最短的路径的长度。

Sample Input


4 4
0 1 5
0 2 1
1 3 3
2 3 10
Sample Output


8

*********************************************/

#include <iostream>
using namespace std;

struct ENode {
	int adjVex;
	int weight;
	ENode *nextArc;
};

class Graph {
public:
	Graph(int v, int e);
	int FMultiGraph();

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
};

Graph::Graph(int v, int e) {
	vSize=v; eSize=e;

	int i, u;
	ENode *p;

	a = new ENode* [vSize];
	for(i=0; i<vSize; i++) a[i]=NULL;

	for(i=0; i<eSize; i++) {
		p = new ENode;
		cin >> u >> p->adjVex >> p->weight;
		p->nextArc = a[u];
		a[u] = p;
	}
}

int Graph::FMultiGraph() {
	int c, *cost=new int [vSize];
	int q, *d=new int [vSize], *p=new int [vSize];
	int j, v, min;
	cost[vSize-1]=0; d[vSize-1]=-1;
	for(j=vSize-2; j>=0; j--) {
		min = 32768;
		for(ENode *r=a[j]; r; r=r->nextArc) {
			v=r->adjVex;
			if(r->weight + cost[v] < min) {
				min = r->weight + cost[v];
				q = v;
			}
		}
		cost[j]=min; d[j]=q;
	}
	c=cost[0];
	delete [] cost; delete [] d; return c;
}

int main() {
	int v, e;
	cin >> v >> e;
	Graph g(v, e);
	//g.test();
	cout << g.FMultiGraph();
	return 0;
}