#include <algorithm>
#include <iostream>
using namespace std;
struct Game
{
    int st, ed;
};
bool cmp(Game x, Game y)
{
    return x.ed < y.ed;
}
Game g[1000005];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> g[i].st >> g[i].ed;
    }
    sort(g + 1, g + 1 + n, cmp);
    int ans = 0, now = 0;
    for (int i = 1; i <= n; i++)
    {
        if (now <= g[i].st)
        {
            ans++;
            now = g[i].ed;
        }
    }
    cout << ans << endl;
    return 0;
}