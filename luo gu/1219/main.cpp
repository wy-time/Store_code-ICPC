/**
 *                             _ooOoo_
 *                            o8888888o
 *                            88" . "88
 *                            (| -_- |)
 *                            O\  =  /O
 *                         ____/`---'\____
 *                       .'  \\|     |//  `.
 *                      /  \\|||  :  |||//  \
 *                     /  _||||| -:- |||||-  \
 *                     |   | \\\  -  /// |   |
 *                     | \_|  ''\---/''  |   |
 *                     \  .-\__  `-`  ___/-. /
 *                   ___`. .'  /--.--\  `. . __
 *                ."" '<  `.___\_<|>_/___.'  >'"".
 *               | | :  `- \`.;`\ _ /`;.`/ - ` : | |
 *               \  \ `-.   \_ __\ /__ _/   .-` /  /
 *          ======`-.____`-.___\_____/___.-`____.-'======
 *                             `=---='
 *          ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
 *                     ���汣��        ����BUG
 *            ��Ի:
 *                   д��¥��д�ּ䣬д�ּ������Ա��
 *                   ������Աд�������ó��򻻾�Ǯ��
 *                   ����ֻ���������������������ߣ�
 *                   ��������ո��գ����������긴�ꡣ
 *                   ��Ը�������Լ䣬��Ը�Ϲ��ϰ�ǰ��
 *                   ���۱������Ȥ���������г���Ա��
 *                   ����Ц��߯��񲣬��Ц�Լ���̫����
 *                   ��������Ư���ã��ĸ���ó���Ա��
**/
#include <iostream>
#include<cstring>
using namespace std;
bool slove(int times,int result[]);
int n;
bool ans1[50]={false};
bool ans2[50]={false};
bool ans3[50]={false};
int cnt=0;
int main()
{
    int result[13]={0};
    cin>>n;

    int i;
    for(i=0;i<n;i++)
    {
        memset(ans1,false,sizeof(ans1));
        memset(ans2,false,sizeof(ans2));
        memset(ans3,false,sizeof(ans3));
        result[0]=i+1;
        ans3[i]=true;
        ans1[0+i]=true;
        ans2[i-0+20]=true;
        slove(0,result);
    }
    cout<<cnt;
    return 0;
}
bool slove(int times,int result[])
{
    int i,k;
    int x=times+1;
    int y;
    int flag=1;
    for(i=0;i<n;i++)
    {
        flag=1;
        y=i;
        x=times+1;
        if(ans1[x+y]||ans2[(y-x)+20]||ans3[i])
        {
            flag=0;
        }
        if(flag)
        {
            ans3[i]=true;
            ans1[x+y]=true;
            ans2[(y-x)+20]=true;
            if(times!=n-2)
            {
                result[times+1]=i+1;
                if(slove(times+1,result))
                {
                    //ppp=true;
                }else
                {
                    ans3[i]=false;
                    ans1[x+y]=false;
                    ans2[20+(y-x)]=false;
                }
            }else
            {
                result[times+1]=i+1;
                cnt++;
                if(cnt<4)
                {
                    for(k=0;k<n-1;k++)
                    {
                        cout<<result[k]<<" ";
                    }
                    cout<<result[k]<<endl;
                }
                ans3[i]=false;
                ans1[x+y]=false;
                ans2[20+(y-x)]=false;
                return false;
            }
        }
    }
    return false;
}
