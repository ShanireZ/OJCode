#include <iostream>
#include <queue>
using namespace std;
struct Node
{
    long long a, b, c;
};
struct cmpa
{
    bool operator()(Node x, Node y)
    {
        return x.a > y.a;
    }
};
struct cmpb
{
    bool operator()(Node x, Node y)
    {
        return x.b < y.b;
    }
};
priority_queue<Node, vector<Node>, cmpa> qa;
priority_queue<Node, vector<Node>, cmpb> qb;
int main()
{
    long long x, n;
    cin >> x >> n;
    for (int i = 1; i <= n; i++)
    {
        long long a, b, c;
        cin >> a >> b >> c;
        b >= x ? qa.emplace(Node{a, b, c}) : qb.emplace(Node{a, b, c});
    }
    long long ans = 0, now = x;
    while (now > 0)
    {
        if (qa.empty())
        {
            cout << -1 << endl;
            return 0;
        }
        Node t = qa.top();
        qa.pop();
        long long cnt = min(t.c, now);
        if (qb.size())
        {
            cnt = min(cnt, now - qb.top().b);
        }
        ans += t.a * cnt, now -= cnt, t.c -= cnt;
        if (t.c > 0)
        {
            qa.emplace(t);
        }
        while (qb.size() && qb.top().b >= now)
        {
            qa.emplace(qb.top());
            qb.pop();
        }
    }
    cout << ans << endl;
    return 0;
}