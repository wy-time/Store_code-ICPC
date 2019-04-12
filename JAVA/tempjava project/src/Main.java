import java.math.BigDecimal;

public class Main {
    public static void main (String args []){
        int i;
        int n=2019;
        BigDecimal sum=BigDecimal.valueOf(n);
        BigDecimal temp=BigDecimal.valueOf(1);
        for(i=1;i<2019;i++){
            temp=temp.multiply(BigDecimal.valueOf(n-i));
            sum=sum.add(temp.multiply(BigDecimal.valueOf(n-i)));
        }
        temp=temp.multiply(BigDecimal.valueOf(n));
        BigDecimal ans=sum.divide(temp,5);
        System.out.println(ans);
        System.out.println(temp);
        System.out.println(sum);
    }
}
