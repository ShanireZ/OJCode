#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int n, cnt, a[2005], vis[200005];
vector<int> ans;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        vis[a[i]] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j < i; j++)
        {
            int x = a[i] + a[j];
            if (vis[x] == 0)
            {
                vis[x] = 1, cnt++;
                ans.push_back(x);
            }
        }
    }
    cout << cnt << endl;
    sort(ans.begin(), ans.end());
    for (int x : ans)
    {
        cout << x << " ";
    }
    return 0;
}