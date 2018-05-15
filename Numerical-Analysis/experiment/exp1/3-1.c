/*
	Name:
	Copyright:
	Author:
	Date: 13/03/18 11:13
	Description: Çó e^x
*/


#include <stdio.h>

float fm(int x, int k) {
	int i;
	float re = 1.0;
	for (i = 0; i < k; i++) {
		re *= x;
	}
	return re;
}

float jch(int n) {
	float re = 1.0;
	while (n > 0) {
		re *= n;
		n--;
	}
	return re;
}

int main() {
	float sum = 0.0;
	int x, n;
	int k;
	
	printf("x = ");
	scanf("%d", &x);
	printf("n = ");
	scanf("%d", &n);
	
	for (k = 0; k <= n; k++) {
		sum += fm(x, k) / jch(k);
	}
	
	printf("e^x = %f", sum);
	
	return 0;
}
