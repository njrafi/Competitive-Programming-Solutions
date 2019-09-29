
//package biginteger;

import java.util.*;
import java.math.*;

public class Powerdigitsum{

	public static void main(String[] args) {
		
			Scanner sc = new Scanner(System.in);
			int t = sc.nextInt();
			for(int i=0;i<t;i++)
			{
				int n = sc.nextInt();
				BigInteger num = new BigInteger("2");
                                BigInteger ten = new BigInteger("10");
				num = num.pow(n);
                                BigInteger sum = BigInteger.ZERO;
                                while(num.compareTo(BigInteger.ZERO)!=0)
                                {
                                    sum = sum.add(num.mod(ten));
                                    num = num.divide(ten);
                                    
                                }
				System.out.println(sum);
				
			}
	}

}
