#include<stdio.h>

struct vector {
	int x;
	int y;
	int z;
};

void plus(struct vector v1, struct vector v2) {
	int sumx;
	int sumy;
	int sumz;

	sumx = v1.x + v2.x;
	sumy = v1.y + v2.y;
	sumz = v1.z + v2.z;

	printf("������ ����\t x:%d\t y:%d\t z:%d", sumx, sumy, sumz);
}

void minus(struct vector v1, struct vector v2) {
	int sumx;
	int sumy;
	int sumz;

	sumx = v1.x - v2.x;
	sumy = v1.y - v2.y;
	sumz = v1.z - v2.z;

	printf("������ ����\t x:%d\t y:%d\t z:%d\t", sumx, sumy, sumz);
}

void inner(struct vector v1, struct vector v2) {
	int inv;

	inv = (v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z);

	printf("������ ������\t vec1 �� vec2=%d", inv);
}

void outter(struct vector v1, struct vector v2) {
	int outv1;
	int outv2;
	int outv3;

	outv1 = (v1.y * v2.z) - (v1.z * v2.y);
	outv2 = (v1.z * v2.x) - (v1.x * v2.z);
	outv3 = (v1.x * v2.y) - (v1.y * v2.x);

	printf("������ ������\t x:%d\t y:%d\t z:%d", outv1, outv2, outv3);
}

int main() {
	struct vector v1;
	struct vector v2;
	int order;

	printf("ù��° ����(x,y,z) : ");
	scanf_s("%d, %d, %d", &v1.x, &v1.y, &v1.z);

	printf("�ι�° ����(x,y,z) : ");
	scanf_s("%d, %d, %d", &v2.x, &v2.y, &v2.z);

	printf("�Էµ� ù��° ����\t \t%d,\t %d,\t %d\n", v1.x, v1.y, v1.z);
	printf("�Էµ� �ι�° ����\t \t%d,\t %d,\t %d\n", v2.x, v2.y, v2.z);

	while (1) {
		printf("\n--------------------------\n");
		printf("1. ������ ��\n2. ������ ��\n3. ������ ����\n4. ������ ����\n5. ����\n");
		printf("--------------------------\n");
		printf("��� �Է� : ");
		scanf_s("%d", &order);

		if (order == 1)
			plus(v1, v2);
		else if (order == 2)
			minus(v1, v2);
		else if (order == 3)
			outter(v1, v2);
		else if (order == 4)
			inner(v1, v2);
		else if (order == 5) {
			printf("���α׷��� �����մϴ�.\n");
			printf("--------------------------\n");
			break;
		}
		else
			printf("������ ��� ���� �ƴմϴ�.\n");
		printf("\n--------------------------\n");
	}

	return 0;
}