#include <iostream>
using namespace std;

struct ENode {
	int adjVex;
	int weight;
	ENode *nextArc;
};

class Graph {
public:
	Graph(int v, int e) {
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

	int FMultiGraph() {
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

int main() {
	int v, e;
	cin >> v >> e;
	Graph g(v, e);
	//g.test();
	cout << g.FMultiGraph();
	return 0;
}