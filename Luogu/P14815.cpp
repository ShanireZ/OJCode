#include <algorithm>
#include <iostream>
using namespace std;
long long n, c, p, q, now, sum, npos, val[500005], sel[500005];
int main()
{
    cin >> n >> c >> p >> q;
    for (int i = 1; i <= n; i++)
    {
        char ch;
        cin >> ch;
        sum += (ch == 'Y');
        val[i] = sum * q - i * p;
    }
    sel[++npos] = 0;
    for (int i = 1; i <= n; i++)
    {
        if (val[i] < val[sel[npos]])
        {
            sel[++npos] = i;
        }
        int l = 1, r = npos;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (val[sel[mid]] > val[i])
            {
                l = mid + 1;
            }
            else if (i - sel[mid] < c)
            {
                r = mid - 1;
            }
            else
            {
                now++, npos = 0;
                sel[++npos] = i;
                break;
            }
        }
    }
    cout << now << endl;
    return 0;
}