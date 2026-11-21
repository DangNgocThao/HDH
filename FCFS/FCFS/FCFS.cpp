#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
void main()
{
    int* bt, * at, waitTimeSum = 0, turnTimeSum = 0;
    int time = 0, n, smallest, count = 0;
    printf("Nhap so tien trinh: ");
    scanf("%d", &n);
    bt = (int*)malloc(n * sizeof(int));
    at = (int*)malloc((n + 1) * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        printf("Nhap thoi gian den P%d : ", i + 1);
        scanf("%d", &at[i]);
        printf("Nhap thoi gian xu ly P%d : ", i + 1);
        scanf("%d", &bt[i]);
    }

    printf("\n   Tien trinh   |Thoi gian xu ly| Thoi gian cho |Thoi gian hoan tat\n\n");
    at[n] = INT_MAX;

    while (count != n)
    {
        smallest = n;
        for (int i = 0; i < n; i++)
        {
            if (at[i] < at[smallest] && bt[i] > 0)
            {
                smallest = i;
            }
        }

        time += bt[smallest];
        waitTimeSum += time - at[smallest] - bt[smallest];
        turnTimeSum += time - at[smallest];

        printf("\tP%d\t|\t%d\t|\t%d\t|\t%d\n", smallest + 1, bt[smallest], time - at[smallest] - bt[smallest], time - at[smallest]);

        bt[smallest] = 0;
        count++;
    }

    printf("\nThoi gian cho trung binh: %.3f", waitTimeSum * 1.0 / n);
    printf("\nThoi gian hoan tat trung binh: %.3f\n", turnTimeSum * 1.0 / n);
    getch();
}