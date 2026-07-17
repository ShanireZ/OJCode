#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
struct Node
{
    long long x, l;
    bool operator<(const Node &oth) const
    {
        return x + l < oth.x + oth.l;
    }
};
Node ns[500005];
long long n, now;
priority_queue<long long> pq;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> ns[i].x;
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> ns[i].l;
    }
    sort(ns + 1, ns + n + 1);
    for (int i = 1; i <= n; i++)
    {
        if (now <= ns[i].l)
        {
            pq.push(ns[i].x);
            now += ns[i].x;
        }
        else if (pq.top() > ns[i].x)
        {
            now += ns[i].x - pq.top();
            pq.pop();
            pq.push(ns[i].x);
        }
    }
    cout << pq.size() << endl;
    return 0;
}