#include <stdio.h>
#include <conio.h>
void main()
{
    int allocated[15][15], max[15][15], need[15][15], avail[15], tres[15], work[15], flag[15];
    int pno, rno, i, j, prc, count, t, total;
    count = 0;

    printf("\n Nhap so tien trinh: ");
    scanf("%d", &pno);
    printf("\n Nhap so tai nguyen: ");
    scanf("%d", &rno);
    for (i = 1; i <= pno; i++)
    {
        flag[i] = 0;
    }
    printf("\n Nhap tong so luong cua moi tai nguyen: ");
    for (i = 1; i <= rno; i++)
        scanf("%d", &tres[i]);


    printf("\n Nhap tai nguyen Max cua moi tien trinh: ");
    for (i = 1; i <= pno; i++)//Nhập ma trận MAX
    {
        printf("\n tien trinh %d: ", i);
        for (j = 1; j <= rno; j++)
            scanf("%d", &max[i][j]);
    }


    printf("\n Nhap tai nguyen Allocated cua moi tien trinh: ");
    for (i = 1; i <= pno; i++)//nhập ma trận Allocation
    {
        printf("\n tien trinh %d: ", i);
        for (j = 1; j <= rno; j++)
            scanf("%d", &allocated[i][j]);
    }

    printf("\n tai nguyen Available: ");
    for (j = 1; j <= rno; j++)//tính tài nguyên sẳn hiện tại của hệ thống
    {
        avail[j] = 0;
        total = 0;
        for (i = 1; i <= pno; i++)
        {
            total += allocated[i][j];
        }
        avail[j] = tres[j] - total;
        work[j] = avail[j];
        printf("%d ", work[j]);
    }

    do
    {
        for (i = 1; i <= pno; i++)//tính ma trận need
        {
            for (j = 1; j <= rno; j++)
            {
                need[i][j] = max[i][j] - allocated[i][j];
            }
        }

        printf("\n   Allocated          Max            Need");
        for (i = 1; i <= pno; i++)
        {
            printf("\n");
            for (j = 1; j <= rno; j++)
            {
                printf("%4d", allocated[i][j]);
            }
            printf("   |");
            for (j = 1; j <= rno; j++)
            {
                printf("%4d", max[i][j]);
            }
            printf("   |");
            for (j = 1; j <= rno; j++)
            {
                printf("%4d", need[i][j]);
            }
        }

        prc = 0;

        for (i = 1; i <= pno; i++)
        {
            if (flag[i] == 0)
            {
                prc = i;

                for (j = 1; j <= rno; j++)
                {
                    if (work[j] < need[i][j])
                    {
                        prc = 0;
                        break;
                    }
                }
            }
            if (prc != 0)
                break;
        }

        if (prc != 0)
        {
            printf("\n Tien trinh %d hoan thanh", i);
            count++;
            printf("\n Available: ");
            for (j = 1; j <= rno; j++)
            {
                work[j] += allocated[prc][j];
                allocated[prc][j] = 0;
                max[prc][j] = 0;
                flag[prc] = 1;
                printf("%d ", work[j]);
            }
        }
    } while (count != pno && prc != 0);

    if (count == pno)
        printf("\nHe thong an toan!!");
    else
        printf("\nHe thong khong an toan!!");

    getch();
}