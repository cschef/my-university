/*********************************************

第K小元素问题

Time Limit:1000MS  Memory Limit:65536K
Total Submit:704 Accepted:317

Description

用分治法编程解决在n个数当中找第K小元素问题（注意：不能用排序）。

Input

第一行输入n的值，第二行输入n个数，第三行输入K的值。

Output

n个数中的第K小元素。

Sample Input


5
8 1 3 6 9
3
Sample Output


6

*********************************************/

#include <iostream>
using namespace std;

class SortableList {
public:
	void Input();
	int Partition(int p, int q);
	int K_Min(int p, int q, int k);
	void solve();
protected:
	int l[1000];
	int length;
	int k;
};

void SortableList::Input() {
	int i;
	cin >> length;
	for(i=0; i<length; i++) {
		cin >> l[i];
	}
	cin >> k;
}

int SortableList::Partition(int p, int q) {
	int x=l[p];
	int i=p, tmp;
	for(int j=p+1; j<=q; j++) {
		if(l[j] <= x) {
			i++;
			tmp=l[i];
			l[i]=l[j];
			l[j]=tmp;
		}
	}
	tmp=l[p];
	l[p]=l[i];
	l[i]=tmp;
	return i;
}

int SortableList::K_Min(int p, int q, int k) {
	if(p == q)
		return l[p];
	int j=Partition(p, q);
	while(k!=j+1) {
		if(k < j+1)
			q=j-1;
		else
			p=j+1;
		j=Partition(p, q);
	}
	return l[j];
}

void SortableList::solve() {
	cout << K_Min(0, length-1, k);
}


int main() {
	SortableList list;
	list.Input();
	list.solve();
	return 0;
}