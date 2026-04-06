#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int n, ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        string s;
        int x = i;
        while (x)
        {
            s += '0' + x % 2;
            x /= 2;
        }
        int ed = s.size() - 1, ok = 1;
        for (int i = 0; i <= ed; i++)
        {
            if (s[i] != s[ed - i])
            {
                ok = 0;
                break;
            }
        }
        ans += ok;
    }
    cout << ans << endl;
    return 0;
}