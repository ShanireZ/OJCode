#include <algorithm>
#include <iostream>
using namespace std;
int a[5005], b[5005], n, m, k;
int main()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= k; i++)
    {
        int op, u, v, pos = 0;
        cin >> op >> u >> v;
        if (op == 1)
        {
            a[u] = v;
        }
        else
        {
            for (int j = 1; j <= m; j++)
            {
                if (a[j] == v)
                {
                    b[++pos] = j;
                }
            }
            if (u > pos)
            {
                cout << -1 << endl;
            }
            else
            {
                cout << b[u] << endl;
            }
        }
    }
    return 0;
}