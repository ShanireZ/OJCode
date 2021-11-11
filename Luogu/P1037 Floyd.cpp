#include <iostream>
#include <string>
#include <cmath>
#include <sstream>
using namespace std;
string multi(string a, string b)
{
    int x[35] = {0}, y[35] = {0}, z[35] = {0};
    for (int i = 0; i < a.size(); i++)
    {
        x[i] = a[i] - '0';
    }
    for (int i = 0; i < b.size(); i++)
    {
        y[i] = b[i] - '0';
    }
    int st = 0;
    for (int i = a.size() - 1; i >= 0; i--)
    {
        for (int j = b.size() - 1; j >= 0; j--)
        {
            int ans = x[i] * y[j];
            int p = a.size() - i - 1 + b.size() - j - 1;
            while (ans)
            {
                st = max(st, p);
                z[p] += ans % 10;
                ans /= 10;
                p++;
            }
        }
    }
    string c;
    for (int i = st; i >= 0; i--)
    {
        c += z[i] + '0';
    }
    return c;
}
int d[15][15];
int main()
{
    string n;
    int k;
    cin >> n >> k;
    for (int i = 1; i <= k; i++)
    {
        int x, y;
        cin >> x >> y;
        d[x][y] = 1;
    }
    for (int i = 0; i < 10; i++)
    {
        d[i][i] = 1;
    }
    for (int k = 0; k < 10; k++)
    {
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                if (d[i][k] + d[k][j] == 2)
                {
                    d[i][j] = 1;
                }
            }
        }
    }
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            d[i][10] += d[i][j];
        }
    }
    string ans = "1";
    for (int i = 0; i < n.size(); i++)
    {
        int now = n[i] - '0';
        string t;
        stringstream ss;
        ss << d[now][10];
        ss >> t;
        ans = multi(t, ans);
    }
    cout << ans << endl;
    return 0;
}