using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace BTLT3
{
    class BTLT3
    {
        static void Main()
        {
            int[] a = new int[100];
            Console.Write("Nhap so phan tu: ");
            int n = Convert.ToInt32(Console.ReadLine());
            Random rand = new Random();
            for (int i = 0; i < n; i++)
                a[i] = rand.Next(0, 10);
            Console.Write("List: ");
            for (int i = 0; i < n; i++)
            {
                if (i == 0)
                    Console.Write("[");
                if (i == n - 1)
                    Console.Write(a[i] + "]");
                else
                    Console.Write(a[i] + ", ");
            }
            Console.Write("\nNhap vao so thread: ");
            int nThread = Convert.ToInt32(Console.ReadLine());
            int t = tinhTong(a, n, nThread);
            Console.Write("Tong list= " + t);
            Console.ReadKey();
        }
        static void mangThread(int[] a, int[] b, int d, int c, int n)//hàm tạo mảng con
        {
            int j = 0;
            for (int i = d; i < c; i++)
            {
                b[j] = a[i];
                j++;
            }
            Console.Write("Thread " + n + ":");
            for (int i = 0; i < j; i++)
            {
                Console.Write(" " + b[i] + ";");
            }
            Console.Write("\n");
        }
        static int tongMang(int[] b)//hàm tính tổng mảng
        {
            int t = 0;
            for (int i = 0; i < b.Length; i++)
            {
                t += b[i];
            }
            return t;
        }
        static int tinhTong(int[] a, int n, int nThread)//hàm tính tổng list
        {
            int tong = 0;
            int[] b = new int[100];
            int i = 0;

            while (i < nThread)
            {
                int d = ((i * n) / nThread);
                int c = ((i + 1) * n / nThread);
                mangThread(a, b, d, c, i + 1);
                tong += tongMang(b);
                i += 1;
            }
            return tong;
        }
    }
}
