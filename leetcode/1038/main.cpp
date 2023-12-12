#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <unordered_map>
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
int dfs(TreeNode* root, int right) {
    int maxNum = root->val;
    if(root->right != nullptr) {
        int res = dfs(root->right,right);
        maxNum = max(maxNum,res);
        root->val += maxNum;
    }
    root->val += right;
    if(root->left != nullptr) {
        int res = dfs(root->left,root->val);
        maxNum = max(maxNum,res);
    }
    return max(maxNum,root->val);
}
class Solution {
public:
    TreeNode* bstToGst(TreeNode* root) {
        dfs(root,0);
        return root;
    }
};
TreeNode* bstToGst(TreeNode* root) {
        dfs(root,0);
        return root;
}
void build(TreeNode * root, int i, vector<int> &edge) {
    root->val = edge[i];
    if(i*2+1<edge.size() && edge[i*2+1] != -1) {
        root->left = new TreeNode();
        build(root->left,i*2+1,edge);
    }

    if(i*2+2<edge.size() && edge[i*2+2] != -1) {
        root->right = new TreeNode();
        build(root->right,i*2+2,edge);
    }
}
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
    // int n,m;
    // cin>>n>>m;
    // int i,j;
    // vector<vector<int>>grid;
    // wfor(i,0,n) {
    //     vector<int>temp;
    //     wfor(j,0,m) {
    //         int val;
    //         cin>>val;
    //         temp.push_back(val);
    //     }
    //     grid.push_back(temp);
    // }

    // vector<vector<int>>cost;
    // wfor(i,0,n * m) {
    //     vector<int>temp;
    //     wfor(j,0,m) {
    //         int val;
    //         cin>>val;
    //         temp.push_back(val);
    //     }
    //     cost.push_back(temp);
    // }
    vector<int> edge = vector<int> {4,1,6,0,2,5,7,-1,-1,-1,3,-1,-1,-1,8};
    TreeNode * root = new TreeNode(edge[0]);
    build(root,0,edge);
    bstToGst(root);
    return 0;
}
