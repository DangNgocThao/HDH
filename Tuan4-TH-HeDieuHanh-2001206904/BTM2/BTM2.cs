using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace BTM2
{
    class Student
    {
        public string Name { get; set; }
        public DateTime BirthDay { get; set; }
    }
    class Program
    {
        static void Main()
        {
            Thread t1 = new Thread(Print);//tạo tiểu trình t1
            t1.Start(new Student() { Name = "ABC", BirthDay = new DateTime(1980, 10, 20) });//tiểu trình t1 chạy
            Console.ReadKey();
        }
        static void Print(object obj)//hàm xuất chuỗi
        {
            Student st = (Student)obj;
            Console.Write(st.Name + "\t" + st.BirthDay.ToShortDateString());
        }
    }
}
