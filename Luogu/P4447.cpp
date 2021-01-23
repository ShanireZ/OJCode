#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
int num[100005];
map<int, int> t;
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> num[i];
        t[num[i]]++;
    }
    sort(num + 1, num + 1 + n);
    int x = unique(num + 1, num + 1 + n) - (num + 1);
    int ans = 0x3f3f3f3f;
    for (int i = 1; i <= x;)
    {
        while (t[num[i]] == 0 && i <= x)
        {
            i++;
        }
        if (i > x)
        {
            break;
        }
        int last = 1, pre = num[i], p = i + 1;
        t[num[i]]--;
        while (t[num[p]] > t[num[p - 1]] && num[p] - num[p - 1] == 1)
        {
            last++;
            t[num[p]]--;
            p++;
        }
        ans = min(ans, last);
    }
    cout << ans;
    return 0;
}