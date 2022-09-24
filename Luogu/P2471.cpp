#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
int n, m, st[50005][20], y[50005], r[50005];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> y[i] >> r[i];
        st[i][0] = i; // 区间降雨量最大的年份(相同取年份较小的)
    }
    int len = 2, half = 1;
    for (int x = 1; x <= log2(n); x++)
    {
        for (int i = 1; i + len - 1 <= n; i++)
        {
            int a = st[i][x - 1], b = st[i + half][x - 1];
            st[i][x] = (r[a] >= r[b]) ? a : b;
        }
        len *= 2, half *= 2;
    }
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        int b, a;
        cin >> b >> a;
        int pb = lower_bound(y + 1, y + 1 + n, b) - y;
        int pa = lower_bound(y + 1, y + 1 + n, a) - y;
        if (y[pa] != a) // a年不存在
        {
            if (y[pb] != b || pa - 1 == pb) // b年也不存在 或者 b年存在但a年前无其他数据
            {
                cout << "maybe" << endl;
                continue;
            }
            int x = log2(pa - 1 - pb);
            int len = pow(2, x);
            int p1 = st[pb + 1][x], p2 = st[pa - len][x];
            int ans = (r[p1] >= r[p2]) ? p1 : p2;
            if (r[ans] >= r[pb]) // 如果 a年前已经有比b年更大的,那么a年肯定比b年大
            {
                cout << "false" << endl;
            }
            else
            {
                cout << "maybe" << endl;
            }
        }
        else if (y[pb] != b) // 如果a年存在b年不存在
        {
            int x = log2(pa - pb + 1);
            int len = pow(2, x);
            int p1 = st[pb][x], p2 = st[pa - len + 1][x];
            int ans = (r[p1] >= r[p2]) ? p1 : p2;
            if (ans == pa) // a年在范围内最大
            {
                cout << "maybe" << endl;
            }
            else
            {
                cout << "false" << endl;
            }
        }
        else
        {
            if (r[pa] > r[pb])
            {
                cout << "false" << endl;
                continue;
            }
            int x = log2(pa - pb);
            int len = pow(2, x);
            int p1 = st[pb + 1][x], p2 = st[pa - len + 1][x];
            int ans = (r[p1] >= r[p2]) ? p1 : p2;
            if (ans == pa)
            {
                if (pa - pb == a - b)
                {
                    cout << "true" << endl;
                }
                else
                {
                    cout << "maybe" << endl;
                }
            }
            else
            {
                cout << "false" << endl;
            }
        }
    }
    return 0;
}