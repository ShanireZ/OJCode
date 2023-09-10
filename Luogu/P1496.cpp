#include <algorithm>
#include <iostream>
using namespace std;
struct Line
{
    int v, pos;
    bool operator<(const Line oth) const
    {
        return pos < oth.pos;
    }
};
Line lines[40005];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int a, b, p1 = i * 2 - 1, p2 = i * 2;
        cin >> a >> b;
        lines[p1].v = 1, lines[p2].v = -1;
        lines[p1].pos = a, lines[p2].pos = b;
    }
    sort(lines + 1, lines + 1 + n * 2);
    int tot = 0, ans = 0;
    for (int i = 1; i <= n * 2; i++)
    {
        if (tot)
        {
            ans += lines[i].pos - lines[i - 1].pos;
        }
        tot += lines[i].v;
    }
    cout << ans << "\n";
    return 0;
}