#include <algorithm>
#include <iostream>
#include <unordered_map>
using namespace std;
unordered_map<int, int> qx[200005];
int ad[200005], n, m, q;
int main()
{
    cin >> n >> m >> q;
    while (q--)
    {
        int op, x, y;
        cin >> op >> x;
        if (op == 1)
        {
            cin >> y;
            qx[x][y] = 1;
        }
        else if (op == 2)
        {
            ad[x] = 1;
        }
        else
        {
            cin >> y;
            cout << ((ad[x] || qx[x][y]) ? "Yes" : "No") << endl;
        }
    }
    return 0;
}