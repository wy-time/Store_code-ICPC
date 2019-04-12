import java.math.BigInteger;
import java.util.Scanner;

public class Main {
    public static void main(String args[])
    {
        Scanner in=new Scanner(System.in);
        int t;
        t=in.nextInt();
        int casecnt=0;
        while(t>0)
        {
            t--;
            casecnt++;
            BigInteger a=in.nextBigInteger();
            BigInteger b=in.nextBigInteger();
            if(b.compareTo(BigInteger.valueOf(0))<0)
                b=b.multiply(BigInteger.valueOf(-1));
            if(a.mod(b)==BigInteger.valueOf(0))
            {
                System.out.println("Case "+casecnt+": "+"divisible");
            }else
                System.out.println("Case "+casecnt+": "+"not divisible");
        }
    }
}
