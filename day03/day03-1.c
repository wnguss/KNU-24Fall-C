#include <stdio.h>
int is_prime_number(int num);

int main()
{
	int num;

	printf("�Ҽ����� Ȯ���� ���� �Է��ϼ��� : ");
	scanf_s("%d", &num);

	int res = is_prime_number(num);
	
	if (res == 1)
		printf("�ش� ���� �Ҽ��Դϴ�.\n");
	else
		printf("�ش� ���� �Ҽ��� �ƴմϴ�.\n");
	
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