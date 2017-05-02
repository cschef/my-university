#include <iostream>
using namespace std;

struct ENode {
	int adjVex;
	ENode *nextArc;
};

class Graph {
public:
	Graph(int v,int e) {
		int i;
		vSize = v;
		eSize = e;
		a = new ENode * [vSize];
		d = new int [vSize];
		Low = new int [vSize];
		for(i=0; i<vSize; i++) {
			d[i] = -1;
			a[i] = NULL;
		}
		for(i=0; i<eSize; i++) {
			int u,v;
			cin >> u >> v;
			ENode *s = new ENode;
			ENode *p = new ENode;
			s->adjVex = v;
			s->nextArc = a[u];
			a[u] = s;
			p->adjVex = u;
			p->nextArc = a[v];
			a[v] = p;
		}
		time = 0;
		num = 0;
	}
	void DFS(int u, int p) {
		Low[u] = d[u] = time++;
		for(ENode *w=a[u]; w; w=w->nextArc) {
			int v=w->adjVex;
			if(d[v] == -1) {
				DFS(v, u);
				if(Low[u] > Low[v]) {
					Low[u] = Low[v];
					num++;
				}
			}
			else {
				if(v!=p && Low[u]>d[v]) {
					Low[u] = d[v];
				}
			}
		}
	}
	void test() {
		int i;
		for(i=0; i<vSize; i++) {
			cout << '(' << d[i] << ',' << Low[i] << ')' << endl;
		}
	}
	void show() {
		int i;
		for(i=0; i<vSize; i++) {
			ENode *p=a[i];
			cout << "a[" << i << "]";
			while(p) {
				cout<<"->"<<p->adjVex;
				p=p->nextArc;
			}
			cout << endl;
		}	
	}
	void solve() {
		cout << num;
	}
protected:
	ENode **a;
	int vSize,eSize;
	int *d, *Low, time;
	int num;
};

int main() {
	int v, e;
	cin >> v >> e;
	Graph g(v, e);
	//g.show();
	g.DFS(0, -1);
	//g.test();
	g.solve();
	return 0;
}
