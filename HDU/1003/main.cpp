#include <iostream>
using namespace std;
int dig[100005];
int main()
{
    std::ios::sync_with_stdio(false);
    int t;
    cin>>t;
    int cnt=0;
    while(t--)
    {
        cnt++;
        int n;
        cin>>n;
        int i;
        int flag=0;
        for(i=0;i<n;i++)
        {
            cin>>dig[i];
            if(dig[i]>0)
                flag=1;
        }
        if(flag)
        {
            int beg=1;
            int endx=1;
            long long sum=-2000;
            long long dp=0;
            int dpbeg=1;
            for(i=0;i<n;i++)
            {

                if(dp+dig[i]<0)
                {
                    if(sum<dp)
                    {
                        sum=dp;
                        beg=dpbeg;
                        endx=i;
                    }
                    dp=0;
                    dpbeg=i+2;
                }else
                {
                    dp+=dig[i];
                    if(sum<dp)
                    {
                        sum=dp;
                        beg=dpbeg;
                        endx=i+1;
                    }
                }
            }
            cout<<"Case "<<cnt<<":\n"<<sum<<" "<<beg<<" "<<endx<<endl;
            if(t!=0)
                cout<<endl;
        }else
        {
            long long sum=dig[0];
            int beg=1;
            int endx;
            for(i=1;i<n;i++)
            {
                if(sum<dig[i])
                {
                    sum=dig[i];
                    beg=i+1;
                }
            }
            endx=beg;
            cout<<"Case "<<cnt<<":\n"<<sum<<" "<<beg<<" "<<endx<<endl;
            if(t!=0)
                cout<<endl;
        }
    }
    return 0;
}
/*#include<stdio.h>
int main(){
    int t, n, caseNum, maxSum, maxHere, beginMax, endMax, beginHere, endHere;
    int a[100002];
    scanf("%d", &t);
    caseNum = 0;
    while(t--){
        caseNum++;
        scanf("%d", &n);
        for(int i=0; i<n; i++){
            scanf("%d", &a[i]);
        }
        maxSum = -2147483647-1;
        maxHere = 0;
        beginMax = 0;
        endMax = 0;
        beginHere = 0;
        endHere = -1;
        for(int i=0; i<n; i++){
            if(maxHere<0){
                maxHere=a[i];
                beginHere = i;
                endHere = i;
            } else {
                maxHere+=a[i];
                endHere++;
            }
            if(maxHere>maxSum){
                maxSum = maxHere;
                beginMax = beginHere;
                endMax = endHere;
            }
        }
        printf("Case %d:\n", caseNum);
        printf("%d %d %d\n", maxSum, beginMax+1, endMax+1);
        if(t){
            printf("\n");
        }
    }
}*/
