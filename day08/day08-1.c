#include<stdio.h>
#include<string.h>
int main()
{
	char list[100];
	int num = 0;
	char temp;
	char* start = 0;
	char* end = 0;

	printf("���ڿ��� �Է� : ");
	scanf_s("%s", &list, sizeof(list));
	//���� �ȹٲ� ó���� strlen �ȽἭ ����, �ι� °�� for�� ���� * �Ⱥٿ��� �״�� ��ȯ, �� ���� start ��� list++�ؼ� ����


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