import java.math.BigInteger;
import java.util.Scanner;

public class Main {
    public static void main (String [] args){
        Scanner in=new Scanner(System.in);
        BigInteger a;
        a=in.nextBigInteger();
        BigInteger b;
        b=in.nextBigInteger();
        System.out.println(a.multiply(b));
    }
}
