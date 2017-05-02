#include <iostream>
using namespace std;

int m2ten(int n, int m) {
	int sum=0, x=1;
	while(n) {
		sum+=n%10*x;
		x*=m;
		n/=10;
	}
	return sum;
}

void ten2m(int n, int m) {
	if(n==0)
		return;
	else {
		ten2m(n/m, m);
		cout << n%m;
	}
}

int fun(int n) {
	if(n==1)
		return 1;
	else
		return n*fun(n-1);
}

int main() {
	int m, n;
	cin >> m >> n;
	ten2m(fun(m2ten(n, m)), m);
	return 0;
}