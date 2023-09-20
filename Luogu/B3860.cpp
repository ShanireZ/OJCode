#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
vector<int> yl[5005];
queue<int> q;
int vis[5005], ans;
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int k, x;
        cin >> k;
        for (int j = 1; j <= k; j++)
        {
            cin >> x;
            yl[i].push_back(x);
        }
    }
    q.push(1), vis[1] = 1, ans = 1;
    while (q.size())
    {
        int now = q.front();
        q.pop();
        for (int nxt : yl[now])
        {
            if (vis[nxt] == 0)
            {
                q.push(nxt), vis[nxt] = 1, ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}