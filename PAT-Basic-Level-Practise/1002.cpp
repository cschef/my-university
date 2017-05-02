#include <iostream>
using namespace std;

const char *digit[] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};

void Input(int &sum) {
	char c[101];
	cin >> c;
	for(int i=0; c[i] != '\0'; i++) {
		sum += c[i]-'0';
	}
}

void Output(int sum) {
	if(sum == 0)
		return;
	Output(sum/10);
	if(sum/10 == 0)
		cout << digit[sum];
	else
		cout << " " << digit[sum%10];
}

int main() {
	int sum=0;
	Input(sum);
	Output(sum);
	return 0;
} 
