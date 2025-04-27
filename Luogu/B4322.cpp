#include <algorithm>
#include <iostream>
using namespace std;
string str;
int main()
{
    int t, n, x, y, op;
    cin >> t;
    while (t--)
    {
        cin >> op;
        if (op == 0)
        {
            cin >> n >> x >> y; // x决定AB/CD，y决定具体前后选择
            int lx = 1, rx = (1 << n), ly = 1, ry = (1 << n);
            while (lx < rx)
            {
                int mx = (lx + rx) / 2, my = (ly + ry) / 2;
                cout << (x <= mx ? (y <= my ? "A" : "B") : (y <= my ? "C" : "D"));
                x <= mx ? rx = mx : lx = mx + 1;
                y <= my ? ry = my : ly = my + 1;
            }
        }
        else
        {
            cin >> str;
            n = str.size();
            int lx = 1, rx = (1 << n), ly = 1, ry = (1 << n);
            for (char ch : str)
            {
                int mx = (lx + rx) / 2, my = (ly + ry) / 2;
                (ch == 'A' || ch == 'B') ? rx = mx : lx = mx + 1; // AB前方行
                (ch == 'A' || ch == 'C') ? ry = my : ly = my + 1; // AC前方列
            }
            cout << n << " " << lx << " " << ly;
        }
        cout << endl;
    }
    return 0;
}