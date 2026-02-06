#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct Node
{
    int id, val;
    bool operator<(const Node &oth) const
    {
        return val > oth.val;
    }
};
priority_queue<Node> q;
vector<int> es[300005];
int n, v[300005];
int main()
{
    cin >> n;
    for (int i = 2; i <= n; i++)
    {
        int p;
        cin >> p;
        es[p].push_back(i);
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }
    q.push(Node{1, v[1]});
    for (int i = 1; i <= n; i++)
    {
        Node now = q.top();
        q.pop();
        cout << now.val << endl;
        for (int nxt : es[now.id])
        {
            q.push(Node{nxt, v[nxt]});
        }
    }
    return 0;
}