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

			printf("%d%% 진행.. 원주율 : %lf\t", percent, PI); // 진행도 : 천만 번 마다 출력되니 percent = 천만 번 * n, 즉 1% 씩 올라감

			for (int i = 0; i < (percent / 5); i++) // i는 percent를 5로 나눈 값까지 출력됨. 5일 때 한번, 10일 때 두번 해서 쭉 올라감
				printf("■");

			for (int j = (percent / 5); j < 20; j++) // percent를 5로 나눈 값으로 시작하니 만약 검정 블럭 2개를 출력한 상태라면 j는 2부터 시작, 빈 블럭이 18개만 채워짐.
				printf("□");

			printf("\n");
		}
	}

	printf("원주율 : %lf", PI);

	return 0;
}
