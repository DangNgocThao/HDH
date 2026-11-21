using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace BTLT2
{
    class Program
    {
        static void Main()
        {
            Thread t1 = new Thread(Print);//tạo tiểu trình t1
            Thread t2 = new Thread(Print);//tạo tiểu trình t2
            Thread t3 = new Thread(Print);//tạo tiểu trình t3
            Thread t4 = new Thread(Print);//tạo tiểu trình t4
            Thread t5 = new Thread(Print);//tạo tiểu trình t5
            t1.Start();//tiểu trình t1 chạy
            t2.Start();//tiểu trình t2 chạy
            t3.Start();//tiểu trình t3 chạy
            t4.Start();//tiểu trình t4 chạy
            t5.Start();//tiểu trình t5 chạy
            Console.ReadKey();
        }
        static void Print()//hàm xuất chuỗi hello
        {
            Console.Write("Hello ");
        }
    }
}
