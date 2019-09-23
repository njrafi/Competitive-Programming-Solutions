//package codeforces;
  import java.util.Scanner;
public class A318 {
  public static void main(String[] args) {
  Scanner in = new Scanner(System.in);
  long n,k;
  n = in.nextLong();
  k = in.nextLong();
  n++;
  n /= 2;
  if(k<=n)
   System.out.println(2*k-1);
  else
   System.out.println(2*(k-n));
  }
 }