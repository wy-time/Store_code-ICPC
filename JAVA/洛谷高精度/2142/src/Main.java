import java.math.BigInteger;
import java.util.Scanner;

public class Main {
    public static  void main (String [] agrs){
        Scanner in=new Scanner(System.in);
        BigInteger a;
        BigInteger b;
        a=in.nextBigInteger();
        b=in.nextBigInteger();
        b=b.multiply(BigInteger.valueOf(-1));
        System.out.println(a.add(b));
    }
}
