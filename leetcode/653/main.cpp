#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
// void read(int &x) {
//  char ch = getchar(); x = 0;
//  for (; ch < '0' || ch > '9'; ch = getchar());
//  for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
// }
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

bool findTarget(TreeNode* root, int k);
int main()
{
    std::ios::sync_with_stdio(false);
    #ifdef test
    freopen("F:\Desktop\question\in.txt","r",stdin);
    #endif
    #ifdef ubuntu
    freopen("./in","r",stdin);
    freopen("./out","w",stdout);
    #endif
    // int n;
    // vector<string> words;
    // cin>>n;
    // string word;
    // for(int i = 0; i<n;i++)
    // {
    //     cin>>word;
    //     words.push_back(word);
    // }
    string s;
    cin>>s;
    // cout<<findTarget(s)<<endl;
    return 0;
}
bool find(TreeNode* root, int k) {
    if(root == nullptr) {return false;}
    if (root->val == k) {
        return true;
    } else {
        if (k > root->val) {
            return find(root->right,k);
        } else {
            return find(root->left,k);
        }
    }
}
bool dfs(TreeNode* trueRoot, TreeNode* root, int k) {
    if(root == nullptr) {return false;}
    int x = root->val;
    int offset = k - x;
    if (offset != x && find(trueRoot,offset)){
        return true;
    }
    if (dfs(trueRoot,root->left,k)){
        return true;
    } 
    if (dfs(trueRoot,root->right,k)) {
        return true;
    }
    return false;
}
bool findTarget(TreeNode* root, int k) {
    return dfs(root,root,k);
}