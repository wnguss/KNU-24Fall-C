#include<stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
	int snum;
	char name[100];
	int	score;
};

int main()
{
	int n;
	struct Student person[2];

	person[0].snum = 1111;
	strcpy_s(person[0].name, 100, "ö��");
	person[0].score = 100;

	printf("%d %s %d\n", person[0].snum, person[0].name, person[0].score);

	return 0;
}