#include<cstdio>
#include <iostream>
int a[131072]= {0}; //������������
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    int i=0;
    a[0]=1;
    int res=0;
    int t=0;//��λ��
    int j=0,cnt=1;//cnt�������ж���Щλ�ó�
    for(i=2; i<=n; i++)
    {
        t=0;
        for(j=0; j<cnt; j++)
        {
            res=a[j]*i+t;
            t=res/10;
            a[j]=res%10;
        }
        while(t)
        {
            cnt++;
            a[cnt-1]+=t%10;
            t/=10;
        }
    }
    for(i=cnt-1; i>=0; i--)
    {
        printf("%d",a[i]);
    }
    return 0;
}
/*
#include <iostream>
using namespace std;
int str[1000000];        //������ĿҪ����������Ĵ�С
int main()
{
    int n,i,j;
    int flag=1;
    int carry=0;        //���ý�λ
    int res=0;
    str[0]=1;
    cin>>n;
    for (i=2; i<=n; i++) //��2��ʼ����׳�
    {
        for (j=1; j<=flag; j++)   //���ݽ�λflag��С���жϵ�ǰ�׳˽���ĵ�λ��
        {
            res=str[j-1]*i+carry;
            str[j-1]=res%10;
            carry=res/10;
        }
        while (carry)  //����λ����һʱ�������չ����һλ
        {
            flag++;
            str[flag-1]=carry%10;
            carry/=10;
        }
    }
    for (i=flag-1; i>=0; i--)  //��������鵹�������ע�����һλ��"i=flag-1",��Ϊ"flag=1" ��Ӧstr[0],�Դ�����
    {
        cout<<str[i];
    }
    return 0;
}*/

