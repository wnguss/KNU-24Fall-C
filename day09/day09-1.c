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

	printf("벡터의 합은\t x:%d\t y:%d\t z:%d", sumx, sumy, sumz);
}

void minus(struct vector v1, struct vector v2) {
	int sumx;
	int sumy;
	int sumz;

	sumx = v1.x - v2.x;
	sumy = v1.y - v2.y;
	sumz = v1.z - v2.z;

	printf("벡터의 차는\t x:%d\t y:%d\t z:%d\t", sumx, sumy, sumz);
}

void inner(struct vector v1, struct vector v2) {
	int inv;

	inv = (v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z);

	printf("벡터의 내적은\t vec1 · vec2=%d", inv);
}

void outter(struct vector v1, struct vector v2) {
	int outv1;
	int outv2;
	int outv3;

	outv1 = (v1.y * v2.z) - (v1.z * v2.y);
	outv2 = (v1.z * v2.x) - (v1.x * v2.z);
	outv3 = (v1.x * v2.y) - (v1.y * v2.x);

	printf("벡터의 외적은\t x:%d\t y:%d\t z:%d", outv1, outv2, outv3);
}

int main() {
	struct vector v1;
	struct vector v2;
	int order;

	printf("첫번째 벡터(x,y,z) : ");
	scanf_s("%d, %d, %d", &v1.x, &v1.y, &v1.z);

	printf("두번째 벡터(x,y,z) : ");
	scanf_s("%d, %d, %d", &v2.x, &v2.y, &v2.z);

	printf("입력된 첫번째 벡터\t \t%d,\t %d,\t %d\n", v1.x, v1.y, v1.z);
	printf("입력된 두번째 벡터\t \t%d,\t %d,\t %d\n", v2.x, v2.y, v2.z);

	while (1) {
		printf("\n--------------------------\n");
		printf("1. 벡터의 합\n2. 벡터의 차\n3. 벡터의 외적\n4. 벡터의 내적\n5. 종료\n");
		printf("--------------------------\n");
		printf("명령 입력 : ");
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
			printf("프로그램을 종료합니다.\n");
			printf("--------------------------\n");
			break;
		}
		else
			printf("적절한 명령 값이 아닙니다.\n");
		printf("\n--------------------------\n");
	}

	return 0;
}