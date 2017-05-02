#include <iostream>
using namespace std;

bool IsPrime(long n) {
	if(n == 2)
		return true;
	for(long i=2; i*i<=n; i++) {
		if(n%i == 0)
			return false;
	}
	return true;
}

int main() {
	int m, n;
	cin >> m >> n;
	int i=1, count=0;
	for(long j=2; i<=n; j++) {
		if(IsPrime(j) && i++>=m) {
			if(++count%10 == 1)
				cout << j;
			else {
				if(count%10 == 0)
					cout << '\n';
				else
					cout << ' ' << j;
			}
		}
	}
	return 0;
}
