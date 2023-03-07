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
		return NULL;
	}
	else
	{
		printf("enter data\n");
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
		count++;
		head = head->next;
	}
	return count;
}

void insertatposition(struct node** head)
{
	int pos, noofnode;
	int i;
	struct node* tempnode = NULL;
	struct node* travenode = *head;
	printf("please enter position:");
	scanf_s("%d", &pos);
	noofnode = countnode(*head);
	if (pos == 1)
	{
		insertatfirst(head);
	}
	else if (pos == noofnode + 1)
	{
		insertatlast(head);
	}
	else if (pos < 1 || pos > noofnode + 1)
	{
		printf("invalid choice\n");
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

void deleteatfirst(struct node** head)
{
	if (*head == NULL)
	{
		printf("linked list not available\n");
		return NULL;
	}
	else
	{
		struct node* tempnode = *head;
		*head = (*head)->next;
		free(tempnode);
	}
}

void deleteatlast(struct node** head)
{  
	struct node* tempnode= *head;
	if (*head == NULL)
	{
		printf("linked list not available\n");
	}
	else if ((*head)->next == NULL)
	{
		free(*head);
		*head = NULL;
	}
	else
	{
		while (tempnode->next->next != NULL)
		{
			tempnode = tempnode->next;
		}
		free(tempnode->next);
		tempnode->next = NULL;
	}
}

void deleteatposition(struct node** head)
{
	int n, pos, i;
	printf("enter a position:");
	scanf_s("%d", &pos);
	n = countnode(*head);
	if (pos == 1)
	{
		deleteatfirst(head);
	}
	else if (pos == n)
	{
		deleteatlast(head);
	}
	else if (pos<1 || pos>n)
	{
		printf("please enter valid position\n");
		deleteatposition(head);
	}
	else
	{
		struct node* temp1 = *head;
		struct node* temp2 = *head;
		for (i = 1; i < pos - 1; i++)
		{
			temp1 = temp1->next;
		}
		temp2 = temp1->next;
		temp1->next = temp2->next;
		free(temp2);
	}
}


void main()
{
	struct node* first = NULL;
	int choice;
	do
	{
	    printf("\n1. Create linked list\n");
	    printf("2. Display linked list\n");
		printf("3. Insert at first\n");
		printf("4. Insert at last\n");
		printf("5. Insert at position\n");
		printf("6. Delete at first\n");
		printf("7. Delete at last\n");
		printf("8. Delete at position\n");
	    printf("0.EXIT\n");

	    printf("Please enter your choice\n");
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
		case 6: deleteatfirst(&first);
			break;
		case 7: deleteatlast(&first);
			break;
		case 8: deleteatposition(&first);
			break;
		case 0: exit(0);
			break;
		default: printf("Please enter valid choice\n");
		}
	} while (choice != 0);
}