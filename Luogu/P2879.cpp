#include <algorithm>
#include <iostream>
using namespace std;
struct Area
{
    int a, b;
    bool operator<(const Area na) const
    {
        return (a == na.a) ? b < na.b : a < na.a;
    }
};
Area as[10005];
int cf[10005];
int main()
{
    int n, x, h, r;
    cin >> n >> x >> h >> r;
    for (int i = 1; i <= r; i++)
    {
        cin >> as[i].a >> as[i].b;
        if (as[i].a > as[i].b)
        {
            swap(as[i].a, as[i].b);
        }
    }
    sort(as + 1, as + 1 + r);
    for (int i = 1; i <= r; i++)
    {
        if (as[i].a == as[i - 1].a && as[i].b == as[i - 1].b)
        {
            continue;
        }
        cf[as[i].a + 1]++;
        cf[as[i].b]--;
    }
    for (int i = 1; i <= n; i++)
    {
        cf[i] += cf[i - 1];
        cout << h - cf[i] << endl;
    }
    return 0;
}