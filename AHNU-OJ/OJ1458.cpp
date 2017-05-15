/*********************************************

部分背包问题

Time Limit:1000MS  Memory Limit:65536K
Total Submit:839 Accepted:329

Description

已知一个载重为M的背包和n件物品，第i件物品的重量为 wi，如果将第i件物品全部装入背包，将有收益pi，这里，wi>0，pi>0。所谓背包问题是指求一种最佳装载方案，使得收益最大。

Input

第一行物品个数n和背包载重M，以下n行输入物品编号i，物品收益pi，物品重量wi。

Output

x1,x2,…,xn，0<=xi<=1，每个xi是第i件物品装入背包中的部分（小数位保留二位）。

Sample Input


3 20
1 25 18
2 24 15
3 15 10
Sample Output


0.00 1.00 0.50

*********************************************/

#include <iostream>
using namespace std;

class Knapsack {
public:
	Knapsack();
	void GreedyKnapsack();
	void Sort();
	void Sort1();
	void Solve();
private:
	float m, *w, *p, *x;
	int n, *no;
};

Knapsack::Knapsack() {
	cin >> n;
	cin >> m;
	int i;
	no=new int [n];
	w=new float [n];
	p=new float [n];
	x=new float [n];
	for(i=0; i<n; i++) {
		cin >> no[i] >> p[i] >> w[i];
	}
}

void Knapsack::GreedyKnapsack() {
	float u=m;
	int i;
	for(i=0; i<n; i++) {
		x[i]=0;
	}
	for(i=0; i<n; i++) {
		if(w[i]>u)
			break;
		x[i]=1.0;
		u=u-w[i];
	}
	if(i<n)
		x[i]=u/w[i];
}

void Knapsack::Sort() {
	float p1, w1;
	int no1, i, j;
	for(i=0; i<n; i++) {
		for(j=i+1; j<n; j++) {
			if(p[i]/w[i] < p[j]/w[j]) {
				no1=no[i]; p1=p[i]; w1=w[i];
				no[i]=no[j]; p[i]=p[j]; w[i]=w[j];
				no[j]=no1; p[j]=p1; w[j]=w1;
			}
		}
	}
}

void Knapsack::Sort1() {
	float p1, w1, x1;
	int no1, i, j;
	for(i=0; i<n; i++) {
		for(j=i+1; j<n; j++) {
			if(no[i] > no[j]) {
				no1=no[i]; x1=x[i]; p1=p[i]; w1=w[i]; 
				no[i]=no[j]; x[i]=x[j]; p[i]=p[j]; w[i]=w[j];
				no[j]=no1; x[j]=x1; p[j]=p1; w[j]=w1;
			}
		}
	}
}

void Knapsack::Solve() {
	for(int i=0; i<n; i++) {
		printf("%.2f ",x[i]);
	}
}

int main() {

	Knapsack k;

	k.Sort();

	k.GreedyKnapsack();

	k.Sort1();

	k.Solve();

	return 0;
}