//package codeforces;
 import java.util.Scanner;
public class A50 {
        public static void main(String args[])
        {
            Scanner in = new Scanner(System.in);
            int a,b;
            a = in.nextInt();
            b = in.nextInt();
            if( (a*b) % 2 != 0)
                    System.out.println( ((a*b)-1)/2);
            else
                    System.out.println(a*b/2);
                                    }
}