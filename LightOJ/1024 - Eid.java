import java.util.*;
import java.math.*;
  public class Main{
      public static void main(String[] args) {
              Scanner sc = new Scanner(System.in);
            int t = sc.nextInt();
            for(int i=1;i<=t;i++)
            {
                int n = sc.nextInt();
                BigInteger ans= BigInteger.ONE;
                for(int j=1;j<=n;j++)
                    {
                        int inp = sc.nextInt();
                        BigInteger tem = BigInteger.valueOf(inp);
                          tem = tem.gcd(ans);
                        ans = ans.multiply(BigInteger.valueOf(inp));
                        ans = ans.divide(tem);
                    }
                System.out.println("Case "+ i + ": "+ ans);
                System.gc();
                        }
    }
  }