#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
priority_queue<long long> q;
int main()
{
    int T, n;
    cin >> T;
    while (T--)
    {
        long long res = 0;
        cin >> n >> res;
        for (int i = 2; i <= n + n; i++)
        {
            long long a;
            cin >> a;
            q.push(a);
            if (i % 2 == 1)
            {
                res += q.top();
                q.pop();
            }
        }
        cout << res << endl;
        while (q.size())
        {
            q.pop();
        }
    }
    return 0;
}