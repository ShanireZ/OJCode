#include <bits/stdc++.h>
using namespace std;
int main()
{
    int m, n, k, l, d;
    cin >> m >> n >> k >> l >> d;
    int a[m][2], b[n][2], c[2]; //c為交換陣列
    int r[k], t[l];             //r t輸出用
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    memset(c, 0, sizeof(c));
    memset(r, 0, sizeof(r));
    memset(t, 0, sizeof(t));
    int x, y, p, q;
    for (int i = 0; i < d; i++) //讀入&計數排序
    {
        cin >> x >> y >> p >> q;
        if (x == p)
        {
            if (y > q)
            {
                b[q][1]++;
                b[q][0] = q;
            }
            else
            {
                b[y][1]++;
                b[y][0] = y;
            }
        }
        else if (y == q)
        {
            if (x > p)
            {
                a[p][1]++;
                a[p][0] = p;
            }
            else
            {
                a[x][1]++;
                a[x][0] = x;
            }
        }
    }
    int j;
    for (int i = 0; i < m; i = j) //從大至小將最優情況排序
    {
        j = i + 1;
        while (i >= 1)
        {
            if (a[i - 1][1] < a[i][1])
            {
                memcpy(c, a[i - 1], sizeof(c));
                memcpy(a[i - 1], a[i], sizeof(c));
                memcpy(a[i], c, sizeof(c));
                i--;
            }
            else
            {
                break;
            }
        }
    }
    for (int i = 0; i < n; i = j)
    {
        j = i + 1;
        while (i >= 1)
        {
            if (b[i - 1][1] < b[i][1])
            {
                memcpy(c, b[i - 1], sizeof(c));
                memcpy(b[i - 1], b[i], sizeof(c));
                memcpy(b[i], c, sizeof(c));
                i--;
            }
            else
            {
                break;
            }
        }
    }
    for (int i = 0; i < k; i++) //將最優結果寫入輸出陣列中
    {
        r[i] = a[i][0];
    }
    for (int i = 0; i < l; i++)
    {
        t[i] = b[i][0];
    }
    sort(r, r + k);
    sort(t, t + l);
    for (int i = 0; i < k; i++) //輸出
    {
        cout << r[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < l; i++)
    {
        cout << t[i] << " ";
    }
    return 0;
}