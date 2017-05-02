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
