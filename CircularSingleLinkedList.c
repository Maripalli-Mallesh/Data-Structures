#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
	int data;
	struct node* next;
}node;

node* createNode(int d)
{
	node* new=(node*)malloc(sizeof(node));
	if(new==NULL)
	{
		printf("Node ceation Unsuccessfull.");
		exit(1);
	}
	new->data=d;
	new->next=NULL;
	return new;
}
void IAB(node** head,int data)
{
	node* new=createNode(data);
	if(*head==NULL)
	{
		*head=new;
		new->next=*head;
		printf("Insertion Successfull");
		return;
	}
	node* temp=*head;
	while(temp->next!=*head)
		temp=temp->next;
	temp->next=new;
	new->next=*head;
	*head=new;
	printf("Insertion Successfull");
}
void IAE(node** head,int d)
{
	node* new=createNode(d);
	if(*head==NULL)
	{
		*head=new;
		new->next=*head;
		printf("Insertion Successfull");
		return;
	}
	node* temp=*head;
	while(temp->next!=*head)
		temp=temp->next;
	temp->next=new;
	new->next=*head;
	printf("Insertion Successfull");
}
void DAB(node** head)
{
	if(*head==NULL)
	{
		printf("List is EMPTY.Nothing to be deleted !");
		return;
	}
	if ((*head)->next == *head)
	{
    free(*head);
    *head = NULL;
	printf("Deleted Successfully.");
    return;
	}
	node* t=*head;
	node* temp=*head;
	while(temp->next!=*head)
	{
		temp=temp->next;
	}

	*head=t->next;
	temp->next=*head;
	free(t);
	printf("Deleted Successfully.");
}
void DAE(node** head)
{
	if(*head==NULL)
	{
		printf("List is EMPTY.Nothing to be deleted !");
		return;
	}
	if ((*head)->next == *head)
	{
    free(*head);
    *head = NULL;
	printf("Deleted Successfully.");
    return;
	}

	node* t=*head;
	node* temp=NULL;
	while(t->next!=*head)
	{	
		temp=t;
		t=t->next;
	}
	temp->next=*head;
	free(t);
	printf("Deleted Successfully.");
}
void disp(node* head)
{
	if(head==NULL)
	{
		printf("\nLinked list is EMPTY !!");
		return;
	}
	printf("List items: ");
	node* temp=head;
	do{
		printf("%d->",temp->data);
		temp=temp->next;
	}while(temp!=head);
}
int main()
{
	node* head=NULL;
	int op,d;
	while(1)
	{
		printf("\nEnter option: ");
		scanf("%d",&op);
		switch(op)
		{
			case 1:
				printf("Enter Data: ");
				scanf("%d",&d);
				IAB(&head,d);
				break;
			case 2:
				printf("Enter Data: ");
				scanf("%d",&d);
				IAE(&head,d);
				break;
			case 3:
				disp(head);
				break;
			case 4:
				DAB(&head);
				break;
			case 5:
				DAE(&head);
				break;
			case 6:
				exit(0);
		}
	}
	return 0;
}