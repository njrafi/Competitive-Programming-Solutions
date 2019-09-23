using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
namespace ConsoleApp3
{
class Program
{
    static void Main(string[] args)
    {
        string[] in1 = Console.ReadLine().Split(' ');
        int n = int.Parse(in1[0]);
        int m = int.Parse(in1[1]);
        string in3 = Console.ReadLine();
        StringBuilder s = new StringBuilder(in3);
        while (m > 0)
        {
            m--;
            string[] in2 = Console.ReadLine().Split(' ');
            int l = int.Parse(in2[0]);
            int r = int.Parse(in2[1]);
            char a = char.Parse(in2[2]);
            char b = char.Parse(in2[3]);
            for (int i = l - 1; i < r; i++)
                if (s[i] == a)
                    s[i] = b;
        }
        Console.WriteLine(s.ToString());
        //Console.ReadKey();
    }
}
} // namespace ConsoleApp3