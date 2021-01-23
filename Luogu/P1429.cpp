#include <iostream>
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <cstdlib>
using namespace std;
//将原点按角θ旋转
//x' = xcosθ - ysinθ
//y' = xsinθ + ycosθ
struct Node
{
    double x, y;
};
Node ns[200005];
bool cmp(Node a, Node b)
{
    return a.x < b.x;
}
int main()
{
    srand(601709);
    double rnd = rand();
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x, y;
        cin >> x >> y;
        ns[i].x = x * cos(rnd) - y * sin(rnd);
        ns[i].y = x * sin(rnd) + y * cos(rnd);
    }
    sort(ns + 1, ns + 1 + n, cmp);
    double mind = 2e9;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= i + 7 && j <= n; j++) //保险起见5~10都可
        {
            double dis = sqrt(pow(ns[i].x - ns[j].x, 2) + pow(ns[i].y - ns[j].y, 2));
            mind = min(dis, mind);
        }
    }
    cout << fixed << setprecision(4) << mind;
    return 0;
}