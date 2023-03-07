#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* next;
	struct node* prev;
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
		newnode->data = a;
		newnode->next = NULL;
		newnode->prev = NULL;
		return newnode;
	}
}
void createlinkedlist(struct node** head1, struct node** head2)
{
	struct node* tempnode = NULL;
	tempnode = createnode();
	if (*head1 == NULL && *head2==NULL)
	{
		*head1 = *head2 = tempnode;
		(*head1)->next = *head1;
		(*head2)->prev = *head1;
	}
	else
	{
		(*head2)->next = tempnode;
		tempnode->prev = (*head2);
		tempnode->next = (*head1);
		(*head1)->prev = tempnode;
		(*head2) = tempnode;
	}
}
void displayforward(struct node* head1,struct node* head2)
{
	struct node* tempnode = head1;
	if (head1 == NULL)
	{
		printf("linked list not available\n");
	}
	else
	{
		do
		{
			printf("%d\n", tempnode->data);
			tempnode = tempnode->next;
		} while (tempnode != head2);
	}
	printf("%d", tempnode->data);	
}
void displaybackward(struct node* head1,struct node* head2)
{
	struct node* tempnode = head2;
	if (head2 == NULL)
	{
		printf("linked list not available\n");
	}
	else
	{
		do
		{
			printf("%d\n", tempnode->data);
			head2 = head2->prev;
		} while (tempnode != head1);
	}	
	printf("%d", tempnode->data);
}
void main()
{
	int choice;
	struct node* first = NULL;
	struct node* last = NULL;
	do
	{
		printf("\n1.create linked list\n");
		printf("2.display linked list\n");
		printf("0.exit\n");

		printf("enter choice:");
		scanf_s("%d", &choice);

		switch (choice)
		{
		case 1:createlinkedlist(&first, &last);
			break;
		case 2:displayforward(first, last);
			break;
		case 3:displaybackward(first, last);
			break;
		case 0:exit(0);
			break;
		default:printf("please enter valid choice\n");
			break;
		}
	} while (choice != 0);
}