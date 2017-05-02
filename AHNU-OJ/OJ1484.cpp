#include <iostream>
using namespace std;

int Count(int a[], int n) {
	int count=0;
	int i, j, t;
	for(i=0; i<n; i++) {
		for(j=i+1; j<n; j++) {
			if(a[i] > a[j]) {
				t=a[i]; a[i]=a[j]; a[j]=t;
			}
		}
	}
	for(i=1; i<n; i++) {
		for(j=0; j<i; j++) {
			if(a[j]*2 == a[i])
				count++;
		}
	}
	return count;
}

int main() {
	int num, n;
	int a[15];
	cin >> num;
	while(num != -1) {
		n=0;
		while(num != 0) {
			a[n++] = num;
			cin >> num;
		}
		cout << Count(a, n-1) << endl;
		cin >> num;
	}
	return 0;
}
