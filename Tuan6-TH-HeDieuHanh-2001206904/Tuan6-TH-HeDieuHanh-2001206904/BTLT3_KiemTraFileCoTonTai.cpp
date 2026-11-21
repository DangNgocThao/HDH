#include <stdio.h>
#include <stdlib.h>
void main()
{
    FILE* f; // tạo con trỏ tới file
    f = fopen("input.txt", "r"); // đọc file
    if (!f)
    {
        printf("File khong ton tai");
        exit(1);
    }
    else
        printf("File ton tai");
    fclose(f);
}