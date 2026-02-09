#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
vector<int> es[1000005];
int n, fa[1000005], dep[1000005], cnt[1000005];
void dfs(int now)
{
    cnt[now] = es[now].size();
    for (int x : es[now])
    {
        dep[x] = dep[now] + 1;
        dfs(x);
    }
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> fa[i];
        es[fa[i]].push_back(i);
    }
    dfs(0);
    fa[0] = -1;
    int now;
    while (cin >> now)
    {
        int f = fa[now];
        while (f != -1 && cnt[f] == 1)
        {
            f = fa[f];
        }
        cout << (f == -1 ? 0 : dep[f] + 1) << endl;
        if (f != -1)
        {
            cnt[f]--;
        }
    }
    return 0;
}