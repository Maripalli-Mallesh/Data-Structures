#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    char data[20];
    struct node *next;
} node;

node* CreateNode(char data[20])
{
    node *newNode = (node*)malloc(sizeof(node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
    strcpy(newNode->data, data);
    newNode->next = NULL;
    return newNode;
}
void IAB(node **head, char data[20])
{
    node *newNode = CreateNode(data);
    newNode->next = *head;
    *head = newNode;
}

void Remove(node **head, char target[20])
{
    node *current = *head;
    node *previous = NULL;

    while (current != NULL && strcmp(current->data, target) != 0)
    {
        previous = current;
        current = current->next;
    }

    if (current == NULL)
    {
        printf("Element not found: %s\n", target);
        return;
    }

    if (previous == NULL)
    {
        *head = current->next;
    }
    else
    {
        previous->next = current->next;
    }

    free(current);
}

void PrintList(node *head)
{
    node *current = head;
    while (current != NULL)
    {
        printf("%s -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main()
{
    node *head = NULL;
    IAB(&head,"Milk");  
    IAB(&head,"Orange"); 
    IAB(&head,"Banana"); 
    IAB(&head,"Apple");
    PrintList(head);
    Remove(&head,"Orange");
    PrintList(head); 
    return 0;
}