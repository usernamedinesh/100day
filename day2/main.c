#include <stdio.h>
#include <stdlib.h>  // for malloc

struct node {
    void *data;
    struct node *next;
};

struct node *linked_list_new();
int linked_list_append(struct node *list, void *data);
int linked_list_insert(struct node *list, void *data, int index);
int linked_list_remove(struct node *list, int index);

//function it creates dummy head node   
struct node *linked_list_new() {
    struct node *list = malloc(sizeof(struct node));
    if (list == NULL) {
        return NULL;
    }

    list->data = NULL;
    list->next = NULL;
    return list;
}

int linked_list_append(struct node *list, void *data) {
    struct node *new_node = malloc(sizeof(struct node));
    if (new_node == NULL) {
        return -1;
    }

    new_node->data = data;
    new_node->next = NULL;

    // Traverse to the end
    struct node *current = list;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = new_node;
    return 0;
}

int main() {
    struct node *list = linked_list_new();
    if (list == NULL) {
        printf("Failed to create list\n");
        return 1;
    }

    int value1 = 10;
    int value2 = 20;

    linked_list_append(list, &value1);
    linked_list_append(list, &value2);

    // Print the list
    struct node *current = list->next;  // skip dummy head
    while (current != NULL) {
        printf("Value: %d\n", *(int *)current->data);
        current = current->next;
    }

    return 0;
}

