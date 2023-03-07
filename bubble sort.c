bubble_sort(int arr[], int n)
{
	int i;
	int temp;
	int j;
	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}
void main()
{
	int i, arr[10];
	int n;
	int j;
	printf("enter how many elements:\n");
	scanf_s("%d", &n);

	printf("enter array elements:\n");
	for (i = 0; i < n; i++)
	{
		scanf_s("%d", &arr[i]);
	}
	printf("unsorted elements are:\n");

	for (i = 0; i < n; i++)
	{
		printf("%d\t", arr[i]);
	}
	bubble_sort(arr, n);
	printf("sorted elements are:\n");
	for (i = 0; i < n; i++)
	{
		printf("%d\t", arr[i]);
	}
}