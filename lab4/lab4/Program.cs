using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace lab4
{
    class Program
    {
        static void Main(string[] args)
        {
            int a, b, c;
            Console.WriteLine("Enter a, b, c");
            a = Convert.ToInt32(Console.ReadLine());
            b = Convert.ToInt32(Console.ReadLine());
            c = Convert.ToInt32(Console.ReadLine());

            Quadratic q = new Quadratic(a, b, c);
            Console.WriteLine("Root count = {0}", q.getRootCount());
            double[] res = q.getRoots();
            if (res == null)
            {
                Console.WriteLine("No roots");
            }
            else if (res.Length == 2)
            {
                Console.WriteLine("Two roouts = {0}, {1}", res[0], res[1]);
            }
            else if(res.Length == 1)
            {
                Console.WriteLine("One root = {0}", res[0]);
            }

            Console.ReadLine();
        }
    }
}
