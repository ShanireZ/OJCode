#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
vector<int> chs[1000005];
int T, n, sz[1000005], dep[1000005];
void dfs(int now)
{
    sz[now] = 1;
    for (int ch : chs[now])
    {
        dep[ch] = dep[now] + 1;
        dfs(ch);
        sz[now] += sz[ch];
    }
}
int main()
{
    cin >> T;
    while (T--)
    {
        cin >> n;
        for (int i = 1; i < n; i++)
        {
            int x, y;
            cin >> x >> y;
            chs[x].push_back(y);
        }
        dep[1] = 1, dfs(1);
        for (int i = 1; i <= n; i++)
        {
            cout << dep[i] << " " << n - sz[i] + 1 << endl;
            dep[i] = sz[i] = 0, chs[i].clear();
        }
    }
    return 0;
}