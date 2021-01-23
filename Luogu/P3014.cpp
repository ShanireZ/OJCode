#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;
long long fact[50];
vector<int> inital;
int main()
{
    int n, k;
    cin >> n >> k;
    fact[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        fact[i] = fact[i - 1] * i;
        inital.push_back(i);
    }
    for (int i = 1; i <= k; i++)
    {
        char op;
        long long x;
        cin >> op;
        vector<int> vis = inital;
        if (op == 'P')
        {
            cin >> x;
            x--;
            for (int j = 1; j <= n; j++)
            {
                int id = x / fact[n - j];
                x = x % fact[n - j];
                cout << vis[id] << " ";
                vis.erase(vis.begin() + id);
            }
            cout << endl;
        }
        else
        {
            long long ans = 1;
            for (int j = 1; j <= n; j++)
            {
                cin >> x;
                int id = lower_bound(vis.begin(), vis.end(), x) - vis.begin();
                ans += id * fact[n - j];
                vis.erase(vis.begin() + id);
            }
            cout << ans << endl;
        }
    }
    return 0;
}