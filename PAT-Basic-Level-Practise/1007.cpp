#include <iostream>
using namespace std;

bool IsPrime(int n) {
	if(n == 2)
		return true;
	for(int i=2; i*i<=n; i++) {
		if(n%i == 0)
			return false;
	}
	return true;
}

int main() {
	int n;
	cin >> n;
	int *a = new int [n];
	int num=0, count=0;
	for(int i=2; i<=n; i++) {
		if(IsPrime(i))
			a[num++] = i;
	}
	for(int i=0; i<num-1; i++) {
		if(a[i+1]-a[i] == 2)
			count++;
	}
	cout << count;
	return 0;
}
