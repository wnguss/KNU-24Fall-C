#include<stdio.h>
int main() {
	int fun;
	double num1;
	double num2;
	double sum;

	printf("원하는 기능을 입력하세요.\n1.더하기  2.빼기  3.곱하기  4.나누기\n\n");
	printf("기능 : ");
	scanf_s("%d", &fun);

	printf("숫자1 을 입력하세요 : ");
	scanf_s("%lf", &num1);
	printf("숫자2 를 입력하세요 : ");
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
		printf("\n해당하지 않는 연산자 입니다.\n");

	return 0;
}