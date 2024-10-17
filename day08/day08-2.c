#include<stdio.h>
#include<stdlib.h>

#define SIZE 10

void fillRandom(int array[SIZE][SIZE]);
void printArray(int array[SIZE][SIZE]);
void movePointer(void* array);


int main() {
	int array[SIZE][SIZE];

	fillRandom(array); //�迭 ���� �ʱ�ȭ
	printArray(array); //�迭 ���
	movePointer(array); //�����͸� �̿��� �̵�
}

void fillRandom(int array[SIZE][SIZE]) {
	for (int i = 0; i < SIZE; i++)
		for (int j = 0; j < SIZE; j++)
			array[i][j] = rand()%21;
}

void movePointer(void* array) {
	int temp = 0;
	int x = 0;
	int y = 0;

	while (10 * x + y <= 99) {
		temp = *((int*)array + (10 * x) + y);
		printf("���� ��ġ : (%d, %d), �迭�� �� : %d\n", x, y, temp);

		if (10 * x + y >= 99) {
			printf("�� �̻� �̵��� �� �����ϴ�.\n");
			printf("���� ��ġ : (%d, %d), �迭�� �� : %d", x, y, temp);
		}

		x += temp / 10;
		y += temp % 10;
		if (y >= 10) {
			x += 1;
			y -= 10;
		}
		temp = 0;
	}
}

void printArray(int array[SIZE][SIZE]) {
	printf("�迭 ���: \n");
		for (int i = 0; i < SIZE; i++) {
			for (int j = 0; j < SIZE; j++) {
				printf("%5d", array[i][j]);
			}
			printf("\n");
		}
}