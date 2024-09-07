#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
struct Node
{
    long long w;
    int h, id;
    bool operator<(const Node &oth) const
    {
        return (w == oth.w) ? (h > oth.h) : (w > oth.w);
    }
};
priority_queue<Node> q;
int n, k, pos;
int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        long long w;
        cin >> w;
        q.emplace(Node{w, 0, i});
    }
    pos = n;
    while ((pos - 1) % (k - 1) != 0)
    {
        q.emplace(Node{0, 0, ++pos});
    }
    long long ans = 0;
    while (q.size() > 1)
    {
        Node now = {0, 0, ++pos};
        for (int i = 0; i < k; i++)
        {
            Node x = q.top();
            q.pop();
            now.w += x.w, now.h = max(now.h, x.h);
        }
        now.h++;
        q.emplace(now), ans += now.w;
    }
    cout << ans << endl;
    cout << q.top().h << endl;
    return 0;
}