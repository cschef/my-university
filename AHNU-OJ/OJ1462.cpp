/*********************************************

矩阵连乘问题

Time Limit:1000MS  Memory Limit:65536K
Total Submit:455 Accepted:306

Description

给定n个矩阵{A0,A1,…,An-1}， 其中Ai，i=0,…,n-1的维数为pi*pi+1，并且Ai与Ai+1是可乘的。考察这n个矩阵的连乘积A0A1…An-1，由于矩阵乘法满足结合律，所以计算矩阵的连乘可有许多不同的计算次序。矩阵连乘问题是确定计算矩阵连乘积的计算次序，使得按照这一次序计算矩阵连乘积，需要的“数乘”次数最少。

Input

第一行输入n的值，第二行输入n个矩阵的维数pi（i=0，…，n）。

Output

最少乘法次数。

Sample Input


6
30 35 15 5 10 20 25
Sample Output


15125

*********************************************/

#include <iostream>
using namespace std;

class MatrixChain {
public:
	MatrixChain() {
		int i;
		cin >> n;
		p = new int [n+1];
		for(i=0; i<=n; i++) {
			cin >> p[i];
		}
		m = new int * [n];
		for(i=0; i<n; i++)
			m[i] = new int [n];
		s = new int * [n];
		for(i=0; i<n; i++)
			s[i] = new int [n];
	}
	int MChain();
	//int LookupChain();
	//void Traceback();
private:
	int *p, **m, **s, n;
	//int LookupChain(int i, int j);
	//void Traceback(int i, int j);
};

int MatrixChain::MChain() {
	int i, j, r, k, t;
	for(i=0; i<n; i++) {
		m[i][i]=0;
	}
	for(r=2; r<=n; r++) {
		for(i=0; i<=n-r; i++) {
			j=i+r-1;
			m[i][j]=m[i+1][j]+p[i]*p[i+1]*p[j+1];
			s[i][j]=i;
			for(k=i+1; k<j; k++) {
				t=m[i][k]+m[k+1][j]+p[i]*p[k+1]*p[j+1];
				if(t < m[i][j]) {
					m[i][j]=t;
					s[i][j]=k;
				}
			}
		}
	}
	return m[0][n-1];
}

int main() {
	MatrixChain mc;
	cout << mc.MChain();
	return 0;
}