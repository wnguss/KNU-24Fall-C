#include<stdio.h>
int main() {
	int fun;
	double num1;
	double num2;
	double sum;

	printf("���ϴ� ����� �Է��ϼ���.\n1.���ϱ�  2.����  3.���ϱ�  4.������\n\n");
	printf("��� : ");
	scanf_s("%d", &fun);

	printf("����1 �� �Է��ϼ��� : ");
	scanf_s("%lf", &num1);
	printf("����2 �� �Է��ϼ��� : ");
	scanf_s("%lf", &num2);

	if (fun == 1) {
		sum = num1 + num2;
		printf("\n%lf + %lf = %lf\n", num1, num2, sum);
	}
	else if (fun == 2) {
		sum = num1 - num2;
		printf("\n%lf - %lf = %lf\n", num1, num2, sum);
	}
	else if (fun == 3) {
		sum = num1 * num2;
		printf("\n%lf * %lf = %lf\n", num1, num2, sum);
	}
	else if (fun == 4) {
		sum = num1 / num2;
		printf("\n%lf / %lf = %lf\n", num1, num2, sum);
	}
	else
		printf("\n�ش����� �ʴ� ������ �Դϴ�.\n");

	return 0;
}