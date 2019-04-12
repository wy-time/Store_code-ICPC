#include <iostream>
#include<queue>
#include<vector>
using namespace std;
struct st
{
    int id;
    int start;
    int start1;
    int end1;
    int need;
    bool operator < (const st &a)const
    {
        if(a.start1!=this->start1)
            return a.start1<this->start1;
        else if(a.end1-a.start-a.need!=this->end1-this->start-this->need)
            return a.end1-a.start-a.need<this->end1-this->start-this->need;
        else
            return a.end1<this->end1;
    }
    /*bool operator > (const st &a)
    {
        if(a.start!=this->start)
            return a.start>this->start;
        else
            return a.end1-a.start-a.need>this->end1-this->start-this->need;
    }*/
};
priority_queue<st>qu;
vector <int> res;
int vis[105];
int main()
{
    st exam;
    std::ios::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    int i;
    for(i=0;i<m;i++)
    {
        exam.id=i+1;
        cin>>exam.start>>exam.end1>>exam.need;
        exam.start1=exam.start;
        qu.push(exam);
    }
    i=1;
    while(!qu.empty())
    {
        exam=qu.top();
        qu.pop();
        /*while(exam.need==0&&exam.end1!=i)
        {
            st temp=exam;
            exam=qu.top();
            qu.pop();
            qu.push(temp);
        }*/
        if(exam.end1==i)
        {
            if(exam.need<=0)
                res.push_back(m+1);
            else
            {
                cout<<-1;
                return 0;
            }
        }else
        {
            if(exam.start<=i)
            {
                exam.start=i;
                if(exam.need>0)
                {
                    res.push_back(exam.id);
                    exam.need--;
                    if(exam.need>0)
                        qu.push(exam);
                    else
                    {
                        if(exam.end1>=i)
                        {
                            vis[exam.end1-1]=m+1;
                        }else
                        {
                            cout<<-1;
                            return 0;
                        }
                    }
                }
            }else
            {
                res.push_back(0);
                qu.push(exam);
            }
        }
        i++;
    }
    vector <int> out;
    vector <int>::iterator it;
    int cnt2=0;
    for(i=0;cnt2<n;i++)
    {
        if(res.size()>i)
        {
            if(vis[i]!=0&&res[i]==0)
            {
                out.push_back(vis[i]);
                cnt2++;
            }else if(vis[i]==0&&res[i]!=0)
            {
                out.push_back(res[i]);
                cnt2++;
            }else if(vis[i]==0&&res[i]==0)
            {
                out.push_back(res[i]);
                cnt2++;
            }else if(vis[i]!=0&&res[i]!=0)
            {
                out.push_back(vis[i]);
                vis[i]=0;
                cnt2++;
                it=res.begin()+i;
                res.insert(it,0);
            }
        }else
        {
            out.push_back(vis[i]);
            cnt2++;
        }
    }
    if(res.size()>n)
    {
        cout<<-1;
        return 0;
    }
    for(i=0;i<n-1;i++)
    {
        cout<<out[i]<<" ";
    }
    cout<<out[i];
    return 0;
}
