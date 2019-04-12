/*#include <iostream>
#include<cmath>
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    int t,n;
    int i;
    long long fib[2]={1,1};
    long long fibsum[50]={0,1};
    long long sum=1;
    int cnt=2;
    while(cnt<50)
    {
        sum+=fib[1];
        fibsum[cnt]=sum;
        cnt++;
        int t=fib[0];
        fib[0]=fib[1];
        fib[1]=fib[1]+t;
    }
    cin>>t;
    while(t--)
    {
        cin>>n;
        int i;
        for(i=0;i<50;i++)
        {
            if(n<=fibsum[i])
                break;
        }
        long long temp=(int)pow(2.0,i-1);
        n-=fibsum[i-1];
        long long r=temp;
        while(n>0)
        {
            r++;

        }
    }
    return 0;
}*/
#include <cstdio>
#include <iostream>
#include<algorithm>
using namespace std;
long long int x,y,z,sum;
long long int a[108]= {1,2,3UL,5UL,8UL,13UL,21UL,34UL,55UL,89UL,144UL,233UL,377UL,610UL,987UL,1597UL,2584UL,4181UL,6765UL,10946UL,17711UL,28657UL,46368UL,75025UL,121393UL,196418UL,317811UL,514229UL,832040UL,1346269UL,2178309UL,3524578UL,5702887UL,9227465UL,14930352UL,24157817UL,39088169UL,63245986UL,102334155UL,165580141UL,267914296UL,433494437UL,701408733UL,1134903170UL,1836311903UL,2971215073UL,4807526976UL,7778742049UL,12586269025UL,20365011074UL,32951280099UL,53316291173UL,86267571272UL,139583862445UL,225851433717UL,365435296162UL,591286729879UL,956722026041UL,1548008755920UL,2504730781961UL,4052739537881UL,6557470319842UL,10610209857722UL};
long long int b[154]= {1,2UL,4UL,8UL,16UL,32UL,64UL,128UL,256UL,512UL,1024UL,2048UL,4096UL,8192UL,16384UL,32768UL,65536UL,131072UL,262144UL,524288UL,1048576UL,2097152UL,4194304UL,8388608UL,16777216UL,33554432UL,67108864UL,134217728UL,268435456UL,536870912UL,1073741824UL,2147483648UL,4294967296UL,8589934592UL,17179869184UL,34359738368UL,68719476736UL,137438953472UL,274877906944UL,549755813888UL,1099511627776UL,2199023255552UL,4398046511104UL,8796093022208UL,17592186044416UL,35184372088832UL,70368744177664UL,140737488355328UL,281474976710656UL,562949953421312UL,1125899906842624UL,2251799813685248UL,4503599627370496UL,9007199254740992UL,18014398509481984UL,36028797018963968UL,72057594037927936UL,144115188075855872UL,288230376151711744UL,576460752303423488UL};
int main()
{
    scanf("%lld",&x);
    while(x--)
    {
        sum=0;
        scanf("%lld",&y);
        while(y)
        {
            for(int i=1; i<60; i++)
            {
                if(y-a[i]<0)
                {
                    y-=a[i-1];
                    sum+=b[i-1];
                    break;
                }
            }
        }
        printf("%lld\n",sum);
    }
    return 0;
}
