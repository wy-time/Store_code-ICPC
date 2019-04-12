#include<stdio.h>
#include<stdlib.h>
typedef struct list
{
    int id;
    int gread;
   struct list*next;
}list;
list *creat(int len);//创建链表的函数
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
        p=p->next;//找到a链表的最后一个元素.
    }
    p->next=b->next;//拼接两个链表
    b=a;//保存链表的起始地址输出用
    while(a->next!=NULL)//排序
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
    list*head;//存放链表的起始地址
    list*end;//存放链表末尾的地址，操作用
    head=end=(list*)malloc(sizeof(list));//现在head和end指向同一个地址
    list *p;
    while(len--)
    {
        p=(list*)malloc(sizeof(list));
        scanf("%d %d",&p->id,&p->gread);
        p->next=NULL;
        end->next=p;//第一次时head的地址和end相同，于是head指向第一个节点
        end=p;//将end的地址改为p的,end自己原来的内存空间不会消失
    }
    return head;
}
