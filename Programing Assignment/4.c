#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev, *next;
};

void insertAfter(struct node* prevNode, int data) {
    if (prevNode == NULL) return;

    struct node* newNode = malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = prevNode->next;
    newNode->prev = prevNode;

    if (prevNode->next != NULL)
        prevNode->next->prev = newNode;

    prevNode->next = newNode;
}

void deleteNode(struct node** head, struct node* del) {
    if (*head == NULL || del == NULL) return;

    if (*head == del)
        *head = del->next;

    if (del->next != NULL)
        del->next->prev = del->prev;

    if (del->prev != NULL)
        del->prev->next = del->next;

    free(del);
}

void display(struct node* head) {
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main() {
    struct node* head = malloc(sizeof(struct node));
    head->data = 10;
    head->prev = head->next = NULL;

    insertAfter(head, 20);
    insertAfter(head->next, 30);

    printf("List: ");
    display(head);

    deleteNode(&head, head->next);

    printf("\nAfter Deletion: ");
    display(head);

    return 0;
}

