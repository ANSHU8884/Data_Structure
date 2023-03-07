#include<stdio.h>
int binary_search(int arr[], int n, int search)
{
	int low = 0;
	int high = n - 1;
	int mid = (low + high) / 2;
	while (low <= high)
	{
		if (search == arr[mid])
		{
			return mid;
		}
		else if (search < arr[mid])
		{
			high = mid - 1;
		}
		else
		{
			low = mid + 1;
		}
	}
	return -1;
}
void main()
{
	int i;
	int n, arr[20];
	int search, index;
	printf("enter number of elements:\n");
	scanf_s("%d" ,&n);
	printf("enter array elements:\n");
	for (i = 0; i < n; i++)
	{
		scanf_s("%d", &arr[i]);
	}
	printf(" array elements are :\n");
	for (i = 0; i < n; i++)
	{
		printf("%d\n", arr[i]);
	}
	printf("enter element to find:\n");
	scanf_s("%d", &search);
	int index = binary_search(arr, n, search);
	if (index != -1)
	{
		printf("number is found at index &d", index, search);
	}
	else
	{
		printf("number %d not found\n");
	}
}