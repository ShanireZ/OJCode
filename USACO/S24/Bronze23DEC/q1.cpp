#include <algorithm>
#include <iostream>
using namespace std;
long long s[200005], h[200005], pos;
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> h[i];
        if (h[s[pos]] < h[i])
        {
            s[++pos] = i;
        }
    }
    for (int i = 1; i <= m; i++)
    {
        long long cnt, pre = 0;
        cin >> cnt;
        for (int i = 1; i <= pos; i++)
        {
            if (h[s[i]] <= pre)
            {
                continue;
            }
            int ex = min(cnt, h[s[i]]) - pre;
            pre = h[s[i]];
            h[s[i]] += ex;
            if (pre >= cnt)
            {
                break;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << h[i] << endl;
    }
    return 0;
}