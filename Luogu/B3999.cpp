#include <algorithm>
#include <iostream>
using namespace std;
struct Node
{
    int v, id;
};
Node dan[1005], mk[1005];
bool cmp0(Node a, Node b)
{
    return a.v < b.v;
}
bool cmp1(Node a, Node b)
{
    return a.v > b.v;
}
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> mk[i].v;
            mk[i].id = i;
        }
        for (int i = 1; i <= n; i++)
        {
            cin >> dan[i].v;
            dan[i].id = i;
        }
        sort(mk + 1, mk + 1 + n, cmp1);
        sort(dan + 1, dan + 1 + n, cmp0);
        int ok = 1, tot = 0;
        for (int i = 1; i <= n; i++)
        {
            tot = tot + mk[i].v - dan[i].v;
            if (tot < 0)
            {
                ok = 0;
                break;
            }
        }
        cout << (ok == 1 ? "Yes\n" : "No\n");
        if (ok)
        {
            for (int i = 1; i <= n; i++)
            {
                cout << mk[i].id << " ";
            }
            cout << '\n';
            for (int i = 1; i <= n; i++)
            {
                cout << dan[i].id << " ";
            }
            cout << '\n';
        }
    }
    return 0;
}
// TAG: 贪心