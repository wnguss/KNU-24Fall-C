#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>

int main(void) {
	int a = 0, b = 0, c = 0;
	double x1, x2, x3;
	int D;

	printf("a, b, c 입력 : ");
	scanf_s("%d %d %d", &a, &b, &c);

	D = pow(b, 2) - 4*(a * c);

	if (D > 0){
		x1 = (-b + sqrt(D)) / (2*a);
		x2 = (-b - sqrt(D)) / (2*a);
		printf("실근의 개수는 2 로, %.2f, %.2f 입니다.\n", x1, x2);
}
	else if (D == 0){
		x3 = -b / (2 * a);
		printf("실근의 개수는 1 로, %.2f 입니다.", x3);
}
	else {
		printf("실근의 개수는 0 입니다.\n");
	}

	return 0;
}