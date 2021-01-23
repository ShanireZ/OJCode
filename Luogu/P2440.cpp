#include <iostream>
using namespace std;
int woods[100005], n, m;
int findx(int l, int r)
{
    int mid = (l + r) >> 1;
    if (mid == 0)
    {
        return 1;
    }
    if (l == r)
    {
        return l;
    }
    int tot = 0;
    for (int i = 1; i <= n; i++)
    {
        tot += woods[i] / mid;
    }
    if (tot >= m)
    {
        return findx(mid + 1, r);
    }
    else
    {
        return findx(l, mid);
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> woods[i];
    }
    cout << findx(0, 100000000) - 1;
    return 0;
}