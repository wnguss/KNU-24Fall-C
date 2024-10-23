#include<stdio.h>
#include<string.h>
int main()
{
	char list[100];
	int num = 0;
	char temp;
	char* start = 0;
	char* end = 0;

	printf("문자열 입력 : ");
	scanf_s("%s", list, sizeof(list));

	num = strlen(list);

	for (int i = 0; i < num; i++) {
		if (!((list[i] >= 'A' && list[i] <= 'Z') || (list[i] >= 'a' && list[i] <= 'z')))
			printf("영어만 입력해야 합니다.");
		return 1;
	}

	start = (char*)list;
	end = ((char*)list) + num - 1;

	for (int i = 0; i < num / 2; i++) {
		temp = *start;
		*start = *end;
		*end = temp;

		start++;
		end--;
	}

	printf("%s", list);

	return 0;
}
