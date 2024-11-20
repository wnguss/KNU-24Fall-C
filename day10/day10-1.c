#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct NODE
{
	char name[50];
	int score;
	struct NODE* link;
};

struct NODE* head;

struct NODE* create_node(char* name, int score)
{
	struct NODE* new_node = (struct NODE*)malloc(sizeof(struct NODE));
	strcpy_s(new_node->name, 50, name);
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

	int order;
	int end = 1;

	char name[50];
	int score;

	while (end) {
		printf("1. 학생 성적 입력\n");
		printf("2. 학생 삭제\n");
		printf("3. 프로그램 종료\n");
		printf("명령 입력 : ");
		scanf_s("%d", &order);

		if (order == 1) {
			printf("학생 이름 : ");
			scanf_s("%s", name, 50);

			printf("점수 : ");
			scanf_s("%d", &score);

			insert_node_priority(create_node(name, score));
		}
		else if (order == 2) {
			printf("삭제할 학생의 이름 : ");
			scanf_s("%s", name, 50);
			delete_node(name);
		} else if (order == 3) {
				end = 0;
		}
		print_nodes();
	}

	return 0;
}
