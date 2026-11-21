using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace BTM1
{
    class Program
    {
        static void Main()
        {
            Thread t = new Thread(new ThreadStart(MethodA));//tạo tiểu trình t
            t.Start();//tiểu trình t chạy
            MethodB();
            Console.ReadKey();
        }
        static void MethodA()//Hàm xuất số 0
        {
            for (int i = 0; i < 100; i++)
                Console.Write("0");
        }
        static void MethodB()//Hàm xuất số 1
        {
            for (int i = 0; i < 100; i++)
                Console.Write("1");
        }
    }
}
