#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int q;
    cin >> q;
    for (int i = 1; i <= q; i++)
    {
        long long s[4], tot = 0;
        cin >> s[0] >> s[1] >> s[2] >> s[3];
        sort(s, s + 4);
        if (s[0] + s[3] == s[1] + s[2]) //可行
        {
            //03-12  03-21 ---4 * 2 最大8种情况
            tot = 8;
            if (s[0] == s[3]) //都相同
            {
                tot = 1;
            }
            else if (s[0] == s[1] || s[1] == s[2]) //不都相同，但存在部分相同
            {
                tot = 4;
            }
        }
        cout << tot << endl;
    }
    return 0;
}