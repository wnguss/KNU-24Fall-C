#include <stdio.h>
#include <stdlib.h>

int main()
{
	int* stud_num;
	char** name; //name 자체가 배열이라 포인터인데 여기에 저장하기 위한 포인터를 써야해서 이중 포인터가 된다.
	int* score;
	int n;
	int max = 0;
	int min = 100;
	float aver;
	float sum = 0;

	printf("학생 수 입력 : ");
	scanf_s("%d", &n);

	stud_num = (int*)malloc(sizeof(int) * n);
	name = (char**)malloc(sizeof(char*) * n);
	score = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++) {
		name[i] = (char*)malloc(100 * sizeof(char));
	}

	for (int i = 0; i < n; i++) {
		printf("학번 : ");
		scanf_s("%d", &stud_num[i]);

		printf("이름 : ");
		scanf_s("%s", name[i], 100);
		
		printf("점수 : ");
		scanf_s("%d", &score[i]);

		printf("\n");
	}

	for (int i = 0; i < n; i++) {
		printf("%d %s %d\n", stud_num[i], name[i], score[i]);
	}

	for (int i = 0; i < n; i++) {
		if (score[i] > max)
			max = score[i];

		if (score[i] < min)
			min = score[i];
	}

	printf("최대값 : %d\n", max);
	printf("최소값 : %d\n", min);

	for (int i = 0; i < n; i++) {
		sum += score[i];
	}

	aver = sum / n;
	printf("평균 : %lf", aver);

	free(stud_num);
	for (int i = 0; i < n; i++) {
		free(name[i]);
	}
	free(score);

	return 0;
}