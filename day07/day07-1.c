#include<stdio.h>
int main() {
	int N;

	printf("���ϴ� �� �� �Է� : ");
	scanf_s("%d", &N);
	printf("\n");
	printf("%d�� �Ƕ�̵�\n", N);

	for (int i = 0; i < N; i++) { // ���ϴ� ������ �ݺ��ؼ� ����
		for (int k = 0; k < N - i; k++) { // ������ �����. �ö󰡴� �� �� ��ŭ *�� �þ�� -i�� ����.
			printf(" ");
		}
		for (int j = 0; j < (i * 2) + 1; j++) { // �Ƕ�̵带 ����� ���ؼ� 1, 3, 5, 7 ... ������ �þ�� �ϴ� (i*2)+1������ ������.
			printf("*");
		}
		printf("\n");
	}

	return 0;
} 
