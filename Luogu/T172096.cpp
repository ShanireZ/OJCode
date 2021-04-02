#include <iostream>
using namespace std;
int a[25];
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        a[x] = 1;
    }
    int tot = 0;
    for (int i = 1; i <= m; i++)
    {
        int x;
        cin >> x;
        if (a[x] == 1)
        {
            tot++;
        }
    }
    cout << tot;
    return 0;
}