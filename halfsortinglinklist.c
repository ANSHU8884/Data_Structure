/*
*c program to sort half linked list in ascending order and half linked list in descending order
* owner-Anshu Balasaheb Kasar
* batch-PPA10
*/
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
		printf("enter data:");
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

void sortlinklist(struct node* head)
{
	int temp, n, i, j;
	struct node* temp1 = head;
	struct node* temp2 = temp1->next;
	n = countnode(head);
	for (i = 1; i < n; i++)
	{
		temp1 = head;
		temp2 = temp1->next;
		for (j = 1; j < n / 2; j++)
		{
			if (temp1->data > temp2->data)
			{
				temp = temp1->data;
				temp1->data = temp2->data;
				temp2->data = temp;
			}
			temp1 = temp1->next;
			temp2 = temp2->next;
		}
		temp1 = temp1->next;
		temp2 = temp2->next;
		for (j = n / 2+1; j < n; j++)
		{
			if (temp1->data < temp2->data)
			{
				temp = temp2->data;
				temp2->data = temp1->data;
				temp1->data = temp;
			}
			temp1 = temp1->next;
			temp2 = temp2->next;
		}
	}
}
void main()
{
	int choice;
	struct node* first = NULL;
	do
	{

		printf("\n1. Create linked list\n");
		printf("2. Display linked list\n");
		printf("3. sorting linked list\n");
		printf("0.EXIT\n");
		printf(" enter choice:");
		scanf_s("%d", &choice);

		switch (choice)
		{
		case 1:createlinkedlist(&first);
			break;
		case 2:displaylinkedlist(first);
			break;
		case 3:sortlinklist(first);
			break;
		case 0:exit(0);
			break;
		default:printf("please enter valid choice\n");
			break;
		}
	} while (choice != 0);
}
