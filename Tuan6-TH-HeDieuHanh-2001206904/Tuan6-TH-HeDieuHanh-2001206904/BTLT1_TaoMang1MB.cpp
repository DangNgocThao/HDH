#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
void main()
{
	char* a;
	int n = 1024 * 1024;//kích thước 1MB
	a = (char*)malloc(n);
	for (int i = 0; i < n; i++)//tạo mảng kích thước 1MB
	{
		a[i] = rand() % 26 + 97;
		printf("%c", a[i]);
	}
	if (a != NULL)//kiểm tra tạo mảng thành công không
		printf("\nTao mang 1MB thanh cong");
	else
		printf("\nTao mang 1MB that bai");
}