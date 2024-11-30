#include<stdio.h>
int solution(int N)
{
	int ans = 0;

	while (N != 0) {

		if (N % 2 == 0) {
			N = N / 2;
		}
		if (N % 2 != 0) {
			ans++;
			N = N - 1;
		}
	}

	return ans;
}