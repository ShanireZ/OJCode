#include <algorithm>
#include <iostream>
using namespace std;
int a[10], n, k;
void dfs(int now)
{
    if (now > n)
    {
        for (int i = 1; i <= n; i++)
        {
            cout << a[i] << " ";
        }
        cout << endl;
        return;
    }
    for (int i = 1; i <= k; i++)
    {
        a[now] = i;
        dfs(now + 1);
    }
}
int main()
{
    cin >> n >> k;
    dfs(1);
    return 0;
}