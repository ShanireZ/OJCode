#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
struct Node
{
    long long pos, val;
    bool operator<(const Node &oth) const
    {
        return val < oth.val;
    }
};
priority_queue<Node> q;
long long n, ans = 1e18, a[1000005], b[1000005];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i + n] = a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
        b[i + n] = b[i];
    }
    for (int i = 1; i <= n + n; i++)
    {
        b[i] += b[i - 1];
    }
    // res_j = max(a[i] - b[i - 1] + b[j - 1]), j + n - 1 >= i >= j
    // ans = min(ans, res_j), n >= j >= 1
    for (int i = 1; i <= n; i++)
    {
        q.push(Node{i, a[i] - b[i - 1]});
    }
    for (int j = 1; j <= n; j++)
    {
        while (q.top().pos < j)
        {
            q.pop();
        }
        ans = min(ans, q.top().val + b[j - 1]);
        q.push(Node{n + j, a[j] - b[n + j - 1]});
    }
    cout << ans << endl;
    return 0;
}