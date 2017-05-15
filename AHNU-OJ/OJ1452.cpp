/*********************************************

集合的幂集

Time Limit:1000MS  Memory Limit:65536K
Total Submit:595 Accepted:295

Description

设S是有n（n≤20）个元素的集合，S的幂集是S所有可能的子集组成的集合。例如，S={a,b,c},则S的幂集={()(c)(b)(bc)(a)(ac)(ab)(abc)}。写一个C++递归程序，以S为输入，输出S的幂集。

Input

n（n≤20）的值以及S的n个元素

Output

S的幂集

Sample Input


3
abc
Sample Output


()(c)(b)(bc)(a)(ac)(ab)(abc)

*********************************************/

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