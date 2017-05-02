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