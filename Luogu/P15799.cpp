#include <algorithm>
#include <iostream>
#include <unordered_map>
using namespace std;
int n, m, cnt;
unordered_map<int, int> mp;
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        mp[x] = 1;
    }
    for (int i = 1; i <= m; i++)
    {
        int x;
        cin >> x;
        cnt += mp[x];
    }
    cout << cnt << endl;
    return 0;
}