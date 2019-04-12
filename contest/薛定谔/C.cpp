#include<iostream>
#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;
int N, M;
int dataSet[100005];

bool pd_section (int middle_value) {
    int cnt, sum;
    cnt = 1;
    sum = 0;
    for (int i = 0; i < N; i++) {
        sum +=  dataSet[i];
        if (sum > middle_value ) {
            cnt++;
            sum = dataSet[i];
        }
        if (cnt > M) {
            return false;
        }
    }
    return true;
}

int main ()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> N >> M;
        int max_value = 0;
        int sum_value = 0;
        for (int i = 0; i < N; i++) {
            cin >> dataSet[i];
            sum_value += dataSet[i];
            max_value = max(max_value, dataSet[i]);
        }
        int start_flag, end_flag;
        start_flag = max_value;
        end_flag = sum_value;
        int middle_value;
        while (start_flag <= end_flag) {
            middle_value = (start_flag + end_flag) / 2;
            if ( pd_section(middle_value) ) {
                end_flag = middle_value - 1;
            } else {
                start_flag = middle_value + 1;
            }
        }
        cout << middle_value << endl;
    }
    return 0;
}