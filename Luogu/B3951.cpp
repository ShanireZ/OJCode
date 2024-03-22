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
        cout << q.size() - pos << endl;     // 统计有多少人比当前h[x]高
        if (pos == 0 || q[pos - 1] != h[x]) // 去重 因为相同身高的不用挨个往后挪
        {
            q.insert(q.begin() + pos, h[x]);
        }
    }
    return 0;
}