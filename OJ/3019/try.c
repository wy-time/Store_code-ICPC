#include<stdio.h>
#include<stdlib.h>
typedef struct list
{
    int id;
    int gread;
   struct list*next;
}list;
list *creat(int len);//��������ĺ���
int main ()
{
    int n,m,i;
    list *p;
    p=(list*)malloc(sizeof(list));
    scanf("%d %d",&n,&m);
    list*a=creat(n);
    list*b=creat(m);
    p=a;
    for (i=0;i<n;i++)
    {
        p=p->next;//�ҵ�a��������һ��Ԫ��.
    }
    p->next=b->next;//ƴ����������
    b=a;//�����������ʼ��ַ�����
    while(a->next!=NULL)//����
    {
        int t=0;
        a=a->next;
        p=a->next;
        while(p!=NULL)
        {
            if(a->id>p->id)
            {
                t=p->id;
                p->id=a->id;
                a->id=t;
                t=p->gread;
                p->gread=a->gread;
                a->gread=t;
            }
            p=p->next;
        }
    }
    while(b->next!=NULL)
    {
        b=b->next;
        printf("%d %d\n",b->id,b->gread);
    }
    return 0;
}
list * creat(int len)
{
    list*head;//����������ʼ��ַ
    list*end;//�������ĩβ�ĵ�ַ��������
    head=end=(list*)malloc(sizeof(list));//����head��endָ��ͬһ����ַ
    list *p;
    while(len--)
    {
        p=(list*)malloc(sizeof(list));
        scanf("%d %d",&p->id,&p->gread);
        p->next=NULL;
        end->next=p;//��һ��ʱhead�ĵ�ַ��end��ͬ������headָ���һ���ڵ�
        end=p;//��end�ĵ�ַ��Ϊp��,end�Լ�ԭ�����ڴ�ռ䲻����ʧ
    }
    return head;
}
