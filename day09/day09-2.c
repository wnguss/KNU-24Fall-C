#include<stdio.h>

struct Product {
	int ID;
	char name[10];
	int price;
};

void printProduct(struct Product item) {
	printf("상품 ID : %d\n", item.ID);
	printf("상품명 : %s\n", item.name);
	printf("가격 : %d원\n", item.price);
	printf("\n");
}

int main() {
	struct Product item[5];

	int i;

	for (i = 0; i < 5; i++) {
		printf("상품 정보를 입력하세요 (입력 중단은 id에 0 입력)\n");

		printf("상품 ID : ");
		scanf_s("%d", &item[i].ID);

		if (item[i].ID == 0) {
			break;
		}

		printf("상품명 : ");
		scanf_s("%s", item[i].name, sizeof(item[i].name));

		printf("가격 : ");
		scanf_s("%d", &item[i].price);

		printf("\n");
	}

	printf("\n<<입력된 상품 목록>>\n");
	for (int k = 0; k < i; k++) {
		printf("\n");
		printProduct(item[k]);
	}

	return 0;
}