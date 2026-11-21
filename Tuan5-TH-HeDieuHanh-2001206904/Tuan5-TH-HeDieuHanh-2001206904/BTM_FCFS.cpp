//#include <stdio.h>
//struct process
//{
//	int ma_tientrinh, tgcho, tgxuly, tong_tgian;
//}p[20];
//void main()
//{
//	int i, n, j, tong_tgcho = 0, tong_tghoantat = 0, tg_cho_tb, tg_hoantat_tb;
//	printf("Nhap so tien trinh: ");
//	scanf("%d", &n);
//	for (i = 1; i <= n; i++)
//	{
//		printf("Nhap ma dinh danh tien trinh: ");
//		scanf("%d", &p[i].ma_tientrinh);
//		printf("Nhap thoi gian xu ly cua tien trinh: ");
//		scanf("%d", &p[i].tgxuly);
//	}
//	p[1].tgcho = 0;
//	p[1].tong_tgian = p[1].tgxuly;
//	for (i = 2; i <= n; i++)
//	{
//		for (j = 1; j < i; j++)
//		{
//			p[i].tgcho = p[i].tgcho + p[j].tgxuly;//tính thời gian chờ của từng tiến trình
//		}
//		tong_tgcho = tong_tgcho + p[i].tgcho;//tính tổng thời gian chờ
//		p[i].tong_tgian = p[i].tgcho + p[i].tgxuly;//tính thời gian hoàn tất của từng tiến trình
//		tong_tghoantat = tong_tghoantat + p[i].tong_tgian;//tính tổng thời gian hoàn tất
//	}
//	//tính thời gian chờ trung bình và thời gian hoàn tất trung bình
//	tg_hoantat_tb = tong_tghoantat / n;
//	tg_cho_tb = tong_tgcho / n;
//	printf("TT\tTG-XuLy\tTG-Cho\tTong");
//	for (i = 1; i <= n; i++)
//	{
//		printf("\n%d\t%d\t%d\t%d\n", p[i].ma_tientrinh, p[i].tgxuly, p[i].tgcho, p[i].tong_tgian);
//	}
//	printf("Thoi gian cho trung binh: %d\n", tg_cho_tb);
//	printf("Thoi gian hoan tat trung binh: %d\n", tg_hoantat_tb);
//}