import java.math.BigInteger;
import java.util.Scanner;

//import java.math.BigInteger;
//import java.util.Scanner;
//
//class Main {
//    public static void main (String args []){
//        BigInteger ans[][]=new BigInteger[1005][3];
//        ans[1][0]=BigInteger.valueOf(0);
//        ans[1][1]=BigInteger.valueOf(1);
//        ans[1][2]=BigInteger.valueOf(1);
//        int i;
//        for (i=2;i<=1002;i++){
//            ans[i][0]=ans[i-1][2];
//            ans[i][2]=ans[i-1][0].add(ans[i-1][1]);
//            ans[i][1]=BigInteger.valueOf(2).pow(i-1);
//        }
//        Scanner in = new Scanner(System.in);
//        while(in.hasNextInt()){
//            int n=in.nextInt();
//            System.out.println(ans[n][0]);
//        }
//    }
//}
class Main{
    public static void main(String []args){
        BigInteger n[]=new BigInteger[10005];
        int i;
        n[0]=BigInteger.valueOf(1);
        for(i=1;i<10005;i++){
            n[i]=n[i-1].multiply(BigInteger.valueOf(i));
        }
        Scanner in=new Scanner(System.in);
        while(in.hasNextInt()){
            int t=in.nextInt();
            System.out.println(n[t]);
        }
    }
}