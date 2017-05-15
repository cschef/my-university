/*********************************************

最长公共子序列问题

Time Limit:1000MS  Memory Limit:65536K
Total Submit:846 Accepted:280

Description

给定2个序列X={x1,x2,…,xm}和Y={y1,y2,…,yn}，找出X和Y的最长公共子序列。

Input

第一行输入序列X，第二行输入序列Y。

Output

X和Y的最长公共子序列的长度。

Sample Input


abcbdab
bdcaba
Sample Output


4

*********************************************/

#include <iostream>
using namespace std;

class LCS {
public:
	LCS();
	int LCSLength();
private:
	int **c, m, n;
	char *x, *y;
};

LCS::LCS() {
	string s;
	cin >> s;
	m = s.length();
	x = new char [m+2];
	x[0] = '0'; x[m+1] = '\0';
	for(int i=0; i<m; i++) {
		x[i+1] = s[i];
	}
	cin >> s;
	n = s.length();
	y = new char [n+2];
	y[0] = '0'; y[n+1] = '\0';
	for(int i=0; i<n; i++) {
		y[i+1] = s[i];
	}
	c = new int * [m+1];
	for(int i=0; i<=m; i++) {
		c[i] = new int [n+1];
	}
}

int LCS::LCSLength() {
	int i, j;
	for(i=1; i<=m; i++)
		c[i][0]=0;
	for(i=1; i<=n; i++)
		c[0][i]=0;
	for(i=1; i<=m; i++) {
		for(j=1; j<=n; j++) {
			if(x[i] == y[j]) {
				c[i][j]=c[i-1][j-1]+1;
			}
			else if(c[i-1][j] >= c[i][j-1]) {
				c[i][j]=c[i-1][j];
			}
			else {
				c[i][j]=c[i][j-1];
			}
		}
	}
	return c[m][n];
}

int main() {
	LCS lcs;
	cout << lcs.LCSLength();
	return 0;
}