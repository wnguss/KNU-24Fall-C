#include <stdio.h>

void swap(int *p_num1, int *p_num2)
{
	int empty = *p_num1;
	*p_num1 = *p_num2;
	*p_num2 = empty;
}

int main()
{
	int a = 100;
	int b = 200;

	printf("a = %d b = %d\n", a, b);
	swap(&a, &b);
	printf("a = %d b = %d\n", a, b);

	return 0;
}