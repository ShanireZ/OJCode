#include <iostream>
using namespace std;
int n, fx, fy, ans, st, ed;
bool check(int a, int b)
{
    if (a == fx && b == fy)
    {
        cout << ans << endl;
        return true;
    }
    return false;
}
int main()
{
    cin >> n >> fx >> fy;
    ans = 1, st = 1, ed = n;
    for (int i = 1; i <= n / 2; i++)
    {
        if (st == fx || ed == fx || st == fy || ed == fy)
        {
            break;
        }
        ans += (ed - st) * 4;
        st++, ed--;
    }
    int i = st, j = st;
    while (j <= ed) //右
    {
        if (check(i, j))
        {
            return 0;
        }
        ans++, j++;
    }
    i++, j--;
    while (i <= ed) //下
    {
        if (check(i, j))
        {
            return 0;
        }
        ans++, i++;
    }
    i--, j--;
    while (j >= st) //左
    {
        if (check(i, j))
        {
            return 0;
        }
        ans++, j--;
    }
    i--, j++;
    while (i >= st) //上
    {
        if (check(i, j))
        {
            return 0;
        }
        ans++, i--;
    }
    return 0;
}