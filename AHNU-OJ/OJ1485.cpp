#include <iostream>
using namespace std;

int main() {
	int n, i, j;
	int area=0, c=0;
	cin >> n;
	int **a = new int * [n+2];
	for(i=0; i<n+2; i++)
		a[i] = new int [n+2];
	for(i=0; i<n+2; i++) {
		a[i][0] = a[0][i] = a[i][n-1] = a[n-1][i] = -1;
	}
	for(i=1; i<=n; i++) {
		for(j=1; j<=n; j++) {
			cin >> a[i][j];
		}
	}
	
	//solve
	for(i=1; i<=n; i++) {
		for(j=1; j<=n; j++) {
			if(a[i][j] <= 50)
				area++;
			if(a[i][j] <= 50 && (a[i-1][j]>50 || a[i+1][j]>50 || a[i][j-1]>50 || a[i][j+1]>50))
				c++;
		}
	}
	
	cout << area << " " << c;
	return 0;
} 
