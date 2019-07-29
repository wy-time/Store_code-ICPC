#include<cstdio>
#include <iostream> 
#include<cstring>
#include<algorithm>
using namespace std;
 
const int maxn = 400000+10;

const int MAX = 2e5+100;
const int ALP = 26;
struct Palindromic_Tree {
    int son[MAX][ALP]; //???
    int fail[MAX]; //fail ??
    int cnt[MAX]; //????????????????????
    int num[MAX]; //???? fail ????????
    int len[MAX]; //?????????????
    int S[MAX]; //??????
    int last; //????????????? SAM
    int n; //????????
    int p; //????????
    int newnode(int l) {
        memset(son[p], 0, sizeof(son[p]));
        cnt[p] = 0;
        num[p] = 0;
        len[p] = l;
        return p++;
    }
 
    void init() {
        p = 0;
        newnode(0);
        newnode(-1);
        last = 0;
        n = 0;
        S[n] = -1;
        fail[0] = 1;
    }
 
    int get_fail(int x) {
        while (S[n - len[x] - 1] != S[n]) x = fail[x];
        return x;
    }
 
    void add(int c) {
        c -= 'a';
        S[++n] = c;
        int cur = get_fail(last); //?????????????
        if (!son[cur][c]) { //????????????????
            int now = newnode(len[cur] + 2);
            fail[now] = son[get_fail(fail[cur])][c]; //??????? fail ?????? fail
            son[cur][c] = now;
            num[now] = num[fail[now]] + 1; //?? fail ????
        }
        last = son[cur][c];
        cnt[last]++; //???????????
    }
    void count() {
        //??????????????? fail ?????????????????????
        for (int i = p - 1; i >= 0; i--) cnt[fail[i]] += cnt[i];
    }
} AUT;
char str[maxn];
int wa[maxn],wb[maxn],wv[maxn];
int c[maxn];
int cmp(int *r,int a,int b,int l)
{
    return r[a]==r[b] && r[a+l]==r[b+l];
}
 
void cal_the_houzhui(char *r,int *sa,int n,int m)
{
    int i,j,p;
    int *x=wa,*y=wb;
 
    for(i=0;i<m;i++)
        c[i]=0;
 
    for(i=0;i<n;i++)
        c[x[i]=r[i]]++;
    for(i=1;i<m;i++)
        c[i]+=c[i-1];
    for(i=n-1;i>=0;i--)
        sa[--c[x[i]]]=i;
 
    p=1;
    for(j=1;p<n;j*=2,m=p)
    {
        for(p=0,i=n-j;i<n;i++)
            y[p++]=i;
        for(i=0;i<n;i++)
            if(sa[i]>=j)
                y[p++]=sa[i]-j;
        for(i=0;i<n;i++)
            wv[i]=x[y[i]];
 
        for(i=0;i<m;i++)
            c[i]=0;
        for(i=0;i<n;i++)
            c[wv[i]]++;
        for(i=1;i<m;i++)
            c[i]+=c[i-1];
        for(i=n-1;i>=0;i--)
            sa[--c[wv[i]]] = y[i];
        swap(x,y);
        p=1;
        x[sa[0]] = 0;
        for(i=1;i<n;i++)
            x[sa[i]] = cmp(y,sa[i-1],sa[i],j)?p-1:p++;
    }
 
}
 
int _rank[maxn],height[maxn];
void cal_the_height(char *r,int *sa,int n)
{
    int i,j,k=0;
    for(i=0;i<n;i++)
        _rank[sa[i]]=i;
    for(i=0;i<n;height[_rank[i++]]=k)
    {
        for(k?k--:0,j=sa[_rank[i]-1];r[i+k]==r[j+k];)
            k++;
    }
}
 
int n;
int _sa[maxn];
 
long long solve()
{
    cal_the_houzhui(str,_sa,n+1,256);
    cal_the_height(str,_sa,n+1);
    long long ans=0;
    for(int i=1;i<=n;i++)
    {
        ans+=n-_sa[i]-height[i];
    }
    return ans;
}
int main()
{
#ifdef test
    freopen("F:\\Desktop\\question\\in.txt", "r", stdin);
#endif
#ifdef ubuntu
	freopen("/home/time/debug/debug/in", "r", stdin);
	freopen("/home/time/debug/debug/out", "w", stdout);
#endif
    scanf("%s",str);
    n=strlen(str);
    AUT.init();
    for(int i=0;i<n;i++)
    {
        AUT.add(str[i]);
    }
    long long ans2=AUT.p-2;
    int len=strlen(str);
    n=len;
    str[n]='$';
    int pos=n+1;
    int i;
    for(i=n-1;i>=0;i--)
    {
        str[pos]=str[i];
        pos++;
    }
    str[pos]='\0';
    n=strlen(str);
    long long ans=solve();
    ans-=1ll*(len+1)*(len+1);
    printf("%lld\n",(ans+ans2)/2);
    return 0;
}
