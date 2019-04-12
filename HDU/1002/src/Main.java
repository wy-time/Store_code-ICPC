import java.math.BigInteger;
import java.util.Scanner;

public class Main {
    public static void main (String [] args){
        Scanner in=new Scanner(System.in);
        int t;
        t=in.nextInt();
        int cnt=0;
        while(t--!=0){
            cnt++;
            BigInteger a=in.nextBigInteger();
            BigInteger b=in.nextBigInteger();
            System.out.println("Case "+cnt+":");
            System.out.println(a+" + "+b+" = "+a.add(b));
            if(t!=0)
                System.out.println();
        }
    }
}
