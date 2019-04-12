import java.math.BigInteger;
import java.util.Scanner;

public class Main {
    public static void main (String [] args){
        Scanner in=new Scanner(System.in);
        int radix=in.nextInt();
        BigInteger a=in.nextBigInteger(radix);
        BigInteger b=in.nextBigInteger(radix);
        a=a.add(b);
        String res=a.toString(radix);
        res=res.toUpperCase();
        System.out.println(res);
        in.close();
    }
}
