#include<stdio.h>

struct Product {
	int ID;
	char name[10];
	int price;
};

void printProduct(struct Product item) {
	printf("��ǰ ID : %d\n", item.ID);
	printf("��ǰ�� : %s\n", item.name);
	printf("���� : %d��\n", item.price);
	printf("\n");
}

int main() {
	struct Product item[5];

	int i;

	for (i = 0; i < 5; i++) {
		printf("��ǰ ������ �Է��ϼ��� (�Է� �ߴ��� id�� 0 �Է�)\n");

		printf("��ǰ ID : ");
		scanf_s("%d", &item[i].ID);

		if (item[i].ID == 0) {
			break;
		}

		printf("��ǰ�� : ");
		scanf_s("%s", item[i].name, sizeof(item[i].name));

		printf("���� : ");
		scanf_s("%d", &item[i].price);

		printf("\n");
	}

	printf("\n<<�Էµ� ��ǰ ���>>\n");
	for (int k = 0; k < i; k++) {
		printf("\n");
		printProduct(item[k]);
	}

	return 0;
}