#include <iostream>
#include <queue>
#include <vector>
using namespace std;
queue<int> q;
vector<int> to[100005];
int de[100005], h[100005];
int main()
{
    int n, k;
    cin >> n >> k;
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        to[u].push_back(v);
        to[v].push_back(u);
        de[u]++, de[v]++;
    }
    for (int i = 1; i <= n; i++)
    {
        if (de[i] == 1)
        {
            q.push(i), h[i] = 1;
        }
    }
    k = n - k;
    while (q.size())
    {
        int now = q.front();
        q.pop(), k--;
        if (k == 0)
        {
            cout << h[now] << endl;
            break;
        }
        for (int nxt : to[now])
        {
            de[nxt]--;
            if (de[nxt] == 1)
            {
                q.push(nxt), h[nxt] = h[now] + 1;
            }
        }
    }
    return 0;
}