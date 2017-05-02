#include "iostream"
using namespace std;

void print_subset(int, int *, int, char *);

int main() {
	int n;
	cin >> n;
	char c[100];
	for(int i=0; i<n; i++) {
		cin >> c[i];
	}
	int a[100];
	print_subset(n, a, 0, c);
	return 0;
}

void print_subset(int n, int *a, int cur, char *c) {
	if(cur == n) {
		cout << '(';
		for(int i=0; i<cur; i++)
			if(a[i])
				cout << c[i];
		cout << ')';
		return;
	}
	a[cur] = 0;
	print_subset(n, a, cur+1, c);
	a[cur] = 1;
	print_subset(n, a, cur+1, c);
}