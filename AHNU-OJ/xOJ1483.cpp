/*********************************************

带时限的作业排序问题II

Time Limit:1000MS  Memory Limit:65536K
Total Submit:15 Accepted:8

Description

带时限的作业排序问题可描述为：设有n个作业和一台处理机，每个作业所需的处理时间、要求的时限和收益可用三元组（pi, di, ti），0<=i < n-1表示，其中，作业i的所需时间为ti，如果作业i能够在时限di内完成，将可收益pi，求使得总收益最大的作业子集J。

Input

第一行输入n的值；第二行输入pi；第三行输入di；第四行输入ti （i=0，…，n-1且作业已经按时限非减次序排列）。

Output

xi（用固定长度n-元组xi表示，xi=0或1，i=0，…，n-1）。

Sample Input


4
5 3 6 10
1 1 2 3
1 1 1 2
Sample Output


0 0 1 1

*********************************************/

#include <iostream>
#include <queue>
using namespace std;

struct Node {
    Node(Node *par, int k) {
        parent=par;
        j=k;
    }
    Node *parent;
    int j;
};

struct qNode {
    qNode() {}
    qNode(int p, int los, int sd, int k, Node *pt) {
        prof=p;
        loss=los;
        d=sd;
        ptr=pt;
        j=k;
    }
    int prof, loss;
    int j, d;
    Node *ptr;
};

class JS {
public:
    //JS(int *prof, int *de, int *time, int size);
    JS();
    int JSFIFOBB();
    void GenerateAns();
    void solve() {
        cout << (ans->parent)->j << endl;
    }
private:
    int *p, total;
    int *t, *d, n;
    Node *ans, *root;
};

JS::JS() {
    cin >> n;
    p = new int [n];
    d = new int [n];
    t = new int [n];
    total=0;
    for(int i=0; i<n; i++) {cin >> p[i]; total+=p[i];}
    for(int i=0; i<n; i++) cin >> d[i];
    for(int i=0; i<n; i++) cin >> t[i];
}

int JS::JSFIFOBB() {
    Node *E, *child;
    queue <qNode> q;
    E = root = new Node(NULL, -1);
    qNode ep(0, 0, 0, -1, root), ec;
    int epsilon=0;
    int U=total+epsilon;
    while(1) {
        int loss=ep.loss, prof=ep.prof;
        E=ep.ptr;
        for(int j=ep.j+1; j<n; j++) {
            if(ep.d+t[j]<=d[j] && loss<U) {
                child=new Node(E,j);
                ec.prof=prof+p[j];
                ec.d=ep.d+t[j];
                ec.ptr=child;
                ec.loss=loss;
                ec.j=j;
                q.push(ec);
                int cost=total-ec.prof;
                if(cost<U) {
                    U=cost;
                    ans=root;
                }
            }
            loss+=p[j];
        }
        do {
            if(q.empty()) return total=U;
            ep=q.front();
            q.pop();
        }while(ep.loss>=U);
    }

}


int main() {
    JS js;
    cout << js.JSFIFOBB() << endl;
    js.solve();
    return 0;
}