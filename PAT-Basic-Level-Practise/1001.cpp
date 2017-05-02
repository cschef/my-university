#include <iostream>
using namespace std;

int Steps(int n) {
	static int count=0;
	if(n == 1)
		return count;
	if(n%2 == 0) {
		count++;
		Steps(n/2);
	}
	else {
		count++;
		Steps((n*3+1)/2);
	}
}

int main() {
	int n;
	cin >> n;
	cout << Steps(n);
	return 0;
} 
