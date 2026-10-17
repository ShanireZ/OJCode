#include <iostream>
#include <cstring>
using namespace std;
int edit[5005], st[5005]; //st初始狀態 edit反轉情況的差分
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
    for (int k = 1; k <= n; k++) //枚舉每一個反轉長度
    {
        memset(edit, 0, sizeof(edit));
        int tag = 0, m = 0, trig = 1;
        for (int i = 1; i <= n; i++)
        {
            tag += edit[i];
            //偶數反轉次數等於沒轉 沒轉的時候且初始向後 需要反轉
            //奇數反轉次數等於反轉1次 反轉1次且初始向前 需要反轉
            if ((tag % 2 == 0 && st[i] == 1) || (tag % 2 == 1 && st[i] == 0))
            {
                if (i + k > n + 1) //如果超界了 說明不能以這個長度反轉
                {
                    trig = 0;
                    break;
                }
                edit[i + 1]++;
                edit[i + k]--;
                m++;
            }
        }
        if (minm > m && trig) //出現更少的反轉次數 且 能成功反轉所有
        {
            minm = m;
            mink = k;
        }
    }
    cout << mink << " " << minm;
    return 0;
}