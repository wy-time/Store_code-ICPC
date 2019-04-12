import java.math.BigInteger;
import java.util.Scanner;

public class Main {
    public static void main (String [] args){
        Scanner in=new Scanner(System.in);
        int n=in.nextInt();
        if(n==0){
            System.out.println(0);
        }else{

            BigInteger a[]=new BigInteger[n+2];
            a[0]=BigInteger.valueOf(1);
            a[1]=BigInteger.valueOf(2);
            for(int i=2;i<n;i++){
                a[i]=a[i-1].add(a[i-2]);
            }
            System.out.println(a[n-1]);
        }
    }
}
