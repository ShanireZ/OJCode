#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
struct Node
{
    int cost, ed;
    bool operator<(const Node oth) const
    {
        return cost < oth.cost;
    }
};
Node ns[150005];
bool cmp(Node a, Node b)
{
    return a.ed < b.ed;
}
priority_queue<Node> q;
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> ns[i].cost >> ns[i].ed;
    }
    sort(ns + 1, ns + 1 + n, cmp);
    long long now = 0;
    for (int i = 1; i <= n; i++)
    {
        if (now + ns[i].cost <= ns[i].ed)
        {
            q.push(ns[i]);
            now += ns[i].cost;
        }
        else
        {
            if (q.top().cost > ns[i].cost)
            {
                now = now - q.top().cost + ns[i].cost;
                q.pop();
                q.push(ns[i]);
            }
        }
    }
    cout << q.size() << endl;
    return 0;
}