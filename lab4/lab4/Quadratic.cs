using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace lab4
{
    // Клас «квадратне рівняння»
    class Quadratic
    {
        // Properties
        protected int a, b, c;

        // Constructor
        public Quadratic(int _a, int _b, int _c)
        {
            a = _a; b = _b; c = _c;
        }

        // Getters
        public int getA()
        {
            return a;
        }
        public int getB()
        {
            return b;
        }
        public int getC()
        {
            return c;
        }

        // Setters
        public void setA(int _a)
        {
            a = _a;
        }
        public void setB(int _b)
        {
            b = _b;
        }
        public void setC(int _c)
        {
            c = _c;
        }

        // Get root count
        public int getRootCount()
        {
            double d = Math.Pow(b, 2) - 4 * a * c;
            if (d > 0)
                return 2;
            else if (d == 0)
                return 1;
            else
                return 0;
        }

        // Get roots
        public double[] getRoots()
        {
            double d = Math.Pow(b, 2) - 4 * a * c;
            if (d > 0)
            {
                double x1, x2;
                x1 = (-b + Math.Sqrt(d))/2*a;
                x2 = (-b - Math.Sqrt(d)) / 2 * a;
                return new double[] { x1, x2 };
            } 
            else if (d == 0)
            {
                double res = -b / 2 * a;
                return new double[] {res};
            }
            else
                return null;

            return null;
        }
    }
}
