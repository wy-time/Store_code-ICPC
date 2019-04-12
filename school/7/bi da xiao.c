#include <stdio.h>
void fun(float a, float b);
int main()
{
    float a,b;
    scanf("%f%f", &a, &b);
    fun(a,b);
    return 0;
}
void fun(float a, float b)
{
    float t;
    if (a > b)
    {
        t = a;
        a = b;
        b = t;
    }
    printf("%5.2f,%5.2f\n", a, b);
}
