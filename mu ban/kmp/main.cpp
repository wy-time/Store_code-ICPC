#include <iostream>
#include<cstring>
using namespace std;
void cal_next(char *str, int *next, int len)
{
    next[0] = -1;//next[0]��ʼ��Ϊ-1��-1��ʾ��������ͬ�����ǰ׺������׺
    int k = -1;//k��ʼ��Ϊ-1
    for (int q = 1; q <= len-1; q++)
    {
        while (k > -1 && str[k + 1] != str[q])//�����һ����ͬ����ôk�ͱ��next[k]��ע��next[k]��С��k�ģ�����kȡ�κ�ֵ��
        {
            k = next[k];//��ǰ����
        }
        if (str[k + 1] == str[q])//�����ͬ��k++
        {
            k = k + 1;
        }
        next[q] = k;//����ǰ����k��ֵ��������ͬ�����ǰ׺������׺��������next[q]
    }
}
int KMP(char *str, int slen, char *ptr, int plen)
{
    int *next = new int[plen];
    cal_next(ptr, next, plen);//����next����
    int k = -1;
    for (int i = 0; i < slen; i++)
    {
        while (k >-1&& ptr[k + 1] != str[i])//ptr��str��ƥ�䣬��k>-1����ʾptr��str�в���ƥ�䣩
            k = next[k];//��ǰ����
        if (ptr[k + 1] == str[i])
            k = k + 1;
        if (k == plen-1)//˵��k�ƶ���ptr����ĩ��
        {
            //cout << i-plen+1+1<< endl;
            //k = -1;//���³�ʼ����Ѱ����һ��
            //i = i - plen + 1;//i��λ����λ�ã����forѭ��i++���Լ�������һ��������Ĭ�ϴ�������ƥ���ַ������Բ����ص�������л������ͬѧָ������
            return i-plen+1;//������Ӧ��λ��
        }
    }
    /*int len=strlen(ptr);
    for(int i=0;i<len-1;i++)
        cout<<next[i]+1<<" ";
    cout<<next[len-1]+1;*/
    return -1;
}
char str[1000005];
char ptr[1000005];
int main()
{
    std::ios::sync_with_stdio(false);
    cin>>str>>ptr;
    KMP(str, strlen(str), ptr, strlen(ptr));//����
    return 0;
}
