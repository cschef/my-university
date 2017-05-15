/*********************************************

带时限的作业排序问题

Time Limit:1000MS  Memory Limit:65536K
Total Submit:729 Accepted:309

Description

设有一个单机系统、无其它资源限制且每个作业运行相等时间，不妨假定每个作业运行1个单位时间。现有n个作业，每个作业都有一个截止期限di>0，di为整数。如果作业能够在截止期限之内完成，可获得pi>0的收益。问题要求得到一种作业调度方案，该方案给出作业的一个子集和该作业子集的一种排列，使得若按照这种排列次序调度作业运行，该子集中的每个作业都能如期完成，并且能够获得最大收益。

Input

第一行输入n的值，以下n行输入作业号i，收益pi，截止期限di。

Output

n个作业的一个最优子集。

Sample Input


4
1 100 2
2 10 1
3 15 2
4 27 1
Sample Output


1 4

*********************************************/

#include <iostream>
using namespace std;

typedef struct {
	int no;
	int p;
	int d;
}JOB;

void Sort_by_p(JOB *job, int n) {
	int i, j;
	JOB tmp;
	for(i=0; i<n; i++) {
		for(j=i+1; j<n; j++) {
			if(job[i].p < job[j].p) {
				tmp=job[i];
				job[i]=job[j];
				job[j]=tmp;
			}
		}
	}
}

int JS(JOB *job, int *x, int n) {
	int k=0, j, r, i;
	x[0]=0;
	cout << job[x[k]].no << " ";
	for(j=1; j<n; j++) {
		r=k;
		while(r>=0 && job[x[r]].d>job[j].d && job[x[r]].d>r+1)
			r--;
		if((r<0 || job[x[r]].d<=job[j].d) && job[j].d>r+1) {
			for(i=k; i>=r+1; i--)
				x[i+1]=x[i];
			x[r+1]=j;
			cout << job[j].no << " ";
			k++;
		}
	}
	return k;
}

int main() {
	JOB *job;
	int n, i;
	cin >> n;
	job = new JOB [n];
	for(i=0; i<n; i++) {
		cin >> job[i].no >> job[i].p >> job[i].d;
	}
	Sort_by_p(job, n);
	int *x = new int [n];
	JS(job, x, n);
	return 0;
}