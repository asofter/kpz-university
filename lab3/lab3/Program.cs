using System;
using System.Collections.Generic;
using System.Text;
using System.Linq;

namespace lab3
{
    class Program
    {
        //На площині дані A(x1, y1) та B(x2, y2) . Знайти координати середини відрізка AB.
        static void task1()
        {
            int x1, y1, x2, y2;
            Console.WriteLine("Enter A(x,y)"); 
            x1 = Convert.ToInt32(Console.ReadLine());
            y1 = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine("Enter B(x,y)"); 
            x2 = Convert.ToInt32(Console.ReadLine());
            y2 = Convert.ToInt32(Console.ReadLine());
            double x3 = (x1 + x2) / 2;
            double y3 = (y1 + y2) / 2;
            Console.WriteLine("С(x,y)=({0}, {1})", x3, y3); 
        }

        //Дані координати точки, що не лежить на координатних осях Ox і Oy. Вивести номер координатної чверті, у якій знаходиться дана точка.
        static void task2()
        {
            int x, y;
            string res = "";
            Console.WriteLine("Enter x,y");
            x = Convert.ToInt32(Console.ReadLine());
            y = Convert.ToInt32(Console.ReadLine());

            if (x == 0)
            {
                if (y == 0)
                {
                    res = "на початку координат т.О";
                }
                else
                {
                    res = "на осі oY.";
                }
            }

            if (x < 0)
            {
                if (y < 0)
                    res = "в III четверті.";
                else if(y == 0)
                    res = "на осі oX.";
                else if(y > 0) 
                    res = "в II четверті.";
            }

            if (x > 0)
            {
                if (y < 0)
                    res = "в IV четверті.";
                else if (y == 0)
                    res = "на осі oX.";
                else if (y > 0)
                    res = "в I четверті.";
            }

            Console.WriteLine("Відрізок знаходиться {0}", res); 
        }

        // Дане натуральне число n. Обчислити An = sqrt(abs(4an-1+2*x)
        static void task3()
        {
            int i, n, x;
            double a;
            Console.WriteLine("Enter n");
            n = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine("Enter x");
            x = Convert.ToInt32(Console.ReadLine());
            a = x;
            for (i = 1;i <=n; i++) { 
                a = Math.Sqrt(Math.Abs(4*a-1+2*x));
            } 
            
            Console.WriteLine("A{0}={1}", n, a); 
        }

        //Даний масив цілих чисел розміру N. Визначити, яке з чисел зустрічається в масиві максимальну кількість раз.
        static void task4()
        {
            int n, i, max, max_key;
            Console.WriteLine("N = ");
            n = Convert.ToInt32(Console.ReadLine());
            int[] a = new int[n];
            Dictionary<int, int> counts = new Dictionary<int, int>();

            for (i = 0; i < n; i++)
            {
                Console.WriteLine("Element {0}=", i);
                a[i] = Convert.ToInt32(Console.ReadLine());
                if (!counts.ContainsKey(a[i]))
                    counts.Add(a[i], 0);
            }

            for (i = 0; i < n; i++)
            {
                counts[a[i]]++;
            }

            max = counts.Values.First();
            max_key = counts.Keys.First();
            foreach (KeyValuePair<int, int> pair in counts)
            {
                if (pair.Value > max)
                {
                    max = pair.Value;
                    max_key = pair.Key;
                }
            }

            Console.WriteLine("{0} has {1} positions in array.", max_key, max);
        }

        //Дані координати вершин трьох трикутників. Визначити, який з них має найбільшу площу .
        static void task5()
        {
            Dictionary<int, int[]> triangle1 = new Dictionary<int, int[]>();
            Dictionary<int, int[]> triangle2 = new Dictionary<int, int[]>();
            Dictionary<int, int[]> triangle3 = new Dictionary<int, int[]>();

            int x, y, i;
            double[] s = new double[3];

            // Enter values for the first triangle
            Console.WriteLine("---First triangle---");
            Console.WriteLine("a(x,y)=");
            x = Convert.ToInt32(Console.ReadLine());
            y = Convert.ToInt32(Console.ReadLine());
            triangle1.Add(1, new int[] {x,y});
            Console.WriteLine("b(x,y)=");
            x = Convert.ToInt32(Console.ReadLine());
            y = Convert.ToInt32(Console.ReadLine());
            triangle1.Add(2, new int[] { x, y });
            Console.WriteLine("c(x,y)=");
            x = Convert.ToInt32(Console.ReadLine());
            y = Convert.ToInt32(Console.ReadLine());
            triangle1.Add(3, new int[] { x, y });

            // Count square for the first triangle
            s[0] = Math.Abs((triangle1[2][0] - triangle1[1][0]) * (triangle1[3][1] - triangle1[1][1]) - (triangle1[3][0] - triangle1[1][0]) * (triangle1[2][1] - triangle1[1][1])) / 2;

            // Enter values for the second triangle
            Console.WriteLine("---Second triangle---");
            Console.WriteLine("a(x,y)=");
            x = Convert.ToInt32(Console.ReadLine());
            y = Convert.ToInt32(Console.ReadLine());
            triangle2.Add(1, new int[] { x, y });
            Console.WriteLine("b(x,y)=");
            x = Convert.ToInt32(Console.ReadLine());
            y = Convert.ToInt32(Console.ReadLine());
            triangle2.Add(2, new int[] { x, y });
            Console.WriteLine("c(x,y)=");
            x = Convert.ToInt32(Console.ReadLine());
            y = Convert.ToInt32(Console.ReadLine());
            triangle2.Add(3, new int[] { x, y });

            // Count square for the second triangle
            s[1] = Math.Abs((triangle2[2][0] - triangle2[1][0]) * (triangle2[3][1] - triangle2[1][1]) - (triangle2[3][0] - triangle1[1][0]) * (triangle2[2][1] - triangle2[1][1])) / 2;

            // Enter values for the second triangle
            Console.WriteLine("---Third triangle---");
            Console.WriteLine("a(x,y)=");
            x = Convert.ToInt32(Console.ReadLine());
            y = Convert.ToInt32(Console.ReadLine());
            triangle3.Add(1, new int[] { x, y });
            Console.WriteLine("b(x,y)=");
            x = Convert.ToInt32(Console.ReadLine());
            y = Convert.ToInt32(Console.ReadLine());
            triangle3.Add(2, new int[] { x, y });
            Console.WriteLine("c(x,y)=");
            x = Convert.ToInt32(Console.ReadLine());
            y = Convert.ToInt32(Console.ReadLine());
            triangle3.Add(3, new int[] { x, y });

            // Count square for the third triangle
            s[2] = Math.Abs((triangle3[2][0] - triangle3[1][0]) * (triangle3[3][1] - triangle3[1][1]) - (triangle3[3][0] - triangle3[1][0]) * (triangle3[2][1] - triangle3[1][1])) / 2;

            double max = s[0];
            double max_key = 0;
            for(i=1; i<3; i++) 
            {
                if (s[i] > max)
                {
                    max = s[i];
                    max_key = i;
                }
            }

            Console.WriteLine("{0} triangle has {1} square.", max_key+1, max);
        }

        static void Main(string[] args)
        {
            //task1();
            //task2();
            //task3();
            //task4();
            //task5();
            Console.ReadKey();
        }
    }
}
