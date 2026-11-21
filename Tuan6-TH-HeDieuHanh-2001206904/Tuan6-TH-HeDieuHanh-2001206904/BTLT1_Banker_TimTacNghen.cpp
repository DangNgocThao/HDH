#include <stdio.h>
int ktTacNghen(int ans[], int n, int& vt)//Hàm kiểm tra chuỗi có tắt nghẽn không
{
	for (int i = 0; i < n; i++)
	{
		if (ans[i] > n || ans[i] < 0)
		{
			vt = ans[i - 1];
			return 0;
		}
	}
	return 1;
}
void main()
{
	//P0, P1, P2, P3, P4 tên của các tiến trình minh họa
	int i, j, k;
	const int n = 5;//Số tiến trình
	const int m = 3;//Số tài nguyên
	int alloc[5][3] = { {3,1,4},//P0 //Ma trận Allocation
						{2,1,0},//P1
						{3,2,1},//P2
						{0,1,0},//P3
						{4,1,2} };//P4
	int max[5][3] = { {5,1,7},//P0 //Ma trận MAX
					{3,1,1},//P1
					{3,2,1},//P2
					{4,1,2},//P3
					{6,2,5} };//P4
	int avail[3] = { 1,0,1 };//Tài nguyên sẳn hiện tại của hệ thống
	int f[n], ans[n], ind = 0;
	for (k = 0; k < n; k++)
	{
		f[k] = 0;
	}
	int need[n][m];
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
			need[i][j] = max[i][j] - alloc[i][j];
	}
	int y = 0;
	for (k = 0; k < 5; k++)
	{
		for (i = 0; i < n; i++)
		{
			if (f[i] == 0)
			{
				int flag = 0;
				for (j = 0; j < m; j++)
				{
					if (need[i][j] > avail[j])
					{
						flag = 1;
						break;
					}
				}
				if (flag == 0)
				{
					ans[ind++] = i;
					for (y = 0; y < m; y++)
						avail[y] += alloc[i][y];
					f[i] = 1;
				}
			}
		}
	}
	int vt, kt = ktTacNghen(ans, n, vt);
	if (kt == 1)
	{
		printf("Chuoi khong tac nghen\n");
		printf("Chuoi an toan la:\n");
		for (i = 0; i < n - 1; i++)
			printf(" P%d ->", ans[i]);
		printf(" P%d", ans[n - 1]);
	}
	else
	{
		printf("Chuoi tac nghen tai P%d\n", vt);
		printf("Chuoi khong an toan la:\n");
		for (i = 0; i < n - 1; i++)
			if (ans[i] > n || ans[i] < 0)
				break;
			else
				printf(" P%d ->", ans[i]);
	}
}