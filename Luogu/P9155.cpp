#include <iostream>
using namespace std;
int read(), ans[300005];
int main()
{
    ios::sync_with_stdio(false);
    int t = read();
    while (t--)
    {
        int n = read(), st = 150000, ed = 150000;
        while (n--)
        {
            int opt = read();
            if (opt == 1) // 乘2
            {
                ed += (st != ed || ans[st] == 1);
            }
            else // 加d
            {
                int d = read(), pos = ed;
                while (d)
                {
                    int tmp = d % 2, now = pos;
                    while (tmp)
                    {
                        st = min(st, now), tmp = tmp + ans[now];
                        ans[now--] = tmp % 2, tmp /= 2;
                    }
                    d /= 2, pos--;
                }
            }
        }
        for (int i = st; i <= ed; i++)
        {
            cout << ans[i];
            ans[i] = 0;
        }
        cout << "\n";
    }
    return 0;
}
int read()
{
    int ans = 0;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        ans = ans * 10 + ch - '0';
        ch = getchar();
    }
    return ans;
}