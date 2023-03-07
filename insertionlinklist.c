#include<stdio.h>		
#include<stdlib.h>

struct node
{
	struct node* prev;
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
		printf("memory not allocated\n");
		return NULL;
	}
	else
	{
		printf("enter data:\n");
		scanf_s("%d", &a);
		newnode->prev = NULL;
		newnode->data = a;
		newnode->next = NULL;
		return newnode;
	}
}

void createlinkedlist(struct node** head1, struct node** head2)
{
	struct node* tempnode = NULL;
	tempnode = createnode();

	if (*head1 == NULL && *head2 == NULL)
	{
		*head1 = *head2 = tempnode;
	}

	else
	{
		(*head2)->next = tempnode;
		tempnode->prev = *head2;
		*head2 = tempnode;

	}
}

void display(struct node* head1)
{
	if (head1 == NULL)
	{
		printf("linked list not available\n");
	}
	else
	{
		while (head1 != NULL)
		{
			printf("%d\n", head1->data);
			head1 = head1->next;
		}
	}
}
void insertionsort(struct node* head1, struct node* head2)
{
	int value;
	struct node* empty = NULL;
	struct node* travenode = head1->next;
	while (travenode != NULL)
	{
		value = travenode->data;
		empty = travenode->prev;
		while (empty != NULL && empty->data > value)
		{
			empty->next->data = empty->data;
			empty->data = value;
			empty = empty->prev;
		}
		travenode = travenode->next;
	}
}
void main()
{
	int choice;
	struct node* first = NULL;
	struct node* last = NULL;
	do
	{
		printf("1. Create Linked list\n");
		printf("2. Display Linked list in forward\n");
		printf("3. Insertion sort\n");
		printf("0. EXIT\n");

		printf("enter your choice:");
		scanf_s("%d", &choice);

		switch (choice)
		{
		    case 1:createlinkedlist(&first, &last);
				break;
			case 2:display(first);
				break;
			case 3:insertionsort(first, last);
				break;
		}
	} while (choice != 0);
}