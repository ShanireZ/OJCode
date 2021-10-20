#include <iostream>
using namespace std;
int main()
{
    int a, n, m, x;
    cin >> a >> n >> m >> x;
    int ta = 2, tx = 1;
    int prea1 = 0, prex1 = 1;
    int prea2 = 1, prex2 = 0;
    for (int i = 1; i <= n - 5; i++)
    {
        int nowa = prea1 + prea2;
        int nowx = prex1 + prex2;
        ta += nowa, tx += nowx;
        prea2 = prea1, prea1 = nowa;
        prex2 = prex1, prex1 = nowx;
    }
    int ex = (m - a * ta) / tx;
    if (x == 1 || x == 2)
    {
        cout << a << endl;
    }
    else
    {
        int pre2 = a, pre1 = ex, tot = a;
        for (int i = 3; i <= x; i++)
        {
            tot += pre2;
            int now = pre2 + pre1;
            pre2 = pre1, pre1 = now;
        }
        cout << tot << endl;
    }
    return 0;
}