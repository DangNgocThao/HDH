using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace BTM7
{
    class ThreadLocking
    {
        static int amount = 0;
        static void Main()
        {
            Thread t1 = new Thread(IncreaseAmount);//tạo tiểu trình t1
            Thread t2 = new Thread(DecreaseAmount);//tạo tiểu trình t2
            t1.Start();//tiểu trình t1 chạy
            t2.Start();//tiểu trình t2 chạy
            Console.ReadKey();
        }
        static void IncreaseAmount()//hàm tăng giá trị amount
        {
            for (int i = 0; i < 100; i++)
            {
                amount++;
                if (amount > 0)
                {
                    Thread.Sleep(1);
                    Console.Write(amount + "\t");
                }
            }
        }
        static void DecreaseAmount()//hàm giảm giá trị amount
        {
            for (int i = 0; i < 100; i++)
            {
                amount--;
            }
        }
    }
}
