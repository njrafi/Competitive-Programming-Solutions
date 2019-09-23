using System;
using System.CodeDom.Compiler;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
namespace Contest_cSharp1
{
class Program
{
private
    static void solve()
    {
        int n = nint();
        int m = nint();
        string s = nstring();
        StringBuilder tem = new StringBuilder(s);
        while (m > 0)
        {
            m--;
            int l = nint();
            int r = nint();
            string from = nstring();
            string to = nstring();
            for (int i = l - 1; i < r; i++)
                if (tem[i] == from[0])
                    tem[i] = to[0];
        }
        s = tem.ToString();
        Console.WriteLine(s);
    }
    static void Main(string[] args)
    {
        process();
        solve();
#if !ONLINE_JUDGE
        Console.ReadKey();
#endif
    }
public
    static List<string> in1 = new List<string>();
public
    static int indexOfinput = 0;
public
    static int nint()
    {
        return int.Parse(in1[indexOfinput++]);
    }
public
    static double ndouble()
    {
        return double.Parse(in1[indexOfinput++]);
    }
public
    static string nstring()
    {
        return in1[indexOfinput++];
    }
public
    static void process()
    {
        string tem;
        while ((tem = Console.ReadLine()) != null)
        {
            string[] tem2 = tem.Split(' ');
            foreach (string i in tem2)
                if (i.Length > 0)
                    in1.Add(i);
        }
        // foreach (var i in in1)
        //Console.WriteLine(i);
    }
}
} // namespace Contest_cSharp1