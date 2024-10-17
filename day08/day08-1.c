#include<stdio.h>
#include<string.h>
int main()
{
	char list[100];
	int num = 0;
	char temp;
	char* start = 0;
	char* end = 0;

	printf("문자열을 입력 : ");
	scanf_s("%s", &list, sizeof(list));
	//값이 안바뀜 처음엔 strlen 안써서 오류, 두번 째엔 for문 내에 * 안붙여서 그대로 변환, 그 다음 start 대신 list++해서 오류


	num = strlen(list);

	start = (char*)list;
	end = ((char*)list)+num-1;

	for (int i = 0; i < num/2; i++) {
		temp = *start;
		*start = *end;
		*end = temp;

		start++;
		end--;
	}

	printf("%s", list);

	return 0;
}