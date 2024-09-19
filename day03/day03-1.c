#include <stdio.h>
int check(a, b);

int main()
{
	int num1;
	int num2 = 1;
	int result;

	printf("소수인지 확인할 수를 입력하세요 : ");
	scanf_s("%d", &num1);

	result = check(num1, num2);

	return 0;
}

int check(a, b)
{
	int res = 0;

	if (a / b == a && a / a == 1 && a % 2 != 0 && a % 3 != 0 && a % 5 != 0 && a % 7 != 0)
		printf("해당 수는 소수입니다.\n");
	else
		printf("해당 수는 소수가 아닙니다.\n");

	return res;
}