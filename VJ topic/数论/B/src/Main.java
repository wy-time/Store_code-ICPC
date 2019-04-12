import java.math.BigInteger;
import java.util.Scanner;

public class Main {
    public static void main(String args[]) {
        Scanner in=new Scanner(System.in);
        int t;
        t=in.nextInt();
        int casecnt=0;
        while (t>0){
            casecnt++;
            t--;
            int n=in.nextInt();
            int i;
            BigInteger res=in.nextBigInteger();
            for (i=1;i<n;i++) {
                BigInteger tt=in.nextBigInteger();
                res=res.multiply(tt).divide(res.gcd(tt));
            }
            System.out.println("Case "+casecnt+": "+res);
            System.gc();
        }
    }
}