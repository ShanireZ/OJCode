#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
using namespace std;
struct Road
{
    string type;
    int a, b;
};
Road roads[105];
int main()
{
    freopen("traffic.in", "r", stdin);
    freopen("traffic.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> roads[i].type >> roads[i].a >> roads[i].b;
    }
    int left = -999999, right = 999999;
    for (int i = n; i >= 1; i--)
    {
        if (roads[i].type == "none")
        {
            left = max(left, roads[i].a);
            right = min(right, roads[i].b);
        }
        else if (roads[i].type == "off")
        {
            left += roads[i].a;
            right += roads[i].b;
        }
        else
        {
            left = max(0, left - roads[i].b);
            right -= roads[i].a;
        }
    }
    cout << left << " " << right << endl;

    left = -999999, right = 999999;
    for (int i = 1; i <= n; i++)
    {
        if (roads[i].type == "none")
        {
            left = max(left, roads[i].a);
            right = min(right, roads[i].b);
        }
        else if (roads[i].type == "on")
        {
            left += roads[i].a;
            right += roads[i].b;
        }
        else
        {
            left = max(0, left - roads[i].b);
            right -= roads[i].a;
        }
    }
    cout << left << " " << right;
    return 0;
}