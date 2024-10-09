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
			PI = 4 * ((float)circle / (float)count);
			printf("%d%% ����.. ������ : %lf\t", count / 10000000, PI);

			int percent = count / 10000000; // ���൵ : õ�� �� ���� ��µǴ� count = õ�� �� * n, �� 1% �� �ö�

			for (int i = 0; i < (percent / 5); i++) // i�� percent�� 5�� ���� ������ ��µ�. 5�� �� �ѹ�, 10�� �� �ι� �ؼ� �� �ö�
				printf("��");

			for (int i = (percent / 5); i < 20; i++) // percent�� 5�� ���� ������ �����ϴ� ���� ���� �� 2���� ����� ���¶�� i�� 2���� ����, �� ���� 18���� ä����.
				printf("��");

			printf("\n");
		}
	}

	printf("������ : %lf", PI);

	return 0;
}
