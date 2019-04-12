import java.util.Scanner;

 public class shiyan {
    public static void main (String args[]){
        Scanner scan=new Scanner(System.in);
        int n=scan.nextInt();
        int t=3;
        int res=0x7f7f7f;
        int cost;
        while(t >0) {
            t--;
            int a = scan.nextInt();
            int b = scan.nextInt();
            if (n > a) {
                if (n % a != 0) {
                    cost = (n / a + 1) * b;
                } else
                    cost = n / a * b;
            } else
                cost = b;
            res = cost > res ? res : cost;
        }
        System.out.println(res);
    }
}
