import java.util.*;
import java.math.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        for (int i = 1; i <= t; i++) {
            BigInteger a = sc.nextBigInteger();
            a = a.abs();
            BigInteger b = sc.nextBigInteger();
            b = b.abs();
            System.out.print("Case ");
            System.out.print(i);
            System.out.print(": ");
            BigInteger num = a.mod(b);
            if (num.compareTo(BigInteger.ZERO) != 0)
                System.out.print("not ");
            System.out.println("divisible");
        }
    }
}
