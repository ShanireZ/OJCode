#include <algorithm>
#include <iostream>
using namespace std;
string s;
int n, m, cn[1000005], cv[1000005];
long long pre, cnt;
int main()
{
    cin >> n >> m >> s;
    s = 'x' + s;
    for (int i = 1; i <= n; i++)
    {
        cv[i] = cv[i - 1] + (s[i] == 'v');
        if (s[i] == 'a')
        {
            pre += cv[i];
        }
        else if (s[i] == 'n')
        {
            cnt += pre;
        }
    }
    for (int i = n; i >= 1; i--)
    {
        cn[i] = cn[i + 1] + (s[i] == 'n');
    }
    while (m--)
    {
        int x;
        cin >> x;
        if (s[x] == 'v' && s[x + 1] == 'a')
        {
            cnt -= cn[x + 1];
            cv[x]--;
        }
        else if (s[x] == 'a' && s[x + 1] == 'v')
        {
            cnt += cn[x + 1];
            cv[x]++;
        }
        else if (s[x] == 'a' && s[x + 1] == 'n')
        {
            cnt -= cv[x - 1];
            cn[x + 1]--;
        }
        else if (s[x] == 'n' && s[x + 1] == 'a')
        {
            cnt += cv[x - 1];
            cn[x + 1]++;
        }
        else if (s[x] == 'n' && s[x + 1] == 'v')
        {
            cv[x]++, cn[x + 1]++;
        }
        else if (s[x] == 'v' && s[x + 1] == 'n')
        {
            cv[x]--, cn[x + 1]--;
        }
        swap(s[x], s[x + 1]);
        cout << cnt << endl;
    }
    return 0;
}