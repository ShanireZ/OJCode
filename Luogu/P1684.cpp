#include <algorithm>
#include <iostream>
#include <map>
#include <set>
using namespace std;
map<int, int> t;
int a[4005], lst = 1, n, ans, cnt;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        t[a[i]]++;
        if (t[a[i]] == 2 || t[a[i]] == 4)
        {
            cnt++;
            if (cnt == 2)
            {
                ans++, cnt = 0;
                for (int j = lst; j <= i; j++)
                {
                    t[a[j]] = 0;
                }
                lst = i + 1;
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
// TAG: DP 贪心