#include <stdio.h>
int factorial(int num);

int main() {
	int num;

	printf("����� ���丮�� �� �Է� : ");
	scanf_s("%d", &num);

	int result = factorial(num);

	printf("%d! = %d", num, result);

	return 0;
}

int factorial(int num) {
	int result;

	if (num == 0 || num == 1) {
		result = 1;
		return 1;
	}
	else
		result = num * factorial(num - 1);

	return result;
}