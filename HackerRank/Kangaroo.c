using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Contest_cSharp3
{
    class Program
    {

        private static void solve()
        {

            int x1 = nint();
            int v1 = nint();
            int x2 = nint();
            int v2 = nint();
            if (x1 > x2)
            {
                int tem = x1;
                x1 = x2;
                x2 = tem;

                tem = v1;
                v1 = v2;
                v2 = tem;
            }
            if ((x2 * v1 - x1 * v2) > 0 && (v1 - v2) > 0 && (x2 * v1 - x1 * v2) % (v1 - v2) == 0)
            {
                int x = (x2 * v1 - x1 * v2) / (v1 - v2);
                if( (x-x1) % v1 ==  0 && (x-x2)%v2==0)
                    Console.WriteLine("YES");
                else
                {
                    Console.WriteLine("NO");
                }
            }
            else
            {
                Console.WriteLine("NO");
            }





        }




        static void Main(string[] args)
        {
            process();

            solve();

#if !ONLINE_JUDGE
            Console.ReadKey();
#endif
        }



        public static List<string> in1 = new List<string>();
        public static int indexOfinput = 0;



        public static int nint()
        {

            return int.Parse(in1[indexOfinput++]);

        }
        public static double ndouble()
        {

            return double.Parse(in1[indexOfinput++]);

        }
        public static string nstring()
        {

            return in1[indexOfinput++];

        }


        public static void process()
        {

            string tem;
            while ((tem = Console.ReadLine()) != null)
            {

                string[] tem2 = tem.Split(' ');
                foreach (string i in tem2)
                    if (i.Length > 0)
                        in1.Add(i);
            }

            //foreach (var i in in1)
            // Console.WriteLine(i);
        }
    }
}
