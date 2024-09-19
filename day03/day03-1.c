#include <stdio.h>
int is_prime_number(int num);

int main()
{
	int num;

	printf("소수인지 확인할 수를 입력하세요 : ");
	scanf_s("%d", &num);

	int res = is_prime_number(num);
	
	if (res == 1)
		printf("해당 수는 소수입니다.\n");
	else
		printf("해당 수는 소수가 아닙니다.\n");
	
	return 0;
}

int is_prime_number(int num)
{
	for (int i = 2; i < num; i++) {
		if (num % i == 0) {
			return 0;
		}
	}
	return 1;
}