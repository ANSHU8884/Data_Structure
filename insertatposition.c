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
		printf("no memeory is allocated\n");
		return NULL;
	}
	else
	{
		printf("enter data:\n");
		scanf_s("%d", &a);
		newnode->data = a;
		newnode->next = NULL;
		return newnode;
	}
}

void createlinkedlist(struct node** head)
{
	struct node* tempnode = NULL;
	struct node* travenode = *head;
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

void insertatfirst(struct node** head)
{
	struct node* tempnode = NULL;
	tempnode = createnode();
	tempnode->next = *head;
	*head = tempnode;
}

void insertatlast(struct node** head)
{
	createlinkedlist(head);
}


int countnode(struct node* head)
{
	int count = 0;
	while (head != NULL)
	{
		head = head->next;
		count++;
	}
	return count;
}

void insertatposition(struct node** head)
{
	int pos, noofnode;
	int i;
	struct node* tempnode = NULL;
	struct node* travenode = *head;
	noofnode = countnode(*head);
	printf("enter position:\n");
	scanf_s("%d", &pos);

	if (pos == 1)
	{
		insertatfirst(head);
	}
	else if (pos == noofnode + 1)
	{
		insertatlast(head);
	}
	else if (pos<1 || pos>noofnode + 1)
	{
		printf("invalid position\n");
		insertatposition(head);
	}
	else
	{
		tempnode = createnode();
		for (i = 1; i < pos - 1; i++)
		{
			travenode = travenode->next;
		}
		tempnode->next = travenode->next;
		travenode->next = tempnode;
	}
}


void main()
{
	int choice;
	struct node* first = NULL;

	do
	{
		printf("1. Create linked list\n");
		printf("2. Display linked list\n");
		printf("3. Insert at first\n");
		printf("4. Insert at last\n");
		printf("5. Insert at position\n");
		printf("0.EXIT\n");

		printf("enter your choice:\n");
		scanf_s("%d", &choice);

		switch (choice)
		{
		case 1: createlinkedlist(&first);
			break;
		case 2: displaylinkedlist(first);
			break;
		case 3: insertatfirst(&first);
			break;
		case 4: insertatlast(&first);
			break;
		case 5: insertatposition(&first);
			break;
		case 0:exit(0);
			break;
		default: printf("please enter valid choice\n");
		}
	} while (choice != 0);
}