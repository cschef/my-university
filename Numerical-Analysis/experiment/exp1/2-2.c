/*
	Name:
	Copyright:
	Author:
	Date: 13/03/18 11:11
	Description: 求倒数
*/


#include <stdio.h>

int main() {
	float a, x[100];
	int n;  //迭代次数
	int i = 0, j;

	printf("a = ");
	scanf("%f", &a);
	printf("x0 = ");
	scanf("%f", &x[0]);
	printf("n = ");
	scanf("%d", &n);

	while (n-- > 0) {
		i++;
		x[i] = 2.0 * x[i - 1] - a * x[i - 1] * x[i - 1];
	}

	for (j = 0; j <= i; j++) {
		printf("x[%d] = %f\n", j, x[j]);
	}
	
	return 0;
}
