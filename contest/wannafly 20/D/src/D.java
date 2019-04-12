import java.math.BigInteger;
import java.util.Scanner;

public class D {
    public static void main (String [] args){
        BigInteger n,m,k;
        Scanner in=new Scanner(System.in);
        n=in.nextBigInteger();
        m=in.nextBigInteger();
        k=in.nextBigInteger();
        BigInteger res=new BigInteger();
        res=n.multiply(m);
        n=n.add(k.multiply(BigInteger.valueOf(-1)));
        m=m.add(k.multiply(BigInteger.valueOf(-1)));
        BigInteger temp1,temp2;
        for(BigInteger i=m;i>BigInteger.valueOf(0);i.add(BigInteger.valueOf(1))){

        }
    }
}
