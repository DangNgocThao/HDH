//#include <stdio.h>
//#define MAX 100
//void main()
//{
//    int bt[MAX], p[MAX], wt[MAX], tat[MAX], i, j, n, total = 0, pos, temp;
//    float avg_wt, avg_tat;
//    printf("Nhap so tien trinh: ");
//    scanf("%d", &n);
//    printf("\nNhap thoi gian xu ly cua tien trinh: \n");
//    for (i = 0; i < n; i++)
//    {
//        printf("p%d:", i + 1);
//        scanf("%d", &bt[i]);
//        p[i] = i + 1;
//    }
//    //sắp xếp theo thời gian xử lý
//    for (i = 0; i < n; i++)
//    {
//        pos = i;
//        for (j = i + 1; j < n; j++)
//        {
//            if (bt[j] < bt[pos])
//                pos = j;
//        }
//        temp = bt[i];
//        bt[i] = bt[pos];
//        bt[pos] = temp;
//        temp = p[i];
//        p[i] = p[pos];
//        p[pos] = temp;
//    }
//    wt[0] = 0;
//    for (i = 1; i < n; i++)
//    {
//        wt[i] = 0;
//        for (j = 0; j < i; j++)
//            wt[i] += bt[j];//tính thời gian chờ của từng tiến trình
//        total += wt[i];//tính tổng thời gian chờ
//    }
//    avg_wt = (float)total / n;//tính thời gian chờ trung bình
//    total = 0;
//    printf("\nTT\tTG Xu Ly\tTG Cho\t\tTG Hoan Tat");
//    for (i = 0; i < n; i++)
//    {
//        tat[i] = bt[i] + wt[i];//tính thời gian hoàn tất của từng tiến trình
//        total += tat[i];//tính tổng thời gian hoàn tất
//        printf("\np%d\t%d\t\t%d\t\t%d", p[i], bt[i], wt[i], tat[i]);
//    }
//    avg_tat = (float)total / n;//tính thời gian hoàn tất trung bình
//    printf("\n\nThoi gian cho trung binh: %f", avg_wt);
//    printf("\nThoi gian hoan tat trung binh: %f\n", avg_tat);
//}