#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char data[50];
    struct Node* next;
    struct Node* prev;
} Node;

Node* createNode(const char* data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode)
    {
         printf("Memory allocation failed\n");
         exit(1);
    }
    strcpy(newNode->data, data);
     
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}
void IAB(Node** head, const char* data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    newNode->next = *head;
    (*head)->prev = newNode;
    *head = newNode;
}

void forwardprint(Node* head) {
    Node* current = head;
    printf("Forward: ");
    while (current != NULL) {
        printf("%s -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

void backwardprint(Node* head) {
    if (head == NULL) return;
    Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    printf("Backward: ");
    while (current != NULL) {
        printf("%s -> ", current->data);
        current = current->prev;
    }
    printf("NULL\n");
}

int main() {
    Node* head = NULL;
    IAB(&head,"S4");
    IAB(&head,"S3");
    IAB(&head,"S2");
    IAB(&head,"S1");
    forwardprint(head);
    backwardprint(head);
    return 0;
}