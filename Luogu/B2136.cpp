#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
int prim[10005], all[10005], pos, n, cnt;
string s;
int main()
{
    cin >> n;
    prim[0] = 1, prim[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        if (prim[i] == 0)
        {
            if (i >= 11)
            {
                pos++;
                all[pos] = i;
            }
            for (int j = i * 2; j <= n; j += i)
            {
                prim[j] = 1;
            }
        }
    }
    for (int i = 1; i <= pos; i++)
    {
        s = to_string(all[i]);
        int ok = 1;
        for (int a = 0, b = s.size() - 1; a <= b; a++, b--)
        {
            if (s[a] != s[b])
            {
                ok = 0;
                break;
            }
        }
        if (ok == 1)
        {
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}