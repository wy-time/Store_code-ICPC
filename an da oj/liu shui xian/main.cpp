#include <iostream>
#include<map>
using namespace std;
typedef struct
{
    int a;
    int b;
}t;
t time[100000];//�ṹ������������
struct r1//�Զ����������
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
    int n;//���ݵ�����
    int cnt=0;//��¼ɾ�������ϲ����������ݵ�����
    typedef multimap<t,int,r1> map_times;//����һ��map���������Զ������r1������
    map_times map_time;
    while(cin>>n&&n)
    {
        int result=0;
        int i;
        for(i=0;i<n;i++)
        {
            cin>>time[i].a>>time[i].b;
            map_time.insert(make_pair(time[i],time[i].b));//��Ԫ�ط���map�����У���ʱ����ɵĽṹΪfirst���ڶ�̨Ϊsecond
        }
        map_times::iterator d;//������
        map_times::iterator p;
        map_times::iterator p1;//����ָ��P����һ��Ԫ��
        map_times::iterator p2;//ָ��p����һ��Ԫ��
        d=map_time.begin();//�õ����� d ָ��map�е���Ԫ��
        /*for(d=map_time.begin();d!=map_time.end();d++)
        {
            if((p=map_time.find(d->second))!=map_time.end())//��first����second�����ڵ�һ̨������ʱ��������ڶ�̨������ͬ�ģ��ҵ��ͺϲ���
            {
                result+=d->second;//�����ʱ����Ϻϲ�ʱ��ȥ�Ĳ���
                d->second=p->second;//��Ԫ�غϲ�
                map_time.erase(p);//ɾ�������Ԫ��
                cnt++;
            }
        }*/
        p=map_time.begin();
        result+=p->first.a;//����һ���ĵ�һ̨��������ʱ��Ӹ����
        for(i=0;i<n-cnt-1;i++)
        {
            int temp=p->second;//��map�����е�һ���ĵڶ�̨��������ʱ��ȡ��������temp
            t timetemp;
            timetemp.a=temp;
            timetemp.b=100000000;
            map_time.insert(make_pair(timetemp,0));//��temp�����pair����map�У��ҳ���temp�����С�ĵ�һ̨�����Ĺ���ʱ��
            map_time.erase(p);//ɾ����һ��Ԫ�أ������������ıȽ�
            p=map_time.lower_bound();//�ҵ�С�����temp�����һ����λ�ã����õ�����pָ��֮
            if(p==map_time.begin())//����ҵ�p�ڿ�ͷ�ͽ�β���д���
            {
                d=p;
                result+=(++p)->first;
                map_time.erase(d);//ɾ�������pair
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
                }else if((p->first)-(p1->first)>(p2->first)-(p->first))//�ж���temp��߻����ұ���temp���ӽ������һ���ӽ���second��ֵ����ȡsecond���Ԫ��
                {
                    result+=(p2)->first;//�������
                    map_time.erase(p);//ɾ�������pair
                    p=p2;//�ı�pָ���λ��
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
        }//��ѭ����������Ӧ��ֻʣ��һ��Ԫ��
        p=map_time.begin();
        result+=p->second;
        cout<<result<<endl;;
        map_time.clear();
    }
}
