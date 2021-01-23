#include <iostream>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <limits>
using namespace std;
struct Node
{
    double x, y, dis[20];
    bool usd;
};
Node nodes[20];
int n;
double mintot, tot;
void dfs(int step, int from)
{
    if (step == n + 1)
    {
        mintot = min(mintot, tot);
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (nodes[i].usd == 0 && nodes[from].dis[i] + tot < mintot)
        {
            nodes[i].usd = 1;
            tot += nodes[from].dis[i];
            dfs(step + 1, i);
            nodes[i].usd = 0;
            tot -= nodes[from].dis[i];
        }
    }
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> nodes[i].x >> nodes[i].y;
        for (int j = 0; j <= i; j++)
        {
            nodes[i].dis[j] = nodes[j].dis[i] = sqrt((nodes[i].x - nodes[j].x) * (nodes[i].x - nodes[j].x) + (nodes[i].y - nodes[j].y) * (nodes[i].y - nodes[j].y));
        }
    }
    mintot = numeric_limits<double>::max();
    dfs(1, 0);
    cout << fixed << setprecision(2) << mintot;
    return 0;
}