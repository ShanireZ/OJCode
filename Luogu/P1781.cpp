#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
struct ZT
{
    string p;
    int id;
};
ZT a[25];
bool cmp(ZT a, ZT b)
{
    if (a.p.size() == b.p.size())
    {
        return a.p < b.p;
    }
    return a.p.size() < b.p.size();
}
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].p;
        a[i].id = i;
    }
    sort(a + 1, a + 1 + n, cmp);
    cout << a[n].id << endl;
    cout << a[n].p << endl;
    return 0;
}