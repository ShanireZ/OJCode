#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;
int n, m;
long long k, a[300005];
deque<long long> q;
int main()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i++)
    {
        q.push_back(a[i]);
    }
    long long tot = 0;
    for (int i = 1; i <= m; i++)
    {
        int op;
        cin >> op;
        long long x;
        if (op == 1) //正向
        {
            cin >> x;
            tot += x;
            while (q.size() && q.back() + tot > k)
            {
                q.pop_back();
            }
        }
        else if (op == 2) //负向
        {
            cin >> x;
            tot -= x;
            while (q.size() && q.front() + tot < -k)
            {
                q.pop_front();
            }
        }
        else
        {
            cout << q.size() << endl;
        }
    }
    return 0;
}