#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>

double f(double x) {
	double f = -log10(1 / x) + sin(x);
	return f;
}

int main(void) {
	double a, b, n;

	printf("적분할 시작 값을 입력하세요 : ");
	scanf_s("%lf", &a);

	printf("적분할 끝 값을 입력하세요 : ");
	scanf_s("%lf", &b);

	printf("시행할 최대 구간을 입력하세요(2^n) : ");
	scanf_s("%lf", &n);

	double sum = 0;

	for (int i = 0; i <= n; i++) {
		double length = (b - a) / pow(2, i);

		sum = 0;

		for (int j = 0; j <= pow(2, i); j++) {
			double height = f(a + j * length);
			sum += height * length;
		}

		printf("구간\t%.0lf 적분 결과 : %.6lf", pow(2, i), sum);
		printf("\n");
	}

	return 0;
}
