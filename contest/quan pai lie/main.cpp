#include <iostream>
#include<algorithm>
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    int a[] = {1,2,3,4,5,6,7,8};
    do
    {
        cout << a[0] << " " << a[1] << " " << a[2] <<" "<< a[3]<<" "<< a[4]<<" "<< a[5]<<" "<< a[6]<<" "<< a[7]<<endl;
    }
    while (next_permutation(a,a+8));
    return 0;
}
