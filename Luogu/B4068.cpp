#include <algorithm>
#include <iostream>
using namespace std;
int a[3005], vis[100005];
int main()
{
    int n;
    cin >> n;
    a[1] = vis[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        int x = a[i - 1] - i;
        a[i] = (x > 0 && vis[x] == 0) ? x : x + i + i;
        vis[a[i]] = 1;
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}