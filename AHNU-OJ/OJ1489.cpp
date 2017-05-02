#include <iostream>
using namespace std;

int main() {
	int e[12][4]={
		{3,21,4,19},{4,20,5,20},{5,21,6,21},{2,19,3,20},
		{7,23,8,22},{8,23,9,22},{9,23,10,23},{6,22,7,22},
		{11,22,12,21},{12,22,1,19},{1,20,2,18},{10,24,11,21}};
	int n;
	cin >> n;
	int **m = new int * [n];
	int i, j, tag1, tag2;
	for(j=0; j<n; j++) {
		m[j] = new int [4];
		for(i=0; i<4; i++)
			cin >> m[j][i];
	}
	for(j=0; j<n; j++) {
		for(i=0; i<12; i++) {
			if((m[j][0]==e[i][0]&&m[j][1]>=e[i][1])||(m[j][0]==e[i][2]&&m[j][1]<=e[i][3]))
				tag1=i;
			if((m[j][2]==e[i][0]&&m[j][3]>=e[i][1])||(m[j][2]==e[i][2]&&m[j][3]<=e[i][3]))
				tag2=i;
		}
		if(tag1%4 == tag2%4)
			cout << "Y";
		else
			cout << "N";
		cout << endl;
	}
	return 0;
}
/*
	for(j=0; j<n; j++) {
		cin >> m1 >> d1 >> m2 >> d2;
		for(i=0; i<12; i++) {
			if((m1==e[i][0]&&d1>=e[i][1])||(m1==e[i][2]&&d1<=e[i][3]))
				tag1=i;
			if((m2==e[i][0]&&d2>=e[i][1])||(m2==e[i][2]&&d2<=e[i][3]))
				tag2=i;
		}
		if(tag1%4==tag2%4)
			cout << "Y";
		else
			cout << "N";
	}
*/
