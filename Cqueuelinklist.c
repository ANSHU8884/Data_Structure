#include<stdio.h>
#include<stdlib.h>

struct queue
{
	struct queue* prev;
	int data;
	struct queue* next;
};
struct queue* createnode()
{
	int element;
	struct queue* Qptr = NULL;
	Qptr = (struct queue*)malloc(sizeof(struct queue));
	if (Qptr == NULL)
	{
		printf("Memory not allocated.\n");
	}
	else
	{
		printf("Enter the element :\n");
		scanf_s("%d", &element);
		Qptr->prev = NULL;
		Qptr->data = element;
		Qptr->next = NULL;
	}
	return Qptr;
}
//insert at first
void insert(struct queue** front, struct queue** rear)
{
	struct queue* Qptr = NULL;
	Qptr = createnode();
	if (*front == NULL || *rear == NULL)
	{
		*front = Qptr;
		*rear = Qptr;
	}
	else
	{
		Qptr->next = *front;
		(*front)->prev = Qptr;
		*front = Qptr;
	}
}
//display
void display(struct queue* front)
{
	if (front == NULL)
	{
		printf("Queue is empty.\n");
	}
	else
	{
		while (front != NULL)
		{
			printf("%d=>", front->data);
			front = front->next;
		}
	}
	printf("\n");
}
//delete at last
void delete(struct queue** front, struct queue** rear)
{
	if (*front == NULL || *rear == NULL)
	{
		printf("Queue is empty.\n");
	}
	else if ((*front)->next == NULL)
	{
		printf("The deleted element is : %d\n", (*front)->data);
		free(*front);
		*front = *rear = NULL;
	}
	else
	{
		printf("The deleted element is : %d\n", (*rear)->data);
		*rear = (*rear)->prev;
		free((*rear)->next);
		(*rear)->next = NULL;
	}
}
void main()
{
	struct queue Q;
	int choice;
	struct queue* front = NULL;
	struct queue* rear = NULL;
	do
	{
		printf("1. Insert element.\n");
		printf("2. Display queue.\n");
		printf("3. Delete element.\n");
		printf("Enter your choice :\n");
		scanf_s("%d", &choice);
		switch (choice)
		{
		case 1:
			insert(&front, &rear);
			break;
		case 2:
			display(front);
			break;
		case 3:
			delete(&front, &rear);
			break;
		case 0:
			exit(0);
		default:
			printf("Please enter a valid choice.\n");
			break;
		}
	} while (choice != 0);
}