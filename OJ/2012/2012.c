#include<stdio.h>
int main ()
{
    double m;
    int n;
    int i = 0;
    double sum = 0, high = 0;
    scanf("%lf %d", &m, &n);
    for(i = 0; i < n; i++)
    {
        sum += m;
        if(i != 0)
        {
            sum += m;
        }
        m /= 2;

    }
    high = m;
    printf("%.2f %.2f\n", high, sum);
    return 0;
}
