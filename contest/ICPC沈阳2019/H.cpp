#include <iostream>
#include <cctype>
#include <algorithm>
#include <string>
#include <cstdio>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
// void read(int &x) {
//  char ch = getchar(); x = 0;
//  for (; ch < '0' || ch > '9'; ch = getchar());
//  for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
// }
struct _nomi
{
    int sum;
    void init()
    {
        sum = 0;
    }
};
struct _Pair
{
    int two;
    int rest;
    int flag;
    void init()
    {
        two = 0;
        rest = 0;
        flag = 0;
    }
    void check(int num[], int sum)
    {
        sort(num, num + 5);
        int i;
        int last = num[0];
        int tflag = 0;
        wfor(i, 1, 5)
        {
            if (last == num[i])
            {
                tflag = 1;
                break;
            }
            last = num[i];
        }
        if (tflag == 1)
        {
            this->flag = 1;
            this->two = last;
            this->rest = sum - last * 2;
        }
    }
};
struct __2Pair
{
    int h_two;
    int l_two2;
    int flag;
    int rest;
    void init()
    {
        h_two = 0;
        l_two2 = 0;
        flag = 0;
        rest = 0;
    }
    void check(int num[], int sum)
    {
        int temp[2];
        sort(num, num + 5);
        int i;
        int tflag = 0;
        int last = num[0];
        wfor(i, 1, 5)
        {
            if (num[i] == last)
            {
                temp[tflag++] = num[i];
                i++;
                if (tflag == 2)
                    break;
            }
            last = num[i];
        }
        if (tflag == 2)
        {
            this->flag = 1;
            this->h_two = max(temp[0], temp[1]);
            this->l_two2 = min(temp[0], temp[1]);
            this->rest = sum - temp[0] * 2 - temp[1] * 2;
        }
    }
};
struct __3tiao
{
    int flag;
    int three;
    int rest;
    void init()
    {
        flag = 0;
        three = 0;
        rest = 0;
    }
    void check(int num[], int sum)
    {
        int vis[14] = {0};
        int i;
        int tflag = 0;
        int temp = 0;
        wfor(i, 0, 5)
        {
            vis[num[i]]++;
            if (vis[num[i]] == 3)
            {
                temp = num[i];
                tflag = 1;
                break;
            }
        }
        if (tflag == 1)
        {
            this->flag = 1;
            this->three = temp;
            this->rest = sum - temp * 3;
        }
    }
};
struct _hulu
{
    int flag;
    int three;
    int two;
    void init()
    {
        flag = 0;
        three = 0;
        two = 0;
    }
    void check(int num[])
    {
        int vis[14] = {0};
        int vis2[14] = {0};
        int i;
        wfor(i, 0, 5)
        {
            vis[num[i]]++;
            vis2[num[i]]++;
        }
        sort(vis2, vis2 + 14, greater<int>());

        if (vis2[0] == 3 && vis2[1] == 2)
        {
            this->flag = 1;
            wfor(i, 1, 14)
            {
                if (vis[i] == 3)
                    this->three = i;
                else if (vis[i] == 2)
                    this->two = i;
            }
        }
    }
};
struct __4tiao
{
    int flag;
    int four;
    int rest;
    void init()
    {
        flag = 0;
        four = 0;
        rest = 0;
    }
    void check(int num[], int sum)
    {
        int vis[14] = {0};
        int i;
        wfor(i, 0, 5)
        {
            vis[num[i]]++;
            if (vis[num[i]] == 4)
            {
                this->four = num[i];
                this->flag = 1;
                this->rest = sum - num[i] * 4;
                break;
            }
        }
    }
};
struct _shunzi
{
    int hig;
    int flag;
    void init()
    {
        hig = 0;
        flag = 0;
    }
    void check(int num[])
    {
        sort(num, num + 5);
        int last = num[0];
        int tflag = 1;
        int i;
        wfor(i, 1, 5)
        {
            if (num[i] - last != 1)
            {
                tflag = 0;
                break;
            }
            last = num[i];
        }
        if (tflag == 1)
        {
            this->flag = 1;
            this->hig = num[4];
        }
    }
};
struct _niubi
{
    int flag;
    void init()
    {
        flag = 0;
    }
    void check(int num[])
    {
        sort(num, num + 5);
        if (num[0] == 1 && num[1] == 10 && num[2] == 11 && num[3] == 12 && num[4] == 13)
            this->flag = 1;
    }
};
bool com_name(const string name, const string name2)
{
    return name < name2;
}
struct st
{
    string name;
    _nomi nomi;
    _Pair Pair;
    __2Pair _2Pair;
    __3tiao _3tiao;
    _hulu hulu;
    __4tiao _4tiao;
    _shunzi shunzi;
    _niubi niubi;
    void init()
    {
        nomi.init();
        Pair.init();
        _2Pair.init();
        _3tiao.init();
        hulu.init();
        _4tiao.init();
        shunzi.init();
        niubi.init();
    }
    bool operator < (const st&A)const
    {
        if (niubi.flag != A.niubi.flag)
            return niubi.flag > A.niubi.flag;
        else if (niubi.flag != 0)
        {
            return com_name(name, A.name);
        } else if (shunzi.flag != A.shunzi.flag)
            return shunzi.flag > A.shunzi.flag;
        else if (shunzi.flag != 0)
        {
            if (shunzi.hig != A.shunzi.hig)
                return shunzi.hig > A.shunzi.hig;
            else
                return com_name(name, A.name);
        } else if (_4tiao.flag != A._4tiao.flag)
            return _4tiao.flag > A._4tiao.flag;
        else if (_4tiao.flag != 0)
        {
            if (_4tiao.four != A._4tiao.four)
                return _4tiao.four > A._4tiao.four;
            else if (_4tiao.rest != A._4tiao.rest)
                return _4tiao.rest > A._4tiao.rest;
            else
                return com_name(name, A.name);
        } else if (hulu.flag != A.hulu.flag)
            return hulu.flag > A.hulu.flag;
        else if (hulu.flag != 0)
        {
            if (hulu.three != A.hulu.three)
                return hulu.three > A.hulu.three;
            else if (hulu.two != A.hulu.two)
                return hulu.two > A.hulu.two;
            else
                return com_name(name, A.name);
        } else if (_3tiao.flag != A._3tiao.flag)
            return _3tiao.flag > A._3tiao.flag;
        else if (_3tiao.flag != 0)
        {
            if (_3tiao.three != A._3tiao.three)
                return _3tiao.three > A._3tiao.three;
            else if (_3tiao.rest != A._3tiao.rest)
                return _3tiao.rest > A._3tiao.rest;
            else
                return com_name(name, A.name);
        } else if (_2Pair.flag != A._2Pair.flag)
            return _2Pair.flag > A._2Pair.flag;
        else if (_2Pair.flag != 0)
        {
            if (_2Pair.h_two != A._2Pair.h_two)
                return _2Pair.h_two > A._2Pair.h_two;
            else if (_2Pair.l_two2 != A._2Pair.l_two2)
                return _2Pair.l_two2 > A._2Pair.l_two2;
            else if (_2Pair.rest != A._2Pair.rest)
                return _2Pair.rest > A._2Pair.rest;
            else
                return com_name(name, A.name);
        } else if (Pair.flag != A.Pair.flag)
            return Pair.flag > A.Pair.flag;
        else if (Pair.flag != 0)
        {
            if (Pair.two != A.Pair.two)
                return Pair.two > A.Pair.two;
            else if (Pair.rest != A.Pair.rest)
                return Pair.rest > A.Pair.rest;
            else
                return com_name(name, A.name);
        } else
        {
            if (nomi.sum != A.nomi.sum)
                return nomi.sum > A.nomi.sum;
            else
                return com_name(name, A.name);
        }
    }
};
const int maxn = 1e5 + 5;
st people[maxn];
int ma[300];
int main()
{
    std::ios::sync_with_stdio(false);
#ifdef test
    freopen("F:\\Desktop\\question\\in.txt", "r", stdin);
#endif
#ifdef ubuntu
    freopen("/home/time/debug/debug/in", "r", stdin);
    freopen("/home/time/debug/debug/out", "w", stdout);
#endif
    int n;
    ma['A'] = 1;
    ma['J'] = 11;
    ma['Q'] = 12;
    ma['K'] = 13;
    while (cin >> n)
    {
        int i;
        wfor(i, 0, n)
        {
            people[i].init();
            string name;
            string pai;
            cin >> name >> pai;
            people[i].name = name;
            int num[5];
            int len = pai.length();
            int j;
            int cnt = 0;
            wfor(j, 0, len)
            {
                if (isalpha(pai[j]))
                {
                    num[cnt++] = ma[pai[j]];
                } else if (pai[j] == '0')
                {
                    num[cnt - 1] *= 10;
                } else
                {
                    num[cnt++] = pai[j] - '0';
                }
            }
            int sum = 0;
            wfor(j, 0, 5)
            sum += num[j];
            people[i].niubi.check(num);
            people[i].shunzi.check(num);
            people[i]._4tiao.check(num, sum);
            people[i].hulu.check(num);
            people[i]._3tiao.check(num, sum);
            people[i]._2Pair.check(num, sum);
            people[i].Pair.check(num, sum);
            people[i].nomi.sum = sum;
        }
        sort(people, people + n);
        wfor(i, 0, n)
        {
            cout << people[i].name << endl;
        }
    }
    return 0;
}
