#include <iostream>
#include <unordered_map>
using namespace std;
unordered_map<int, int> cnt;
int t[3000], tot;
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        for (int j = 1; j * x <= m; j++)
        {
            cnt[j * x]++;
        }
    }
    for (auto it = cnt.begin(); it != cnt.end(); it++)
    {
        t[it->second]++;
        tot++;
    }
    cout << m - tot << " ";
    for (int i = 1; i <= n; i++)
    {
        cout << t[i] << " ";
    }
    return 0;
}