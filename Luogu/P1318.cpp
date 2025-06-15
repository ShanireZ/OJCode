#include <algorithm>
#include <iostream>
#include <stack>
using namespace std;
int n, ans, h[10005], l[10005], r[10005];
stack<pair<int, int>> s;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> h[i];
        while (s.size() && s.top().first < h[i])
        {
            r[s.top().second] = i;
            s.pop();
        }
        s.push({h[i], i});
    }
    while (s.size())
    {
        s.pop();
    }
    for (int i = n; i >= 1; i--)
    {
        while (s.size() && s.top().first < h[i])
        {
            l[s.top().second] = i;
            s.pop();
        }
        s.push({h[i], i});
    }
    while (true)
    {
        int now = ans;
        for (int i = 1; i <= n; i++)
        {
            if (l[i] && r[i])
            {
                ans += min(h[l[i]], h[r[i]]) - h[i];
                h[i] = min(h[l[i]], h[r[i]]);
            }
        }
        if (ans == now)
        {
            break;
        }
    }
    cout << ans << endl;
    return 0;
}