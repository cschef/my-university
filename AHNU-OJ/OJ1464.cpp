/*********************************************

NQeens

Time Limit:1000MS  Memory Limit:65536K
Total Submit:455 Accepted:288

Description

n-皇后问题要求在一个n*n的棋盘上放置n个皇后，使得它们彼此不受“攻击”。观察表明n-皇后问题的解存在垂直对偶性，请修改教材算法NQeens，令x[0]=1，2，……，[n/2]，使得只求其中不对称的那些解。

Input

n的值。

Output

不对称的那些解。

Sample Input


4
Sample Output


1 3 0 2
Hint

4-皇后全部的解为 
1 3 0 2 
2 0 3 1

*********************************************/

#include <iostream>
using namespace std;

bool Place(int k, int i, int *x) {
	for(int j=0; j<k; j++) {
		if(x[j]==i || abs(x[j]-i)==abs(j-k))
			return false;
	}
	return true;
}

void NQueens(int k, int n, int *x) {
	int i, j;
	for(i=0; i<(k==0?n/2:n); i++) {
		if(Place(k, i, x)) {
			x[k]=i;
			if(k == n-1) {
				for(j=0; j<n; j++)
					cout << x[j] << ' ';
				cout << endl;
			}
			else NQueens(k+1, n, x);
		}
	}
}

void NQueens(int n, int *x) {
	NQueens(0, n, x);
}

int main() {
	int n;
	cin >> n;
	int *x = new int [n];
	NQueens(n, x);
	return 0;
}