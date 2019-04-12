// #include<bits/stdc++.h>
// using namespace std;
// typedef long long ll;
// const int MaxN = 2e5 + 100;
// const int MAXN = MaxN;
// int cntA[MaxN], cntB[MaxN], tsa[MAXN], A[MAXN], B[MAXN];
// int sa[MAXN], Rank[MAXN], h[MAXN];
// char ch[MAXN];
// struct Node {
//     int val, index;
//     Node(int val_, int index_): val(val_), index(index_) {
//     }
//     bool operator < (const Node b)const {
//         if (val == b.val) {
//             return b.index < index;
//         }
//         return b.val < val;
//     }
// };
// priority_queue<Node>pq;
// void GetSa(char *ch, int *sa, int *rank, int n) {

//     for (int i = 0; i < MaxN; i++)  cntA[i] = 0;
//     for (int i = 1; i <= n; i++)   cntA[(int)ch[i]]++;
//     for (int i = 1; i <= MaxN; i++) cntA[i] += cntA[i - 1];
//     for (int i = n; i; i--)  sa[cntA[()ch[i]]--] = i;
//     rank[sa[1]] = 1;
//     for (int i = 2; i <= n; i++) {
//         rank[sa[i]] = rank[sa[i - 1]];
//         if (ch[sa[i]] != ch[sa[i - 1]])  rank[sa[i]]++;
//     }
//     for (int l = 1; rank[sa[n]] < n; l <<= 1) {
//         for (int i = 0; i < MaxN; i++)  cntA[i] = 0;
//         for (int i = 0; i < MaxN; i++)  cntB[i] = 0;
//         for (int i = 1; i <= n; i++) {
//             cntA[A[i] = rank[i]]++;
//             cntB[B[i] = (i + l <= n) ? rank[i + l] : 0]++;
//         }
//         for (int i = 1; i < MaxN; i++)   cntB[i] += cntB[i - 1];
//         for (int i = n; i; i--)  tsa[cntB[B[i]]--] = i;
//         for (int i = 1; i < MaxN; i++)  cntA[i] += cntA[i - 1];
//         for (int i = n; i; i--)  sa[cntA[A[tsa[i]]]--] = tsa[i];
//         rank[sa[1]] = 1;
//         for (int i = 2; i <= n; i++) {
//             rank[sa[i]] = rank[sa[i - 1]];
//             if (A[sa[i]] != A[sa[i - 1]] || B[sa[i]] != B[sa[i - 1]])    rank[sa[i]]++;
//         }
//     }
// }

// void GetHeight(char *ch, int *sa, int *rank, int *height, int n) {

//     GetSa(ch, sa, rank, n);
//     for (int i = 1, j = 0; i <= n; i++) {
//         if (j)   j--;
//         while (ch[i + j] == ch[sa[rank[i] - 1] + j]) j++;
//         height[rank[i]] = j;
//     }
// }
// int GetK(int k, int n) {
//     int ans = 0;
//     k--;
//     if (k == 0) {
//         for (int i = 1; i <= n; ++i)   ans = ans + (n - sa[i] + 1 - h[i]);
//         return ans;
//     }
//     while (!pq.empty())pq.pop();
//     for (int i = 2; i <= n; i++) {
//         while (!pq.empty() && pq.top().index < i - k + 1)pq.pop();
//         pq.push(Node(h[i], i));
//         if (i > k) {
//             int top = pq.top().val;
//             int last = h[i - k];
//             ans += max(0, top - last);
//         }
//     }
//     return ans;
// }

// int main() {
//     int n;
//     int a, b;
//     while (~scanf("%s", ch + 1))
//     {
//         scanf("%d %d", &a, &b);
//         n = strlen(ch + 1);
//         GetHeight(ch, sa, Rank, h, n);
//         printf("%d\n", GetK(a, n) - GetK(b + 1, n));
//     }
//     return 0;
// }
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 200010;
char s[N];
struct SAM {
    int p, q, np, nq, cnt, lst, a[N][26], l[N], f[N], tot;
    int Tr(char c) {return c - 'a';}
    // int val(int c) {return l[c] - l[f[c]];}
    SAM() {cnt = 0; lst = ++cnt;}
    void Initialize() {
        memset(l, 0, sizeof(int) * (cnt + 1));
        memset(f, 0, sizeof(int) * (cnt + 1));
        for (int i = 0; i <= cnt; i++)for (int j = 0; j < 26; j++)a[i][j] = 0;
        cnt = 0; lst = ++cnt;
    }
    void extend(int c) {
        p = lst; np = lst = ++cnt; l[np] = l[p] + 1;
        while (!a[p][c] && p)a[p][c] = np, p = f[p];
        if (!p) {f[np] = 1;}
        else {
            q = a[p][c];
            if (l[p] + 1 == l[q])f[np] = q;
            else {
                nq = ++cnt; l[nq] = l[p] + 1;
                memcpy(a[nq], a[q], sizeof(a[q]));
                f[nq] = f[q]; f[np] = f[q] = nq;
                while (a[p][c] == q)a[p][c] = nq, p = f[p];
            }
        }
    }
    int b[N], x[N], r[N];
    void build() {
        int len = strlen(s + 1);
        for (int i = 1; i <= len; i++)extend(Tr(s[i]));
        memset(r, 0, sizeof(int) * (cnt + 1));
        memset(b, 0, sizeof(int) * (cnt + 1));
        for (int i = 1; i <= cnt; i++)b[l[i]]++;
        for (int i = 1; i <= len; i++)b[i] += b[i - 1];
        for (int i = 1; i <= cnt; i++)x[b[l[i]]--] = i;
        for (int i = p = 1; i <= len; i++) {p = a[p][Tr(s[i])]; r[p]++;}
        for (int i = cnt; i; i--)r[f[x[i]]] += r[x[i]];
    }
    void solve(int a, int b) {
        int ans = 0;
        build();
        for (int i = cnt; i > 0; i--)
        {
            int p = x[i];
            int fp = f[p];
            r[fp] += r[p];
            if (r[p] >= a && r[p] <= b)ans += l[p] - l[fp];
        }
        printf("%d\n", ans);
    }
} sam;
// int T;
int main() {
    while (~scanf("%s", s + 1))
    {
        int a, b;
        scanf("%d %d", &a, &b);
        sam.Initialize();
        sam.solve(a, b);
    }
    return 0;
}