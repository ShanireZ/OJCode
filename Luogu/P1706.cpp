#include <algorithm>
#include <iomanip>
#include <iostream>
using namespace std;
int n, vis[10], box[10];
void dfs(int now)
{
    if (now > n)
    {
        for (int i = 1; i <= n; i++)
        {
            cout << "    " << box[i];
        }
        cout << endl;
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == 1)
        {
            continue;
        }
        box[now] = i, vis[i] = 1;
        dfs(now + 1);
        box[now] = 0, vis[i] = 0;
    }
}
int main()
{
    cin >> n;
    dfs(1);
    return 0;
}