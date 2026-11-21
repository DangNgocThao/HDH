#include <stdio.h>
#include <stdlib.h>
void main()
{
	int n, i, * ptr, sum = 0;
	printf("Enter number of elements: ");
	scanf("%d", &n);
	ptr = (int*)malloc(n * sizeof(int));
	//nếu bộ nhớ không được cấp phát
	if (ptr == NULL)
	{
		printf("Error! memory not allocated.");
		exit(0);
	}
	printf("Enter elements: ");
	for (i = 0; i < n; ++i)
	{
		scanf("%d", ptr + i);
		sum += *(ptr + i);
	}
	printf("Sum = %d", sum);
	//giải phóng bộ nhớ
	free(ptr);
}