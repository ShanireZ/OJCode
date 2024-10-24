#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
int T, n, p, ta[100005], ni[100005], cnt[5];
string s, ss;
int trans(char c)
{
    return (c == 'P') ? 1 : ((c == 'V') ? 2 : 3);
}
int main()
{
    cin >> T;
    while (T--)
    {
        cin >> n >> s >> ss;
        for (int i = 1; i <= n; i++)
        {
            ta[i] = trans(s[i - 1]), ni[i] = trans(ss[i - 1]);
        }
        cnt[1] = cnt[2] = cnt[3] = 0, p = n + 1;
        for (int i = 1; i <= n; i++)
        {
            cnt[ta[i]]++;
            if (cnt[1] == cnt[2] && cnt[2] == cnt[3])
            {
                p = -1;
                break;
            }
            cnt[ni[i]]++;
            if (cnt[1] == cnt[2] && cnt[2] == cnt[3])
            {
                p = i;
                break;
            }
        }
        if (p == -1)
        {
            cout << 0 << endl;
            continue;
        }
        cnt[1] = cnt[2] = cnt[3] = 0;
        int p321 = 0, p312 = 0, p231 = 0, p213 = 0, p132 = 0, p123 = 0;
        for (int i = 1; i <= n; i++)
        {
            cnt[ta[i]]++;
            if (((cnt[1] - cnt[2] == 1) && (cnt[2] - cnt[3] == 1) && p123 < p) ||
                ((cnt[1] - cnt[3] == 1) && (cnt[3] - cnt[2] == 1) && p132 < p) ||
                ((cnt[2] - cnt[1] == 1) && (cnt[1] - cnt[3] == 1) && p213 < p) ||
                ((cnt[2] - cnt[3] == 1) && (cnt[3] - cnt[1] == 1) && p231 < p) ||
                ((cnt[3] - cnt[1] == 1) && (cnt[1] - cnt[2] == 1) && p312 < p) ||
                ((cnt[3] - cnt[2] == 1) && (cnt[2] - cnt[1] == 1) && p321 < p))
            {
                // 如果ta出现了 x-1 x x+1 情况,对手也出现了这个情况,那么对手出现的位置必须在对手出现 x x x 之前
                // 此时修改对手出现 x-1 x x+1 的位置后至 x x x 之前的位置即可
                p = -1;
                break;
            }
            cnt[ni[i]]++;
            if (cnt[1] - cnt[2] == 1 && cnt[2] - cnt[3] == 1)
            {
                p123 = i;
            }
            else if (cnt[1] - cnt[3] == 1 && cnt[3] - cnt[2] == 1)
            {
                p132 = i;
            }
            else if (cnt[2] - cnt[1] == 1 && cnt[1] - cnt[3] == 1)
            {
                p213 = i;
            }
            else if (cnt[2] - cnt[3] == 1 && cnt[3] - cnt[1] == 1)
            {
                p231 = i;
            }
            else if (cnt[3] - cnt[1] == 1 && cnt[1] - cnt[2] == 1)
            {
                p312 = i;
            }
            else if (cnt[3] - cnt[2] == 1 && cnt[2] - cnt[1] == 1)
            {
                p321 = i;
            }
        }
        cout << ((p == -1) ? 1 : 2) << endl;
    }
    return 0;
}