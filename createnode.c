#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node* next;
};
struct node* createnode()
{
	int a;
	struct node* newnode = NULL;
	newnode = (struct node*)malloc(sizeof(struct node));
	
	if (newnode == NULL)
	{
		printf("no memory allocated\n");
		return;
	}
	else
	{
		printf("enter data:");
		scanf_s("%d", &a);
		newnode->data = a;
		newnode->next = NULL;
		return newnode;
	}
}
void createlinkedlist(struct node** head)
{
	struct node* travenode = *head;
	struct node* tempnode = NULL;
	tempnode = createnode();
	if (*head == NULL)
	{
		*head = tempnode;
	}
	else
	{
		while (travenode->next != NULL)
		{
			travenode = travenode->next;
		}
		travenode->next = tempnode;
	}
}

void displaylinkedlist(struct node* head)
{
	if (head == NULL)
	{
		printf("linked list not available\n");
		return;
	}
	else
	{
		while (head != NULL)
		{ 
			printf("%d\n", head->data);
			head = head->next;
		}
	}
}
void main()
{
	struct node* first = NULL;
	int choice;
	do
	{
	    printf("1.Create linked list\n");
	    printf("2.Display linked list\n");
	    printf("0.Exit\n");

	    printf("Enter your choice\n");
	    scanf_s("%d", &choice);
	
		switch (choice)
		{
		case 1: createlinkedlist(&first);
			break;
		case 2: displaylinkedlist(first);
			break;
		case 0: exit(0);
			break;
		default: printf("please enter valid choice\n");
		}
	} while (choice != 0);
}
