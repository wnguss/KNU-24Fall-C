#include <stdio.h>
int pactorial(num);

int main() {
	int num;

	printf("����� ���丮�� �� �Է� : ");
	scanf_s("%d", &num);

	int result = pactorial(num);

	printf("%d! = %d", num, result);

	return 0;
}

int pactorial(num) {
	int result = 1;

	if (num == 1)
		return 1;
	else
		result = num * pactorial(num - 1);

	return result;
}