import java.util.Scanner;
public class another {
     public static void main(String[] args)
        {
        Scanner in = new Scanner(System.in);
        int num = in.nextInt();
        if(num%2!=0 || num<=2)
            System.out.println("NO");
            else
                System.out.println("YES");
                    }
 }