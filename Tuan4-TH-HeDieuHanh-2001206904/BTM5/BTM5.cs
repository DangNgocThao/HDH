using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace BTM5
{
    class Program
    {
        static void Main(string[] args)
        {
            Thread t1 = new Thread(() =>
             {
                 Thread.Sleep(1000);
                 Console.WriteLine("Thread t1 started");
             });//tạo tiểu trình t1
            t1.Start();//tiểu trình t1 chạy
            Console.WriteLine("Main thread ending...");
            Console.ReadKey();
        }
    }
}
