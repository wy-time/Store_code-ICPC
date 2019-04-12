#include<stdio.h>
#include<math.h>
void a1(double a,double b,double delat,double *x1, double* x2);
void a2(double a,double b,double delat,double *x1, double* x2);
void a3(double a,double delat,double *x1, double* x2);
int main()
{
    double a,b,c;
    double x=0,y=0;
    double *x1=&x,*x2=&y;
    int safe=1;
    scanf("%lf %lf %lf",&a,&b,&c);
    double delat=(b*b)-(4*a*c);
    if(delat>0){
        a1(a,b,delat,x1,x2);
    }else if(delat==0)
    {
        a2(a,b,delat,x1,x2);
    }else
    {
        a3(a,delat,x1,x2);
        safe=0;
    }
    if(safe){
        printf("x1=%.3f x2=%.3f\n",*x1,*x2);
    }else
    {
        printf("x1=%.3f%+.3fi x2=%.3f%+.3fi\n",(-b)/(2*a),*x1,(-b)/(2*a),*x2);
    }
    return 0;
}
void a1(double a,double b,double delat,double *x1, double* x2)
{
    *x1=(-b+sqrt(delat))/(2*a);
    *x2=(-b-sqrt(delat))/(2*a);
}
void a2(double a,double b,double delat,double *x1, double* x2)
{
    *x1=*x2=(-b)/(2*a);
}
void a3(double a,double delat,double *x1, double* x2)
{
    *x1=sqrt(-delat)/(2*a);
    *x2=-sqrt(-delat)/(2*a);
}
