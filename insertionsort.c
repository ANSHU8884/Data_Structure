#include<stdio.h>
#include<stdlib.h>
void insertion_sort(int arr[], int n)
{
	int value;
	int empty, i;
	for (i = 1; i < n; i++)
	{
		value = arr[i];
		empty = i;
		while (empty > 0 && arr[empty - 1] > value)
		{
			arr[empty] = arr[empty - 1];
			empty--;
		}
		arr[empty] = value;
	}
}
void main()
{
	int value;      
	int empty, i, n;
	int arr[10];
	printf("enter no of elements:");
	scanf_s("%d", &n);
	printf("enter array elements:");
	for (i = 0; i < n; i++)
	{
		scanf_s("%d",&arr[i]);
	}
	printf("unsorted array elements are:\n");
	for (i = 0; i<n;i++)
	{
		printf("%d\t", arr[i]);
	}
	insertion_sort(arr, n);
	printf("sorted elements are:\n");
	for (i = 0; i < n; i++)
	{
		printf("%d\t", arr[i]);
	}
}