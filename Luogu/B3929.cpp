#include <algorithm>
#include <iostream>
#include <set>
using namespace std;
set<int> lk;
int main()
{
    int a, n;
    cin >> a >> n;
    for (int i = 1; i <= 1001; i++)
    {
        int now = i * i;
        while (now >= a && now <= 1001 * 1001)
        {
            lk.insert(now);
            now += i * i;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        auto p = lk.lower_bound(x);
        if (*p == x)
        {
            cout << "lucky" << endl;
        }
        else
        {
            cout << *p << endl;
        }
    }
    return 0;
}