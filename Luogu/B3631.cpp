#include <algorithm>
#include <iostream>
using namespace std;
struct Node
{
    int pre, aft;
};
Node ns[1000005];
int main()
{
    int q;
    cin >> q;
    ns[1].pre = 0, ns[1].aft = 0;
    while (q--)
    {
        int op, x, y;
        cin >> op >> x;
        if (op == 1)
        {
            cin >> y;
            ns[y].pre = x, ns[y].aft = ns[x].aft;
            ns[x].aft = y;
        }
        else if (op == 2)
        {
            cout << ns[x].aft << endl;
        }
        else
        {
            int r = ns[ns[x].aft].aft;
            ns[x].aft = r, ns[r].pre = x;
        }
    }
    return 0;
}