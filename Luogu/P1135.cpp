#include <iostream>
using namespace std;
int to[205], k[205], stp[205];
int main()
{
    int n, a, b;
    cin >> n >> a >> b;
    for (int i = 1; i <= n; i++)
    {
        cin >> k[i];
        stp[i] = -1;
    }
    int st = 0, ed = 0;
    to[++ed] = a, stp[a] = 0;
    while (st != ed)
    {
        st++;
        int now = to[st];
        int t = now + k[now];
        if (now == b)
        {
            cout << stp[now] << endl;
            return 0;
        }
        if (stp[t] == -1 && t >= 1 && t <= n)
        {
            stp[t] = stp[now] + 1;
            to[++ed] = t;
        }
        t = now - k[now];
        if (stp[t] == -1 && t >= 1 && t <= n)
        {
            stp[t] = stp[now] + 1;
            to[++ed] = t;
        }
    }
    cout << -1 << endl;
    return 0;
}