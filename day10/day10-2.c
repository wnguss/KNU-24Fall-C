#include<stdio.h>
#include<stdlib.h>
#include<string.h>

enum rank {
    rank1 = 1,
    rank2,
    rank3,
    rank4,
    rank5
};

struct NODE {
    char* customerName;
    enum rank customerRank;
    int order_amount;
    int point;
    struct NODE* prev;
    struct NODE* next;
};

struct NODE* head;

struct NODE* create_node(char* customerName, enum rank customerRank, int order_amount, int point) {
    struct NODE* new_node = (struct NODE*)malloc(sizeof(struct NODE));
    new_node->customerName = (char*)malloc(strlen(customerName) + 1);
    strcpy_s(new_node->customerName, strlen(customerName) + 1, customerName);
    new_node->customerRank = customerRank;
    new_node->order_amount = order_amount;
    new_node->point = point;
    new_node->prev = NULL;
    new_node->next = NULL;

    return new_node;
}

struct NODE* last_node() {
    struct NODE* cur = head;
    while (cur->next != NULL) {
        cur = cur->next;
    }
    return cur;
}

struct NODE* find_node_insert(enum rank customerRank, int order_amount, int point) {
    struct NODE* cur = head->next;

    while (cur != NULL) {
        if (cur->customerRank > customerRank) {
            return cur;
        }
        else if (cur->customerRank == customerRank) {
            if (cur->order_amount < order_amount) {
                return cur;
            }
            else if (cur->order_amount == order_amount) {
                if (cur->point < point) {
                    return cur;
                }
            }
        }
        cur = cur->next;
    }

    return NULL;
}

void insert_node_priority(struct NODE* new_node) {
    struct NODE* priority = find_node_insert(new_node->customerRank, new_node->order_amount, new_node->point);
    struct NODE* last = last_node();

    if (priority == NULL) {
        last->next = new_node;
        new_node->prev = last;
    }
    else if (priority != NULL) {
        new_node->next = priority;
        new_node->prev = priority->prev;

        priority->prev->next = new_node;

        priority->prev = new_node;
    }
}

void insert_node_last(struct NODE* new_node) {
    struct NODE* last = last_node();
    last->next = new_node;
}

void print_nodes() {
    struct NODE* cur = head->next;
    printf("--------------------\n");
    while (cur != NULL) {
        printf("%s님의 랭크 : %d\n", cur->customerName, cur->customerRank);
        printf("%s님의 구매량 : %d\n", cur->customerName, cur->order_amount);
        printf("%s님의 포인트 : %d\n", cur->customerName, cur->point);
        cur = cur->next;
    }
    printf("--------------------\n");
}

int delete_node(char* customerName) {
    struct NODE* prev = head;
    struct NODE* cur = head->next;

    while (cur != NULL) {
        if (strcmp(customerName, cur->customerName) == 0) {
            prev->next = cur->next;
            free(cur);
            return 1;
        }

        prev = cur;
        cur = cur->next;
    }
    return 0;
}

void change_nodes(char* customerName) {
    struct NODE* prev = head;
    struct NODE* cur = head->next;

    int rank;
    int amount;
    int point;

    while (cur != NULL) {
        if (strcmp(customerName, cur->customerName) == 0) {
            printf("수정할 고객의 랭크 : ");
            scanf_s("%d", &rank);

            printf("수정할 고객의 구매량 : ");
            scanf_s("%d", &amount);

            printf("수정할 고객의 포인트 : ");
            scanf_s("%d", &point);

            delete_node(customerName);

            insert_node_priority(create_node(customerName, rank, amount, point));

            return 1;
        }

        prev = cur;
        cur = cur->next;
    }
}

int main() {
    head = (struct NODE*)malloc(sizeof(struct NODE));
    head->next = NULL;

    int inst;
    int iteration = 1;

    char name[50];
    int rank;
    int amount;
    int point;

    while (iteration) {
        printf("1. 고객 추가\n");
        printf("2. 고객 삭제\n");
        printf("3. 고객 정보 수정\n");
        printf("4. 전체 리스트 출력\n");
        printf("5. 프로그램 종료\n");
        printf("명령 입력 : ");
        scanf_s("%d", &inst);
        printf("\n");

        switch (inst) {
        case 1:
            printf("고객 이름 : ");
            scanf_s("%s", name, 50);

            printf("고객 등급(0~4) : ");
            scanf_s("%d", &rank);

            printf("고객 구매량 : ");
            scanf_s("%d", &amount);

            printf("고객 포인트 : ");
            scanf_s("%d", &point);
            printf("\n");

            insert_node_priority(create_node(name, (enum rank)rank, amount, point));

            break;

        case 2:
            printf("삭제할 고객의 이름 : ");
            scanf_s("%s", name, 50);
            delete_node(name);
            break;

        case 3:
            printf("수정할 고객의 이름 : ");
            scanf_s("%s", name, 50);

            change_nodes(name);

            break;

        case 4:
            print_nodes();
            break;

        case 5:
        default:
            iteration = 0;
            break;
        }
    }

    return 0;
}
