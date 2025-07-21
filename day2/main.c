#include <stdio.h>

struct node {
    void *data;
    struct node *next;
};

struct node *linked_list_new();
int linked_list_add(struct node *list, void *data);
int linked_list_insert(struct node *list, void *data, int index);
int linked_list_remove(struct node *list, int index);

struct node *linked_list_new() {
    struct node *list = malloc(sizeof(struct node));
    if (list == NULL) {
        return NULL;
    }

    list ->data = NULL;
    list ->next = NULL;
    return list;
}

int main() {
    printf("hellow");
}
