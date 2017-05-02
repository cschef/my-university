#include <iostream>
using namespace std;

struct ENode {
	int adjVex;
	ENode *nextArc;
};

class Graph {
public:
	Graph(int v,int e) {
		vSize = v;
		eSize = e;
		a = new ENode * [vSize];
		visited = new int [vSize];
		for(int i=0; i<vSize; i++) {
			visited[i] = -1;
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
	}
	void DFS() {
		int i;
		cout<<"DFS:";
		for(i=0;i<vSize;i++) {
			if(visited[i]==-1)
				DFS_Travel(i);
		}
		cout<<endl;
	}
	void show() {
		int i;
		for(i=0;i<vSize;i++) {
			ENode *p=a[i];
			cout<<"a["<<i<<"]";
			while(p) {
				cout<<"->"<<p->adjVex;
				p=p->nextArc;
			}
			cout<<endl;
		}	
	}

protected:
	void DFS_Travel(int u) {
		ENode *w;
		cout << u << " ";
		visited[u]=0;
		for(w=a[u];w;w=w->nextArc) {
			int v=w->adjVex;
			if(visited[v]==-1)
				DFS_Travel(v);
		}
	}
	ENode **a;
	int vSize,eSize;
	int *visited;
};

int main() {
	int v, e;
	cin >> v >> e;
	Graph g(v, e);
	g.show();
	g.DFS();
	return 0;
}