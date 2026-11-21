using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace BTM4
{
    class Program
    {
        static void Main()
        {
            Thread t1 = new Thread(MethodA);//tạo tiểu trình t1
            Thread t2 = new Thread(MethodB);//tạo tiểu trình t2
            Thread t3 = new Thread(MethodC);//tạo tiểu trình t3
            t1.Start();//tiểu trình t1 chạy
            t2.Start();//tiểu trình t2 chạy
            t2.Join();//tiểu trình t2 tham gia
            t3.Start();//tiểu trình t3 chạy
            MethodB();
            Console.ReadKey();
        }
        static void MethodA()//Hàm xuất số 0
        {
            for (int i = 0; i < 100; i++) Console.Write("0");
        }
        static void MethodB()//Hàm xuất số 1
        {
            for (int i = 0; i < 100; i++) Console.Write("1");
        }
        static void MethodC()//Hàm xuất số 2
        {
            for (int i = 0; i < 100; i++) Console.Write("2");
        }
    }
}