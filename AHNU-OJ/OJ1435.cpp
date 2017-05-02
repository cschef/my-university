#include <iostream>
using namespace std;

bool Place(int k, int i, int *x) {
	for(int j=0; j<k; j++) {
		if(x[j]==i || abs(x[j]-i)==abs(j-k))
			return false;
	}
	return true;
}

void NQueens(int k, int n, int *x, int &count, int q) {
	int i, j;
	for(i=0; i<n; i++) {
		if(Place(k, i, x)) {
			x[k]=i;
			if(k == n-1) {
				count++;
				if(count == q) {
					for(j=0; j<n; j++)
						cout << x[j]+1;
					cout << endl;
				}
			}
			else NQueens(k+1, n, x, count, q);
		}
	}
}

void NQueens(int n, int *x, int q) {
	int count=0;
	NQueens(0, n, x, count, q);
}

int main() {
	int p, q;
	cin >> p;
	int *x = new int [8];
	for(int i=0; i<p; i++) {
		cin >> q;
		NQueens(8, x, q);
	}
	return 0;
}