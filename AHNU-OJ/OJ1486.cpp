#include <iostream>
using namespace std;

int main() {
	char s[20];
	cin >> s;
	while(strcmp(s, "ENDOFINPUT")) {
		if(!strcmp(s, "START") || !strcmp(s, "END"))
			cin >> s;
		
	}
	return 0;
} 
