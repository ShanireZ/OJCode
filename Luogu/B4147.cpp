#include <algorithm>
#include <iostream>
#include <map>
using namespace std;
int n, x, sz = 1, d[20], c[20];
map<string, int> mp;
void dfs(int now)
{
    if (now == n)
    {
        string s1, s2;
        for (int i = 0; i < x; i++)
        {
            s1 += to_string(c[i]) + "-";
            cout << c[i] << " ";
        }
        for (int i = x + 1; i < n; i++)
        {
            s2 += to_string(c[i]) + "-";
            cout << c[i] << " ";
        }
        int sum = 0;
        for (int i = 0; i < d[x]; i++)
        {
            string mid = to_string(i) + "-";
            sum += mp[s1 + mid + s2];
        }
        cout << sum << endl;
        return;
    }
    for (int i = 0; i < d[now]; i++)
    {
        c[now] = i;
        now + 1 == x ? dfs(now + 2) : dfs(now + 1);
    }
}
int main()
{
    cin >> n >> x;
    for (int i = 0; i < n; i++)
    {
        cin >> d[i];
        sz *= d[i];
    }
    for (int i = 0; i < sz; i++)
    {
        string str;
        int id, val;
        for (int j = 0; j < n; j++)
        {
            cin >> id;
            str += to_string(id) + "-";
        }
        cin >> val;
        mp[str] = val;
    }
    x != 0 ? dfs(0) : dfs(1);
    return 0;
}