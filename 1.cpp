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