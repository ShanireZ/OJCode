#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
int def[5005];
priority_queue<int> q;
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        while (q.size())
        {
            q.pop();
        }
        int n, t, m;
        cin >> n >> t >> m;
        for (int i = 1; i <= n; i++)
        {
            cin >> def[i];
        }
        for (int i = 1; i <= m; i++)
        {
            int p;
            cin >> p;
            def[p] -= 2;
        }
        for (int i = 1; i <= n; i++)
        {
            if (def[i] <= 0)
            {
                q.push(def[i]);
            }
        }
        while (q.size() && t)
        {
            t += q.top() - 1;
            q.pop();
            if (t < 0)
            {
                t = 0, q.push(t);
            }
        }
        cout << n - q.size() << endl;
    }
    return 0;
}