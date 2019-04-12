#include <iostream>
#include<cstring>
using namespace std;
int ma[5005][5005];
int mindis[10005];
bool vis[10005];
const int INF = 0x3f3f3f;
int main()
{
    std::ios::sync_with_stdio(false);
    memset(ma, INF, sizeof(ma));
    int n, m;
    cin >> n >> m;
    int i;
    for (i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        ma[a][b] = ma[b][a] = min(c, min(ma[a][b], ma[b][a])); //���뵽���������Сֵ
    }
    for (i = 1; i <= n; i++)
    {
        mindis[i] = ma[1][i]; //��ʼ����̾������飬ĿǰΪ��һ���㵽�����ܵ��ĵ����̾��룬INF��ʾ������
    }
    vis[1] = true; //��һ�����Ѿ��߹�
    bool liantong = true;
    long long cost = 0;
    for (i = 1; i < n; i++) //n�����ѭ��
    {
        int tempdis = INF;
        int k = -1;
        for (int j = 1; j <= n; j++) //��Ŀǰ����̾���
        {
            if (!vis[j] && mindis[j] < tempdis)
            {
                tempdis = mindis[j];
                k = j;
            }
        }
        if (k == -1)
        {
            liantong = false; //���Ƿ���ͨ
            break;
        }
        cost += tempdis;
        vis[k] = true;
        for (int j = 1; j <= n; j++)
        {
            if (!vis[j] && mindis[j] > ma[k][j]) //��Ϊ����һ����������Ը�����̾������飬��̾���������Ŀǰ������������ֵ
                mindis[j] = ma[k][j];
        }
    }
    if (!liantong)
        cout << "orz" << endl;
    else
        cout << cost << endl;
    return 0;
}
