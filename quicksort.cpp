#include <iostream>
using namespace std;

class SortableList {
public:
	void Input();
	int Partition(int p, int q);
	void QuickSort();
	void QuickSort(int l, int r);
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

int SortableList::

int main() {
	SortableList list;
	list.Input();
	list.solve();
	return 0;
}