#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
vector<int> to[100005];
int n, ans;
int main()
{
    cin >> n;
    for (int i = 1; i <= n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        to[u].push_back(v);
        to[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
    {
        ans = max(ans, (int)to[i].size() + 1);
    }
    cout << ans << endl;
    return 0;
}