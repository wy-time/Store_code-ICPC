#include<bits/stdc++.h>
using namespace std;

#define Abigail inline void
typedef long long LL;

const int N=500000,C=20;

int n,m,sk;
struct cont{
  LL cnt;
  int id;
}a[N+9];

bool cmp1(const cont &a,const cont &b){return a.cnt<b.cnt||a.cnt==b.cnt&&a.id<b.id;}

struct question{
  LL k;
  int id;
}q[N+9];
int ans[N+9];

bool cmp2(const question &a,const question &b){return a.k<b.k;}

int c[N+9];

void Add(int p,int v){for (;p<=m;p+=p&-p) c[p]+=v;}

int Query_kth(int p){
  int res=0;
  for (int i=C-1;i>=0;--i)
    if (res+(1<<i)<=m&&p>c[res+(1<<i)]) p-=c[res+=1<<i];
  return res+1;
} 

Abigail into(){
  scanf("%d%d%d",&n,&m,&sk);
  int x;
  for (int i=1;i<=n;++i){
  	scanf("%d",&x);
  	++a[x].cnt;
  }
  for (int i=1;i<=sk;++i){
  	scanf("%lld",&q[i].k);
  	q[i].id=i;q[i].k-=(LL)n;
  }
}

Abigail work(){
  for (int i=1;i<=m;++i) a[i].id=i;
  sort(a+1,a+m+1,cmp1);
  sort(q+1,q+sk+1,cmp2);
  int j=1;
  LL now=0;
  for (int i=1;i<m;++i){
    Add(a[i].id,1);
  	for (;j<=sk&&q[j].k<=now+(a[i+1].cnt-a[i].cnt)*i;++j){
  	  int t=(q[j].k-now)%i;
  	  ans[q[j].id]=Query_kth(t==0?i:t);
  	}
  	now+=(a[i+1].cnt-a[i].cnt)*i;
  }
  Add(a[m].id,1);
  for (;j<=sk;++j){
  	int t=(q[j].k-now)%m;
  	ans[q[j].id]=Query_kth(t==0?m:t);
  }
}

Abigail outo(){
  for (int i=1;i<=sk;++i)
    printf("%d\n",ans[i]);
}

int main(){
  into();
  work();
  outo();
  return 0;
}
