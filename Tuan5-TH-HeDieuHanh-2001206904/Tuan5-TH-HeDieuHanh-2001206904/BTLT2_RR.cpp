//#include <stdio.h> 
//#define MAX 100
//void main()
//{
//    int i, limit, total = 0, x, counter = 0, time_quantum;
//    int wait_time = 0, turnaround_time = 0, arrival_time[MAX], burst_time[MAX], temp[MAX];
//    float average_wait_time, average_turnaround_time;
//    printf("Nhap so tien trinh: ");
//    scanf("%d", &limit);
//    x = limit;
//    for (i = 0; i < limit; i++)
//    {
//        printf("\nNhap noi dung tien trinh P%d\n", i + 1);
//        printf("Thoi gian den: ");
//        scanf("%d", &arrival_time[i]);
//        printf("Thoi gian xu ly: ");
//        scanf("%d", &burst_time[i]);
//        temp[i] = burst_time[i];
//    }
//    printf("\nNhap Quantum: ");
//    scanf("%d", &time_quantum);
//    printf("\nTT\tTG Xu Ly\t TG Hoan Tat\t TG Cho\n");
//    for (total = 0, i = 0; x != 0;)
//    {
//        if (temp[i] <= time_quantum && temp[i] > 0)//nếu 0 < thời gian xử lí < quantum thì thực hiện
//        {
//            total = total + temp[i];
//            temp[i] = 0;
//            counter = 1;
//        }
//        else if (temp[i] > 0)//ngược lại nếu thời gian xử lí > quantum thì thực hiện
//        {
//            temp[i] = temp[i] - time_quantum;
//            total = total + time_quantum;
//        }
//        if (temp[i] == 0 && counter == 1)//nếu thời gian xử lí = 0 thì thực hiện
//        {
//            x--;//giảm số tiến trình
//            printf("\nP%d\t%d\t\t %d\t\t %d", i + 1, burst_time[i], total - arrival_time[i], total - arrival_time[i] - burst_time[i]);
//            wait_time = wait_time + total - arrival_time[i] - burst_time[i];
//            turnaround_time = turnaround_time + total - arrival_time[i];
//            counter = 0;
//        }
//        if (i == limit - 1)
//        {
//            i = 0;
//        }
//        else if (arrival_time[i + 1] <= total)
//        {
//            i++;
//        }
//        else
//        {
//            i = 0;
//        }
//    }
//    //tính thời gian chờ trung bình và thời gian hoàn tất trung bình
//    average_wait_time = wait_time * 1.0 / limit;
//    average_turnaround_time = turnaround_time * 1.0 / limit;
//    printf("\n\nThoi gian cho trung binh: %f", average_wait_time);
//    printf("\nThoi gian hoan tat trung binh: %f\n", average_turnaround_time);
//}