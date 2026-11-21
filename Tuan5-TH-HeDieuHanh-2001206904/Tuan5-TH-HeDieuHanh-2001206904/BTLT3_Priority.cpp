//#include <stdio.h>
//#define MAX 100
//void main()
//{
//    int bt[MAX], p[MAX], wt[MAX], tat[MAX], pr[MAX], i, j, n, total = 0, pos, temp;
//    float avg_wt, avg_tat;
//    printf("Nhap so tien trinh: ");
//    scanf("%d", &n);
//
//    printf("\nNhap thoi gian xu ly va do uu tien\n");
//    for (i = 0; i < n; i++)
//    {
//        printf("\nP%d\n", i + 1);
//        printf("Nhap thoi gian xu ly: ");
//        scanf("%d", &bt[i]);
//        printf("Nhap do uu tien: ");
//        scanf("%d", &pr[i]);
//        p[i] = i + 1;
//    }
//
//    //xếp tiến trình theo độ ưu tiên
//    for (i = 0; i < n; i++)
//    {
//        pos = i;
//        for (j = i + 1; j < n; j++)
//        {
//            if (pr[j] < pr[pos])
//                pos = j;
//        }
//
//        temp = pr[i];
//        pr[i] = pr[pos];
//        pr[pos] = temp;
//
//        temp = bt[i];
//        bt[i] = bt[pos];
//        bt[pos] = temp;
//
//        temp = p[i];
//        p[i] = p[pos];
//        p[pos] = temp;
//    }
//
//    wt[0] = 0; //thời gian chờ tiến trình đầu tiên là 0
//
//    //tính thời gian chờ của từng tiến trình
//    for (i = 1; i < n; i++)
//    {
//        wt[i] = 0;
//        for (j = 0; j < i; j++)
//            wt[i] += bt[j];
//
//        total += wt[i];
//    }
//
//    avg_wt = (float)total / n;      //tính thời gian chờ trung bình
//    total = 0;
//
//    printf("\nTT\tTG Xu Ly\tTG Cho\t\tTG Hoan Tat");
//    for (i = 0; i < n; i++)
//    {
//        tat[i] = bt[i] + wt[i];     //tính thời gian hoàn tất của từng tiến trình
//        total += tat[i];
//        printf("\nP%d\t%d\t\t%d\t\t%d", p[i], bt[i], wt[i], tat[i]);
//    }
//
//    avg_tat = (float)total / n;     //tính thời gian hoàn tất trung bình
//    printf("\n\nThoi gian cho trung binh: %f", avg_wt);
//    printf("\nThoi gian hoan tat trung binh: %f\n", avg_tat);
//}