#include <algorithm>
#include <iostream>
#include <set>
using namespace std;
set<int> s[3][1005][1005]; // s[a][b][c] a=0:x=b,y=c a=1:x=b,z=c a=2:y=b,z=c
int main()
{
    int n, q, res = 0;
    cin >> n >> q;
    while (q--)
    {
        int x, y, z;
        cin >> x >> y >> z;
        int pre = s[0][x][y].size();
        s[0][x][y].insert(z);
        res += ((int)s[0][x][y].size() == n && pre != n);
        pre = s[1][x][z].size();
        s[1][x][z].insert(y);
        res += ((int)s[1][x][z].size() == n && pre != n);
        pre = s[2][y][z].size();
        s[2][y][z].insert(x);
        res += ((int)s[2][y][z].size() == n && pre != n);
        cout << res << endl;
    }
    return 0;
}