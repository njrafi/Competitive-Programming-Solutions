//package codeforces;
  import java.util.Scanner;
public class A118 {
     public static void main(String[] args) {
        int sum = 0 , inp;
        Scanner in = new Scanner(System.in);
        for(int i=0;i<5;i++)
        {
            inp = in.nextInt();
            sum += inp;
        }
                if(sum%5==0 && sum>0)
            System.out.println(sum/5);
        else
            System.out.println(-1);
    }
 }