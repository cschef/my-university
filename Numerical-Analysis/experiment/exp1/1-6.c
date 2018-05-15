#include <stdio.h>
#include <math.h>

int main() {
	float w = 7.0/25.0;
	float x[100] = {1.0};
	int i = 0;
	do {
		i++;
		x[i] = w * x[i - 1] + (1 - w) / (1.0 + x[i - 1]);
	} while (fabs(x[i] - x[i - 1]) >= 0.00001);
	printf("%f", x[i]);
	return 0;
}
