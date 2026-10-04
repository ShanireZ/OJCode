#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int cnt[200005][2], n;
vector<int> to[200005];
void dfs(int now)
{
    for (int nxt : to[now])
    {
        dfs(nxt);
        cnt[now][0] += cnt[nxt][0];
        cnt[now][1] += cnt[nxt][1];
    }
    cnt[now][now % 2]++;
}
int main()
{
    cin >> n;
    for (int i = 2; i <= n; i++)
    {
        int f;
        cin >> f;
        to[f].push_back(i);
    }
    dfs(1);
    for (int i = 1; i <= n; i++)
    {
        cout << cnt[i][i % 2] << '\n';
    }
    cout << endl;
    return 0;
}