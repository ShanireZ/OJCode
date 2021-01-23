#include <iostream>
#include <algorithm>
using namespace std;
int dpmax[500005][2], dpmin[500005][2], pos, root;
void dfs(int &now)
{
    now = ++pos;
    char ch;
    cin >> ch;
    if (ch == '2')
    {
        int lc = 0, rc = 0;
        dfs(lc);
        dfs(rc);
        dpmax[now][0] = max(dpmax[lc][1] + dpmax[rc][0], dpmax[lc][0] + dpmax[rc][1]);
        dpmax[now][1] = dpmax[lc][0] + dpmax[rc][0] + 1;
        dpmin[now][0] = min(dpmin[lc][1] + dpmin[rc][0], dpmin[lc][0] + dpmin[rc][1]);
        dpmin[now][1] = dpmin[lc][0] + dpmin[rc][0] + 1;
    }
    else if (ch == '1')
    {
        int c = 0;
        dfs(c);
        dpmax[now][0] = max(dpmax[c][1], dpmax[c][0]);
        dpmax[now][1] = dpmax[c][0] + 1;
        dpmin[now][0] = min(dpmin[c][1], dpmin[c][0]);
        dpmin[now][1] = dpmin[c][0] + 1;
    }
    else
    {
        dpmax[now][0] = dpmin[now][0] = 0;
        dpmax[now][1] = dpmin[now][1] = 1;
    }
}
int main()
{
    dfs(root);
    cout << max(dpmax[root][0], dpmax[root][1]) << " " << min(dpmin[root][0], dpmin[root][1]);
    return 0;
}