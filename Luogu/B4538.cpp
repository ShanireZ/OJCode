#include <algorithm>
#include <iostream>
using namespace std;
int c[100005], tot[100005], pos[100005], n, m, id;
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int op, x;
        cin >> op >> x;
        if (op == 1)
        {
            c[pos[x]]--;
        }
        else
        {
            id++;
            pos[id] = x;
            c[x]++, tot[x]++;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << c[i] << " ";
    }
    cout << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << tot[i] << " ";
    }
    return 0;
}