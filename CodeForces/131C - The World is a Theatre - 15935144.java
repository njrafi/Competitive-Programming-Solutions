import java.util.*;
import java.math.BigInteger;
 /* Name of the class has to be "Main" only if the class is public. */
public class Main
{
 public static void main(String[] args)
 {
  Scanner in = new Scanner(System.in);
  int n,m,t,i,j,k;
  BigInteger ans ,tem,t1,t2,t3,t4,t5,t6,a,b;
  n = in.nextInt();
  m = in.nextInt();
  t = in.nextInt();
  ans = BigInteger.ZERO;
      for(i=4;i<=n;i++)
        for(j=1;j<=m;j++)
            if(i+j==t)
            {
             a = BigInteger.ONE;
             b = BigInteger.ONE;
             t1 = BigInteger.ONE;
             for(k=1;k<=n;k++)
             {
              tem = BigInteger.valueOf(k);
              t1 = t1.multiply(tem);
             }
             t2 = BigInteger.ONE;
             for(k=1;k<=n-i;k++)
             {
              tem = BigInteger.valueOf(k);
              t2 = t2.multiply(tem);
             }
             t3 = BigInteger.ONE;
             for(k=1;k<=i;k++)
             {
              tem = BigInteger.valueOf(k);
              t3 = t3.multiply(tem);
             }
             t4 = BigInteger.ONE;
             for(k=1;k<=m;k++)
             {
              tem = BigInteger.valueOf(k);
              t4 = t4.multiply(tem);
             }
             t5 = BigInteger.ONE;
             for(k=1;k<=m-j;k++)
             {
              tem = BigInteger.valueOf(k);
              t5 = t5.multiply(tem);
             }
             t6 = BigInteger.ONE;
             for(k=1;k<=j;k++)
             {
              tem = BigInteger.valueOf(k);
              t6 = t6.multiply(tem);
             }
             a = a.multiply(t1);
             a = a.divide(t2);
             a = a.divide(t3);
             b = b.multiply(t4);
             b = b.divide(t5);
             b = b.divide(t6);
             a = a.multiply(b);
             ans = ans.add(a);
            }
            System.out.println(ans);
 }
}