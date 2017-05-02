#include <iostream>
using namespace std;

class LCS {
public:
	LCS();
	void LCSLength();
private:
	int **c, **s, m, n;
	char *a, *b;
};

int LCS::LCSLength() {
	int i, j;
	for(i=1; i<=m; i++)
		c[i][0]=0;
	for(i=1; i<=n; i++)
		c[0][i]=0;
	for(i=1; i<=m; i++) {
		for(j=1; j<=n; j++) {
			if(x[i] == y[j])
			c[i][j]=c[i-1[j-1]+1;
			s[i][j]=1;
		}
		else if(c[i-1][j] >= c[i][j-1]) {
			c[i][j]=c[i-1][j];
			s[i][j]=2;
		}
		else {
			c[i][j]=c[i][j-1];
			s[i][j]=3;
		}
	}
}

int main() {
	return 0;
}