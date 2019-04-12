#include <iostream>
#include<map>
using namespace std;
typedef struct
{
    int a;
    int b;
}t;
t time[100000];//结构体来储存数据
struct r1//自定义排序规则
{
    bool operator()(const t& c,const t &d)
    {
        if(c.a!=d.a)
        {
            return c.a<d.a;
        }else
        {
            return d.b<c.b;
        }
    }
};
int main()
{
    int n;//数据的组数
    int cnt=0;//记录删除（被合并）掉的数据的组数
    typedef multimap<t,int,r1> map_times;//定义一个map的容器以自定义规则r1来排序
    map_times map_time;
    while(cin>>n&&n)
    {
        int result=0;
        int i;
        for(i=0;i<n;i++)
        {
            cin>>time[i].a>>time[i].b;
            map_time.insert(make_pair(time[i],time[i].b));//将元素放入map容器中，以时间组成的结构为first，第二台为second
        }
        map_times::iterator d;//迭代器
        map_times::iterator p;
        map_times::iterator p1;//用来指向P的上一个元素
        map_times::iterator p2;//指向p的下一个元素
        d=map_time.begin();//让迭代器 d 指向map中的首元素
        /*for(d=map_time.begin();d!=map_time.end();d++)
        {
            if((p=map_time.find(d->second))!=map_time.end())//在first中找second，即在第一台机器的时间中找与第二台机器相同的，找到就合并。
            {
                result+=d->second;//将结果时间加上合并时略去的部分
                d->second=p->second;//将元素合并
                map_time.erase(p);//删除多余的元素
                cnt++;
            }
        }*/
        p=map_time.begin();
        result+=p->first.a;//将第一个的第一台机器工作时间加给结果
        for(i=0;i<n-cnt-1;i++)
        {
            int temp=p->second;//将map容器中第一个的第二台机器工作时间取出，存入temp
            t timetemp;
            timetemp.a=temp;
            timetemp.b=100000000;
            map_time.insert(make_pair(timetemp,0));//将temp制造成pair插入map中，找出与temp相差最小的第一台机器的工作时间
            map_time.erase(p);//删除第一个元素，它不参与后面的比较
            p=map_time.lower_bound();//找到小与等于temp的最后一个个位置，并让迭代器p指向之
            if(p==map_time.begin())//如果找到p在开头和结尾另行处理
            {
                d=p;
                result+=(++p)->first;
                map_time.erase(d);//删除制造的pair
                d=map_time.upper_bound(p->first)
                //if(--d!=p)
            }
            else
            {
                p1=--p;
                p++;
                p2=++p;
                p--;
                if(p2==map_time.end())
                {
                    result+=p->first;
                    map_time.erase(p);
                    p=p1;
                }else if((p->first)-(p1->first)>(p2->first)-(p->first))//判断是temp左边还是右边与temp更接近，如果一样接近则看second的值，先取second大的元素
                {
                    result+=(p2)->first;//结果加上
                    map_time.erase(p);//删除制造的pair
                    p=p2;//改变p指向的位置
                }else if((p->first)-(p1->first)<(p2->first)-(p->first))
                {
                    result+=p->first;
                    map_time.erase(p);
                    p=p1;
                }else
                {
                    if(p1->second>p2->second)
                    {
                        result+=p->first;
                        map_time.erase(p);
                        p=p1;
                    }else
                    {
                        result+=p2->first;
                        map_time.erase(p);
                        p=p2;
                    }
                }
            }
        }//出循环后容器中应该只剩下一个元素
        p=map_time.begin();
        result+=p->second;
        cout<<result<<endl;;
        map_time.clear();
    }
}
