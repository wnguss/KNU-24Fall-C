#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define NAME_MAX 50

struct NODE
{
	char name[NAME_MAX];
	int score;
	struct NODE* link;
};

struct NODE* head;

struct NODE* create_node(char* name, int score)
{
	struct NODE* new_node = (struct NODE*)malloc(sizeof(struct NODE));
	strcpy_s(new_node->name, NAME_MAX, name);
	new_node->score = score;
	new_node->link = NULL;

	return new_node;
}

struct NODE* last_node()
{
	struct NODE* cur = head;
	while (cur->link != NULL) {
		cur = cur->link;
	}
	return cur;
}

struct NODE* find_node_insert(int score)
{
	struct NODE* prev = head;
	struct NODE* cur = head->link;
	if (cur == NULL) return head;


	while (cur != NULL) {
		if (cur->score >= score) {
			if (cur->link == NULL) return cur;

			prev = cur;
			cur = cur->link;
		}
		else {
			return prev;
		}
	}
}

void insert_node_priority(struct NODE* new_node)
{
	struct NODE* priority = find_node_insert(new_node->score);
	new_node->link = priority->link;
	priority->link = new_node;
}

void insert_node_last(struct NODE* new_node)
{
	struct NODE* last = last_node();
	last->link = new_node;
}

void print_nodes()
{
	struct NODE* cur = head->link;
	printf("--------------------\n");
	while (cur != NULL) {
		printf("%s : %d\n", cur->name, cur->score);
		cur = cur->link;
	}
	printf("--------------------\n");
}

int delete_node(char* name)
{
	struct NODE* prev = head;
	struct NODE* cur = head->link;
	while (cur != NULL) {
		if (strcmp(name, cur->name) == 0) {
			prev->link = cur->link;
			free(cur);
			return 1;
		}

		prev = cur;
		cur = cur->link;
	}
	return 0;
}

int main()
{
	head = (struct NODE*)malloc(sizeof(struct NODE));
	head->link = NULL;

	int inst;
	int iteration = 1;

	char name[NAME_MAX];
	int score;

	while (iteration) {
		printf("1. �� �߰�\n");
		printf("2. �� ����\n");
		printf("3. �� ���� ����\n");
		printf("��� �Է� : ");
		scanf_s("%d", &inst);

		switch (inst)
		{
		case 1:
			printf("�� �̸� : ");
			scanf_s("%s", name, NAME_MAX);

			printf("�� ��� : ");
			scanf_s("%d", &score);

			insert_node_priority(create_node(name, score));

			break;
		case 2:
			printf("������ ���� �̸� : ");
			scanf_s("%s", name, NAME_MAX);
			delete_node(name);
			break;

		case 3:
		default:
			iteration = 0;
			break;
		}
		print_nodes();
	}

	return 0;
}