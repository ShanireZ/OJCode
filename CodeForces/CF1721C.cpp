#include <algorithm>
#include <iostream>
#include <set>
using namespace std;
int a[200005], ans[200005];
multiset<int> b;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        b.clear();
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        for (int i = 1; i <= n; i++)
        {
            int x;
            cin >> x;
            b.insert(x);
        }
        for (int i = 1; i <= n; i++)
        {
            cout << *b.lower_bound(a[i]) - a[i] << " ";
        }
        cout << endl;
        for (int i = n; i >= 1; i--) // 最大值為和現有最大可用的差
        {
            ans[i] = *(--b.end()) - a[i];
            b.erase(b.lower_bound(a[i])); // 每次去掉當前數的後繼 使影響最小
        }
        for (int i = 1; i <= n; i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}