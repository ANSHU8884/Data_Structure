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

void displayforward(struct node* head1)
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


void displaybackward(struct node* head2)
{
	if (head2 == NULL)
	{
		printf("linked list not available\n");
	}
	else
	{
		while (head2 != NULL)
		{
			printf("%d\n", head2->data);
			head2 = head2->prev;
		}
	}
}

void insertatfirst(struct node** head1, struct node** head2)
{
	struct node* tempnode = NULL;
	tempnode = createnode();
	if (*head1 == NULL && *head2 == NULL)
	{
		*head1 = *head2 = tempnode;
	}
	else
	{
		(*head1)->prev = tempnode;
        tempnode->next = *head1;
		*head1 = tempnode;
	}
}

void insertatlast(struct node** head1, struct node** head2)
{
	createlinkedlist(head1, head2);
}

int countnode(struct node* head1)
{
	int count = 0;
	while (head1 != NULL)
	{
		count++;
		head1 = head1->next;
	}
	return count;
}
void insertatposition(struct node** head1, struct node** head2)
{
	int pos, i, n;                                                                                                                                                                                                                                                                                                                                                                                                                                                 
	struct node* tempnode = NULL;
	struct node* travenode = *head1;
	printf("enter position:");
	scanf_s("%d", &pos);
	n = countnode(*head1);
	if (pos == 1)
	{
		insertatfirst(head1, head2);
	}
	else if (pos == n)
	{
		insertatlast(head1, head2);
	}
	else if (pos<1 || pos>n + 1)
	{
		printf("invalid position\n");
		insertatposition(head1, head2);
	}
	else
	{
		tempnode = createnode();
		for (i = 1; i < pos-1 ; i++)
		{
			travenode = travenode->next;
		}
		tempnode->prev = travenode;
		tempnode->next=travenode->next;
		travenode->next = tempnode;
		travenode->next->prev = tempnode;
	}

}
void deleteatfirst(struct node** head1, struct node** head2)
{
	if (*head1 == NULL)
	{
		printf("linked list not available\n");
	}
	else
	{
		struct node* tempnode = *head1;
		*head1 = (*head1)->next;
		(*head1)->prev = NULL;
		free(tempnode);
	}
}

void deleteatlast(struct node** head1, struct node** head2)
{
	if (*head2==NULL)
	{
		printf("linked list not available\n");
	}
	else if ((*head1)->next == NULL)
	{
		free(*head1);
		*head1 = NULL;
	}
	else
	{
		struct node* tempnode = *head2;
		(*head2)->prev->next = NULL;
		(*head2) = (*head2)->prev;
		free(tempnode);
	}
}

void deleteatposition(struct node** head1, struct node** head2)
{
	int pos, i, n;
	struct node* tempnode = NULL;
	struct node* travenode = *head1;
	printf("enter position:");
	scanf_s("%d", &pos);
	n = countnode(*head1);
	if (pos == 1)
	{
		deleteatfirst(head1, head2);
	}
	else if (pos == n)
	{
		deleteatlast(head1, head2);
	}
	else if (pos<1 || pos>n + 1)
	{
		printf("invalid position\n");
		deleteatposition(head1, head2);
	}
	else
	{
		struct node* tempnode = *head1;
		for (i = 1; i < pos; i++)
		{
			tempnode = tempnode->next;
		}
		tempnode->prev->next = tempnode->next;
		tempnode->next->prev = tempnode->prev;
		free(tempnode);
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
		printf("3. Display Linked list in backward\n");
		printf("4. Insert at first\n");
		printf("5. Insert at last\n");
		printf("6. Insert at position\n");
		printf("7. Delete at first\n");
		printf("8. Delete at last\n");
		printf("9. Delete at position\n");
		printf("0. EXIT\n");

		printf("enter your choice:");
		scanf_s("%d", &choice);

		switch (choice)
		{
		case 1:createlinkedlist(&first, &last);
			break;
		case 2:displayforward(first);
			break;
		case 3:displaybackward(last);
			break;
		case 4:insertatfirst(&first, &last);
			break;
		case 5:insertatlast(&first, &last);
			break;
		case 6:insertatposition(&first, &last);
			break;
		case 7:deleteatfirst(&first, &last);
			break;
		case 8:deleteatlast(&first, &last);
			break;
		case 9:deleteatposition(&first, &last);
			break;
		case 0:exit(0);
			break;
		default:printf("please enter valid choice\n");
			break;
		}
	} while (choice != 0);
}