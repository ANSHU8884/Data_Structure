#include<stdio.h>
#define MAX 10
struct queue
{
	int arr[MAX];
	int front;
	int rear;
};
void init_queue(struct queue* qptr)
{
	qptr->rear = -1;
	qptr->front = -1;
}
int isfull(struct queue* qptr)
{
	return qptr->rear == MAX - 1;
}
void enqueue(struct queue* qptr,int value)
{
	if (!isfull(qptr))
	{
		(qptr->rear)++;
		qptr->arr[qptr->rear] = value;
	}
	else
	{
		printf("Queue is full\n");
	}
}
int isempty(struct queue* qptr)
{
	return qptr->rear == qptr->front;
}
int dequeue(struct queue* qptr)
{
	int n;
	if (!isempty(qptr))
	{
		(qptr->front)++;
		n = qptr->arr[qptr->front];

		return n;
	}
	else
	{
		printf("Q is empty\n");
	}
}
void bfs(int graph[8][8], int start, int n)
{
	struct queue q;
	init_queue(&q);
	int i = start;
	int visited[8];
	for (int k = 1; k <= n; k++)
	{
		visited[k] = 0;
	}
	enqueue(&q, i);
	printf("%d", i);
	while (!isempty(&q))
	{
		visited[i] = 1;
		i = dequeue(&q);
		for (int j = 1; j <= n; j++)
		{
			if (graph[i][j] == 1 && visited[j] == 0)
			{
				visited[j] = 1;
				printf("%d", j);
				enqueue(&q, j);
			}
		}
	}
}
void main()
{
	int graph[8][8] = { {0,0,0,0,0,0,0,0},
		                {0,0,1,0,1,0,0,0},
		                {0,1,0,1,0,0,0,0},
		                {0,0,1,1,0,0,1,1}, 
		                {0,1,1,0,0,0,1,0},			   
		                {0,1,1,0,0,1,1,0},
	                    {0,0,0,1,1,0,1,0},
		                {0,0,1,1,1,0,0,1}};
	bfs(graph, 1, 7);
}