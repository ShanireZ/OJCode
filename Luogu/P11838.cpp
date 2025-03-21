#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int T, n, k, a[105];
vector<pair<int, int>> p;
bool check1(int l, int r)
{
    for (int i = l + 1; i <= r; i++)
    {
        if (a[i] != a[i - 1])
        {
            return false;
        }
    }
    return true;
}
bool check2(int l, int r)
{
    p.clear();
    for (int i = l; i <= r; i++)
    {
        if (i == l || a[i] != a[i - 1])
        {
            p.emplace_back(make_pair(a[i], 1));
            continue;
        }
        p.back().second++;
    }
    if (p.size() == 1 || p.size() % 2 == 0)
    {
        for (int i = 0; i + 2 < (int)p.size(); i++)
        {
            if (p[i] != p[i + 2])
            {
                return false;
            }
        }
        return true;
    }
    return false;
}
bool check3(int l, int r)
{
    for (int len = 1; l + len - 1 <= r; len++)
    {
        int ok = ((r - l + 1) % len == 0);
        for (int i = l + len; i <= r && ok; i++)
        {
            if (a[i] != a[i - len])
            {
                ok = 0;
            }
        }
        if (ok == 0)
        {
            continue;
        }
        for (int i = l; i < l + len; i++)
        {
            if ((check1(l, i) && check2(i + 1, l + len - 1)) ||
                (check2(l, i) && check1(i + 1, l + len - 1)))
            {
                return true;
            }
        }
    }
    return false;
}
int main()
{
    cin >> T;
    while (T--)
    {
        cin >> n >> k;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        if (k == 1)
        {
            cout << (check1(1, n) ? "YES" : "NO") << endl;
        }
        else if (k == 2)
        {
            cout << (check2(1, n) ? "YES" : "NO") << endl;
        }
        else
        {
            cout << (check3(1, n) ? "YES" : "NO") << endl;
        }
    }
    return 0;
}