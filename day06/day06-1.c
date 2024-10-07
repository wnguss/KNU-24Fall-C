#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node* link;
};

struct node* create_node(int data)
{
	struct node* new_node = (struct node*)malloc(sizeof(struct node));
	new_node->data = data;
	new_node->link = NULL;

	return new_node;
}

struct node* head = NULL;

struct node* last_node()
{
	struct node* cur = head;
	while (cur->link != NULL) {
		cur = cur->link;
	}
	return cur;
}

void insert_node_last(struct node* new_node)
{
	struct node* last = last_node();
	last->link = new_node;
}

void print_nodes()
{
	struct node* cur = head->link;
	while (cur != NULL) {
		printf("%d\n", cur->data);
		cur = cur->link;
	}
}

struct node* find_node(int value)
{
	struct node* cur = head->link;
	while (cur != NULL) {
		if (cur->data == value) return cur;

		cur = cur->link;
	}
	return NULL;
}

int delete_node(int value)
{
	struct node* prev = head;
	struct node* cur = head->link;
	while (cur != NULL) {
		if (cur->data == value) {
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
	head = (struct node*)malloc(sizeof(struct node));
	head->link = NULL;

	for (int i = 1; i < 6; i++) {
		insert_node_last(create_node(i));
	}
	printf("노드 추가\n");
	print_nodes();

	printf("중간 노드 삭제\n");
	delete_node(3);
	print_nodes();

	return 0;
}