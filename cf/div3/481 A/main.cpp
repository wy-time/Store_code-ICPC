#include <iostream>
#include<stack>
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    int n;
    cin>>n;
    int use[1005]={0};
    stack <int> st,st2;
    int i;
    for(i=0;i<n;i++)
    {
        int t;
        cin>>t;
        st.push(t);
    }
    while(!st.empty())
    {
        int t=st.top();
        st.pop();
        if(!use[t])
        {
            st2.push(t);
            use[t]=1;
        }
    }
    cout<<st2.size()<<endl;
    while(st2.size()>1)
    {
        cout<<st2.top()<<" ";
        st2.pop();
    }
    cout<<st2.top()<<endl;
    st2.pop();
    return 0;
}
