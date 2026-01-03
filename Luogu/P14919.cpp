#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
vector<int> tr[100005];
long long c[100005], n;
void dfs(int now)
{
    long long tot = 0;
    for (int nxt : tr[now])
    {
        dfs(nxt);
        tot += c[nxt];
    }
    if (tr[now].size())
    {
        c[now] = min(c[now], tot);
    }
}
int main()
{
    cin >> n;
    for (int i = 2; i <= n; i++)
    {
        int fa;
        cin >> fa;
        tr[fa].push_back(i);
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> c[i];
    }
    dfs(1);
    cout << c[1] << endl;
    return 0;
}