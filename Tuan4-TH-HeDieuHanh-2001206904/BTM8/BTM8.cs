using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace BTM8
{
    class ThreadDeadLock
    {
        static object syncObj1 = new object();
        static object syncObj2 = new object();
        static void Main()
        {
            Thread t1 = new Thread(Foo);//tạo tiểu trình t1
            Thread t2 = new Thread(Bar);//tạo tiểu trình t2
            t1.Start();//tiểu trình t1 chạy
            t2.Start();//tiểu trình t2 chạy
            Console.ReadKey();
        }
        static void Foo()//hàm xuất chuỗi foo theo khóa
        {
            Console.WriteLine("Inside Foo method");
            lock(syncObj1)
            {
                Console.WriteLine("Foo: lock(syncObj1)");
                Thread.Sleep(100);
                lock(syncObj2)
                {
                    Console.WriteLine("Foo: lock(syncObj2)");
                }
            }
        }
        static void Bar()//hàm xuất chuỗi bar theo khóa
        {
            Console.WriteLine("Inside Bar method");
            lock (syncObj2)
            {
                Console.WriteLine("Bar: lock(syncObj2)");
                Thread.Sleep(100);
                lock (syncObj1)
                {
                    Console.WriteLine("Bar: lock(syncObj1)");
                }
            }
        }
    }
}
