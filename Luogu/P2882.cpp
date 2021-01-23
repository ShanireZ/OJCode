#include <iostream>
#include <cstring>
using namespace std;
int edit[5005], st[5005]; //st初始状态 edit反转情况的差分
int main()
{
    int n;
    cin >> n;
    //0表示F 1表示B
    for (int i = 1; i <= n; i++)
    {
        char ch;
        cin >> ch;
        if (ch == 'F')
        {
            st[i] = 0;
        }
        else
        {
            st[i] = 1;
        }
    }
    int mink = 0x3f3f3f3f, minm = 0x3f3f3f3f;
    for (int k = 1; k <= n; k++) //枚举每一个反转长度
    {
        memset(edit, 0, sizeof(edit));
        int tag = 0, m = 0, trig = 1;
        for (int i = 1; i <= n; i++)
        {
            tag += edit[i];
            //偶数反转次数等于没转 没转的时候且初始向后 需要反转
            //奇数反转次数等于反转1次 反转1次且初始向前 需要反转
            if ((tag % 2 == 0 && st[i] == 1) || (tag % 2 == 1 && st[i] == 0))
            {
                if (i + k > n + 1) //如果超界了 说明不能以这个长度反转
                {
                    trig = 0;
                    break;
                }
                edit[i + 1]++;
                edit[i + k]--;
                m++;
            }
        }
        if (minm > m && trig) //出现更少的反转次数 且 能成功反转所有
        {
            minm = m;
            mink = k;
        }
    }
    cout << mink << " " << minm;
    return 0;
}