#include<stdio.h>
#include <stdlib.h>

int main()
{
	int* stud_num;
	char** name; //name ��ü�� �迭�̶� �������ε� ���⿡ �����ϱ� ���� �����͸� ����ؼ� ���� �����Ͱ� �ȴ�.
	int* score;
	int n;

	printf("�л� �� �Է� : ");
	scanf_s("%d", &n);

	stud_num = (int*)malloc(sizeof(int) * n);
	name = (char**)malloc(sizeof(char*) * n);
	score = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++) {
		name[i] = (char*)malloc(100 * sizeof(char));
	}

	for (int i = 0; i < n; i++) {
		printf("�й� : ");
		scanf_s("%d", &stud_num[i]);

		printf("�̸� : ");
		scanf_s("%s", name[i], 100);
		
		printf("���� : ");
		scanf_s("%d", &score[i]);

		printf("\n");
	}

	for (int i = 0; i < n; i++) {
		printf("%d %s %d\n", stud_num[i], name[i], score[i]);
	}

	free(stud_num);
	for (int i = 0; i < n; i++) {
		free(name[i]);
	}
	free(score);

	return 0;
}