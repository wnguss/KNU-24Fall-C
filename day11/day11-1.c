#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>

int main(void) {
	int a = 0, b = 0, c = 0;
	double x1, x2, x3;
	int D;

	printf("a, b, c �Է� : ");
	scanf_s("%d %d %d", &a, &b, &c);

	D = pow(b, 2) - 4*(a * c);

	if (D > 0){
		x1 = (-b + sqrt(D)) / (2*a);
		x2 = (-b - sqrt(D)) / (2*a);
		printf("�Ǳ��� ������ 2 ��, %.2f, %.2f �Դϴ�.\n", x1, x2);
}
	else if (D == 0){
		x3 = -b / (2 * a);
		printf("�Ǳ��� ������ 1 ��, %.2f �Դϴ�.", x3);
}
	else {
		printf("�Ǳ��� ������ 0 �Դϴ�.\n");
	}

	return 0;
}