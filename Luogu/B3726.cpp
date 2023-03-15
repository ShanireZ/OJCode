#include <iostream>
#include <string>
using namespace std;
string s[15];
int main()
{
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
    }
    for (int i = 1; i <= q; i++)
    {
        int opt, x, y, z;
        cin >> opt >> x;
        if (opt == 1)
        {
            cin >> y >> z;
            s[y].insert(z, s[x]);
        }
        else
        {
            cout << s[x] << "\n";
        }
    }
    return 0;
}