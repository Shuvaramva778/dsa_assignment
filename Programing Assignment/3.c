#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

void push(struct node** head, int data) {
    struct node* newNode = malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

void reversePrint(struct node* head) {
    if (head == NULL) return;
    reversePrint(head->next);
    printf("%d ", head->data);
}

int main() {
    struct node* head = NULL;

    push(&head, 10);
    push(&head, 20);
    push(&head, 30);

    printf("Reverse Traversal: ");
    reversePrint(head);

    return 0;
}
