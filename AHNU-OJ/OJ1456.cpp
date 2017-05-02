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