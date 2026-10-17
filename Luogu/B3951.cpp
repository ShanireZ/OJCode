#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int n, m, h[2005];
vector<int> q;
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> h[i];
    }
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        int pos = upper_bound(q.begin(), q.end(), h[x]) - q.begin();
        cout << q.size() - pos << endl;     // 統計有多少人比當前h[x]高
        if (pos == 0 || q[pos - 1] != h[x]) // 去重 因為相同身高的不用挨個往後挪
        {
            q.insert(q.begin() + pos, h[x]);
        }
    }
    return 0;
}