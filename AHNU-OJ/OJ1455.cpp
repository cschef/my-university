/*********************************************

关节点问题

Time Limit:1000MS  Memory Limit:65536K
Total Submit:719 Accepted:271

Description

对于一个给定的连通图G，采用深度优先搜索的方法，识别出G的所有关节点。

Input

第一行输入结点个数n和边的个数m，下面m行输入各边。

Output

关节点个数

Sample Input


8 10
0 3
0 2
2 3
1 2
2 4
1 4
1 6
5 6
5 7
6 7
Sample Output


3

*********************************************/

// wrong
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



#include<iostream>
#include<malloc.h> 
using namespace std;
#define MAX 50
int Low[MAX],d[MAX]; 
typedef struct Anode
{
    int adjvex;
    struct Anode *nextarc;
}ArcNode[MAX]; 
typedef struct
{
    ArcNode vertices;
    int vexnum,arcnum; 
}ALGraph;
ALGraph G=*((ALGraph *)malloc(sizeof(ALGraph)));
void DFS(int u,int p)
{
    static int time=0;
    int v;
    Low[u]=d[u]=time++;
    for(Anode *w=&(G.vertices[u]);w;w=w->nextarc)
    {
        v=w->adjvex;
        if(d[v]==-1)
        {
            DFS(v,u);
            if( Low[u]>Low[v])   Low[u]=Low[v];
        }
            else if(v!=p&&Low[u]>d[v])  Low[u]=d[v];
    }
} 
int main()
{
     
    int i,j,k,n,m,l=0,u,count=0;
    Anode *N;
    cin>>n>>m;
    for(u=0;u<n;u++)
    {
        d[u]=-1;
        G.vertices[u].adjvex=u;
        G.vertices[u].nextarc=NULL;
    }
        for(k=0;k<m;k++)
        {
			cin>>i>>j;
            N=(Anode *)malloc(sizeof(Anode));
            N->adjvex=j;
            N->nextarc=G.vertices[i].nextarc;
            G.vertices[i].nextarc=N;
            N=(Anode *)malloc(sizeof(Anode));
            N->adjvex=i;
            N->nextarc=G.vertices[j].nextarc;
            G.vertices[j].nextarc=N;
        } 
        DFS(0,-1);
        for(i=0;i<n;i++)
        {
            for(Anode *w=G.vertices[i].nextarc;w;w=w->nextarc)
            {  
                if(Low[w->adjvex]>=d[i]&&i!=0)
                {
                    count++;
                    break;
                }
            }      
        }
        cout<<count<<endl;
    return 0;
}