import java.util.Scanner;

public class Main {
    public  static void main (String args[]){
        Scanner scan=new Scanner(System.in);
        int n=scan.nextInt();
        int a[]=new int[n];
        boolean use[]=new boolean[n];
        int i=0;
        for(i=0;i<n;i++){
            use[i]=true;
        }
        int cnt=0;
        for(i=0;i<n;i++)
            a[i]=scan.nextInt();
        int j=0;
        for(i=0;i<n;i++){
            for(j=i+1;j<n;j++){
                int t=a[i]+a[j];
                for(int k=0;k<n;k++){
                    if(t==a[k]&&k!=i&&k!=j&&use[k]){
                        use[k]=false;
                        cnt++;
                    }
                }
            }
        }
        System.out.println(cnt);
    }
}
