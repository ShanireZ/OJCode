#include <algorithm>
#include <iostream>
using namespace std;
int qz[1000005], t;
int main()
{
    for (int i = 1, num = 1; i <= 1000000; num++)
    {
        string s = to_string(num);
        for (int j = 1; j <= num && i <= 1000000; j++) // 当前数字次数
        {
            for (int k = 0; k < (int)s.size() && i <= 1000000; k++) // 遍历当前数字,加到字符串中
            {
                qz[i++] = qz[i - 1] + s[k] - '0';
            }
        }
    }
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        int l, r;
        cin >> l >> r;
        cout << qz[r] - qz[l - 1] << endl;
    }
    return 0;
}