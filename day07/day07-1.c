#include<stdio.h>
int main() {
	int N;

	printf("원하는 층 수 입력 : ");
	scanf_s("%d", &N);
	printf("\n");
	printf("%d층 피라미드\n", N);

	for (int i = 0; i < N; i++) { // 원하는 층까지 반복해서 쌓음
		for (int k = 0; k < N - i; k++) { // 왼쪽을 띄워줌. 올라가는 층 수 만큼 *이 늘어나니 -i를 해줌.
			printf(" ");
		}
		for (int j = 0; j < (i * 2) + 1; j++) { // 피라미드를 만들기 위해선 1, 3, 5, 7 ... 식으로 늘어나야 하니 (i*2)+1까지로 정해줌.
			printf("*");
		}
		printf("\n");
	}

	return 0;
} 
