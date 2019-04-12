#include <iostream>
#include<map>
using namespace std;
typedef struct
{
    char left;
    char right;
} TREE;
typedef map<char,TREE>MAP;
MAP ma;
void slove(char root);
int main()
{
    std::ios::sync_with_stdio(false);
    TREE tree[30];
    int n;
    cin>>n;
    char root;
    int cnt=1;
    cin>>root>>tree[0].left>>tree[0].right;
    ma.insert(make_pair(root,tree[0]));
    while(--n)
    {
        char temp;
        cin>>temp>>tree[cnt].left>>tree[cnt].right;
        ma.insert(make_pair(temp,tree[cnt++]));
    }
    slove(root);
    return 0;
}
void slove(char root)
{
    if(root!='*')
    {
        cout<<root;
        slove(ma[root].left);
        slove(ma[root].right);
    }
}
