#include <algorithm>
#include <iostream>
using namespace std;
int t[200005], h[200005], rec[200005], n, d;
int main()
{
    cin >> n >> d;
    for (int i = 1; i <= n; i++) // 编号和日期都+1 方便统一处理不用特判和额外日期加一
    {
        cin >> t[i];
        h[i] = (t[i] < t[i - 1] ? 0 : 1e9);
    }
    for (int i = 1; i <= d; i++)
    {
        char opt;
        int r, x;
        cin >> opt >> r;
        r++;
        if (opt == '!')
        {
            cin >> x;
            t[r] = x;
            rec[r] += max(0, i - h[r]);
            h[r] = (t[r] < t[r - 1] ? i : 1e9);
            rec[r + 1] += max(0, i - h[r + 1]);
            h[r + 1] = (t[r + 1] < t[r] ? i : 1e9);
        }
        else
        {
            cout << rec[r] + max(0, i - h[r]) << endl;
        }
    }
    return 0;
}