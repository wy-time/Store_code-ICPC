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
 *                     佛祖保佑        永无BUG
 *            佛曰:
 *                   写字楼里写字间，写字间里程序员；
 *                   程序人员写程序，又拿程序换酒钱。
 *                   酒醒只在网上坐，酒醉还来网下眠；
 *                   酒醉酒醒日复日，网上网下年复年。
 *                   但愿老死电脑间，不愿鞠躬老板前；
 *                   奔驰宝马贵者趣，公交自行程序员。
 *                   别人笑我忒疯癫，我笑自己命太贱；
 *                   不见满街漂亮妹，哪个归得程序员？
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
