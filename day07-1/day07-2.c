#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

int main(void) {

	double x = 0;
	double y = 0;
	double PI;

	int count = 0, circle = 0;

	srand(time(NULL));

	while (count < 1000000000) {
		x = (double)rand() / (double)RAND_MAX;
		y = (double)rand() / (double)RAND_MAX;
		count++;

		if (sqrt(pow(x, 2) + pow(y, 2)) < 1) {
			circle++;
		}

		if (count % 10000000 == 0) {
			PI = 4 * ((double)circle / (double)count);

			int percent = count / 10000000;

			printf("%d%% ����.. ������ : %lf\t", percent, PI); // ���൵ : õ�� �� ���� ��µǴ� percent = õ�� �� * n, �� 1% �� �ö�

			for (int i = 0; i < (percent / 5); i++) // i�� percent�� 5�� ���� ������ ��µ�. 5�� �� �ѹ�, 10�� �� �ι� �ؼ� �� �ö�
				printf("��");

			for (int j = (percent / 5); j < 20; j++) // percent�� 5�� ���� ������ �����ϴ� ���� ���� �� 2���� ����� ���¶�� j�� 2���� ����, �� ���� 18���� ä����.
				printf("��");

			printf("\n");
		}
	}

	printf("������ : %lf", PI);

	return 0;
}