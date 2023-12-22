#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
string s;
int stk[200005];
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n, pos = 0;
        cin >> n >> s;
        s += 'z', stk[0] = n;
        for (int i = 0; i < n; i++)
        {
            while (s[i] > s[stk[pos]])
            {
                pos--;
            }
            stk[++pos] = i;
        }
        int ans = pos;
        for (int i = 1; i <= pos; i++) // 尾部最长相同长度
        {
            if (s[stk[i]] != s[stk[1]])
            {
                ans = i - 1;
                break;
            }
        }
        for (int i = 1; i <= pos / 2; i++)
        {
            swap(s[stk[i]], s[stk[pos - i + 1]]);
        }
        int ok = 1;
        for (int i = 0; i < n; i++)
        {
            if (s[i] > s[i + 1])
            {
                ok--;
                break;
            }
        }
        cout << (ok == 0 ? -1 : pos - ans) << endl;
    }
    return 0;
}