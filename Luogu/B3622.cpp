#include <algorithm>
#include <iostream>
using namespace std;
int a[15], n;
void dfs(int now)
{
    if (now > n)
    {
        for (int i = 1; i <= n; i++)
        {
            cout << (a[i] ? 'Y' : 'N');
        }
        cout << endl;
        return;
    }
    dfs(now + 1);
    a[now] = 1;
    dfs(now + 1);
    a[now] = 0;
}
int main()
{
    cin >> n;
    dfs(1);
    return 0;
}