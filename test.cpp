#include <iostream>
using namespace std;

template <class T>
class Point {
	public:
		Point(T a, T b) {
			x=a; y=b;
		}
		T get_x() {
			return x;
		}
		T get_y() {
			return y;
		}
	private:
		T x;
		T y;		
};

int main() {
	Point <int> p(3, 7);
	cout << p.get_x() << endl;
	cout << p.get_y() << endl;
	return 0;
} 
