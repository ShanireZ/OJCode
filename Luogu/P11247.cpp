#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
vector<int> tk[100005];
int cnt[100005], a[100005];
int main()
{
    int m, n, k;
    cin >> m >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        int b;
        cin >> b;
        tk[a[i]].emplace_back(b);
    }
    int usd = 0, mxu = 0;
    for (int i = 1; i <= m; i++)
    {
        sort(tk[i].begin(), tk[i].end(), greater<int>());
        int h = k;
        for (int j = 0; j < (int)tk[i].size() && h > 0; j++)
        {
            h -= tk[i][j], cnt[i]++;
        }
        if (h <= 0)
        {
            usd += cnt[i];
            mxu = max(mxu, cnt[i]);
        }
        else
        {
            cout << -1 << endl;
            return 0;
        }
    }
    if (mxu - 1 > usd - mxu)
    {
        if (mxu - 1 > n - mxu)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << mxu - 1 + mxu << endl;
        }
    }
    else
    {
        cout << usd << endl;
    }
    return 0;
}