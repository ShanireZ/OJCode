#include <algorithm>
#include <iostream>
using namespace std;
int ans[500005];
struct Fish
{
    long long g, id;
};
Fish fs[500005];
bool cmpg(Fish a, Fish b)
{
    return a.g < b.g;
}
bool cmpid(Fish a, Fish b)
{
    return a.id < b.id;
}
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> fs[i].g;
        fs[i].id = i;
    }
    sort(fs + 1, fs + 1 + n, cmpg);
    int l = 1, r = n;
    while (l <= r)
    {
        int mid = (l + r) / 2, ok = 1;
        long long tot = fs[mid].g;
        for (int i = 1; i <= n; i++)
        {
            if (i != mid && fs[i].g < tot)
            {
                tot += fs[i].g;
            }
            else if (i != mid && fs[i].g >= tot)
            {
                ok = 0;
                break;
            }
        }
        ok ? (r = mid - 1) : (l = mid + 1);
    }
    for (int i = l; i <= n; i++)
    {
        ans[fs[i].id] = 1;
    }
    sort(fs + 1, fs + 1 + n, cmpid);
    for (int i = 1; i <= n; i++)
    {
        cout << (ans[i] ? 'T' : 'N');
    }
    return 0;
}