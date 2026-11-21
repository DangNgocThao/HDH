using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace BTM6
{
    class ThreadPooling
    {
        static void Main()
        {
            ThreadPool.QueueUserWorkItem(ThreadProc);
            ThreadPool.QueueUserWorkItem(ThreadProc, 123);
            Console.ReadKey();
        }
        static void ThreadProc(object data)//Hàm xuất chuỗi
        {
            for (int i = 0; i < 10; i++)
            {
                Console.WriteLine("Thread callback: " + data);
                Thread.Sleep(500);
            }
        }

    }
}
