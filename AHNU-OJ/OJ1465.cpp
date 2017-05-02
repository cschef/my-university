#include <iostream>
using namespace std;

void SumOfSub(int s, int k, int r, int **x, int m, int *w, int n, int &count) {
	x[k][1]=1;
	if(s+w[k] == m) {
		count++;
		int i, j;
		for(i=0; i<n; i++) {
			for(j=0; j<=k; j++) {
				if(x[j][0] == i) {
					cout << x[j][1] << " ";
					break;
				}
			}
			if(j > k)
				cout << "0 ";
		}
		cout << endl;
	}
	else if(s+w[k]+w[k+1] <= m)
		SumOfSub(s+w[k], k+1, r-w[k], x, m, w, n, count);
	if(s+r-w[k]>=m && s+w[k+1]<=m) {
		x[k][1]=0;
		SumOfSub(s, k+1, r-w[k], x, m, w, n, count);
	}
}

void SumOfSub(int **x, int n, int m, int *w, int &count) {
	int r=0;
	for(int i=0; i<n; i++)
		r+=w[i];
	if(r>=m && w[0]<=m)
		SumOfSub(0, 0, r, x, m, w, n, count);
}

int main() {
	int n, M, count=0;
	cin >> n >> M;
	int *w = new int [n];
	int **x = new int * [n];
	for(int i=0; i<n; i++)
		x[i] = new int [2];
	for(int i=0; i<n; i++) { 
		cin >> w[i];
		x[i][0]=i;
	}
	int i, j, t;
	for(i=0; i<n; i++) {
		for(j=i+1; j<n; j++) {
			if(w[i] > w[j]) {
				t=w[i]; w[i]=w[j]; w[j]=t;
				t=x[i][0]; x[i][0]=x[j][0]; x[j][0]=t;
			}
		}
	}
	SumOfSub(x, n, M, w, count);
	if(count==0)
		cout << "no solution!";
	return 0;
}
