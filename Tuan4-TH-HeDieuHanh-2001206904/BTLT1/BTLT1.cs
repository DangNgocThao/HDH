using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BTLT1
{
    class Program
    {
        static void Main()
        {
            int n;
            do
            {
                Console.Write("Nhap n: ");
                n = Convert.ToInt32(Console.ReadLine());
            } while (n <= 0);//nhập n > 0
            fibonacciN(n);
            Console.ReadKey();
        }
        static int fibonacci(int n)//hàm tính số fibonacci
        {
            if (n == 1 || n == 2)
                return 1;
            else
                return fibonacci(n - 1) + fibonacci(n - 2);
        }
        static void fibonacciN(int n)//hàm xuất số fibonacci
        {
            Console.Write("Chuoi fibonacci den n: ");
            for (int i = 1; i < n; i++)
            {
                if (fibonacci(i) <= n)
                    Console.Write(fibonacci(i) + " ");
                else
                    break;
            }
        }
    }
}