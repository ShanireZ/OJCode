#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
struct Node
{
    int val, dt, id;
};
vector<Node> cl[55];
int nd[55], xpy[55];
bool cmp(Node a, Node b)
{
    if (a.val == b.val)
    {
        if (a.dt == b.dt)
        {
            return a.id < b.id;
        }
        return a.dt > b.dt;
    }
    return a.val < b.val;
}
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> nd[i];
    }
    for (int i = 1; i <= n; i++)
    {
        int cnt = 1e9;
        for (int j = 1; j <= m; j++)
        {
            cin >> xpy[j];
            cnt = min(cnt, xpy[j] / nd[j]);
        }
        for (int j = 1; j <= m; j++)
        {
            cl[j].emplace_back(Node{xpy[j] - cnt * nd[j], cnt, i});
        }
    }
    for (int i = 1; i <= m; i++)
    {
        sort(cl[i].begin(), cl[i].end(), cmp);
        for (Node x : cl[i])
        {
            cout << x.id << " ";
        }
        cout << endl;
    }
    return 0;
}