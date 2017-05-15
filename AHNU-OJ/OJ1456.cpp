/*********************************************

最大最小元问题

Time Limit:1000MS  Memory Limit:65536K
Total Submit:811 Accepted:303

Description

请改写教材中的分治算法MaxMin，使其可以输出n个数中的最大值和次最大值以及最小值和次最小值（注意：不能用排序）。

Input

第一行输入数的个数n，第二行输入n个数。

Output

第一行输出最大值和次最大值，第二行输出最小值和次最小值。

Sample Input


3
2 1 3
Sample Output


3 2
1 2

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
};

void SortableList::Input() {
	int i;
	cin >> length;
	for(i=0; i<length; i++) {
		cin >> l[i];
	}
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
	cout << K_Min(0, length-1, length) << ' ' << K_Min(0, length-1, length-1) << endl;
	cout << K_Min(0, length-1, 1) << ' ' << K_Min(0, length-1, 2);
}


int main() {
	SortableList list;
	list.Input();
	list.solve();
	return 0;
}