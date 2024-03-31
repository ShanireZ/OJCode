#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
struct XS
{
    int id, f;
};
XS a[5005];
bool cmp(XS a, XS b)
{
    if(a.f == b.f)
    {
        return a.id < b.id;
    }
    return a.f > b.f;
}
int main()
{
    int n, m;
    cin >> n >> m;
    m = 1.5 * m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].id >> a[i].f;
    }
    sort(a + 1, a + 1 + n, cmp);
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i].f >= a[m].f)
        {
            cnt++;
        }
    }
    cout << a[m].f << " " << cnt << endl;
    for (int i = 1; i <= cnt; i++)
    {
        cout << a[i].id << " " << a[i].f << endl;
    }
    return 0;
}