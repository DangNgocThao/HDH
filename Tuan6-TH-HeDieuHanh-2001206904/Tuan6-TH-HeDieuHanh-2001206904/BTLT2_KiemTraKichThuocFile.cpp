#include <stdio.h>
#include <stdlib.h>
long filesize(FILE* f)
{
    fseek(f, 0, SEEK_END); // đọc file từ đầu tới cuối
    return ftell(f); // trả về vị trí cuối cùng
}
void main()
{
    FILE* f; // tạo con trỏ tới file
    f = fopen("input.txt", "rb"); // đọc file dưới dạng binary
    if (!f)
    {
        printf("Error: file not found!"); // nếu có lỗi
        exit(1);
    }
    printf("File Size: %d bytes", filesize(f)); // in ra kích thước file
}