#include <iostream>
using namespace std;

struct STU {
	char name[11];
	char no[11];
	int grade;
};
int main() {
	int n;
	STU *stu;
	cin >> n;
	stu = new STU [n];
	for(int i=0; i<n; i++) {
		cin >> stu[i].name >> stu[i].no >> stu[i].grade;
	}
	int max, min, pmax, pmin;
	max=min=stu[0].grade;
	pmax=pmin=0;
	for(int i=1; i<n; i++) {
		if(stu[i].grade > max) {
			max=stu[i].grade;
			pmax=i;
		}
		if(stu[i].grade < min) {
			min=stu[i].grade;
			pmin=i;
		}
	}
	cout << stu[pmax].name << " " << stu[pmax].no << endl;
	cout << stu[pmin].name << " " << stu[pmin].no;
	return 0;
} 
