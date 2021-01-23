#include <iostream>
#include <algorithm>
using namespace std;
int a[10005];
int gcd(int a, int b)
{
    int r;
    while (b)
    {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}
int main()
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        int n;
        cin >> n;
        for (int j = 1; j <= n; j++)
        {
            //a[1]必然是分子  a[2]必然是分母  其他数都可以是分子
            cin >> a[j];
        }
        swap(a[1], a[2]); //将分母换到a[1]中 如果a[1]被约分为1 那么就是整数
        for (int j = 2; j <= n; j++)
        {
            int r = gcd(a[1], a[j]);
            if (a[1] % r == 0)
            {
                a[1] /= r;
            }
            if (a[1] == 1)
            {
                cout << "Yes" << endl;
                break;
            }
            if (j == n)
            {
                cout << "No" << endl;
            }
        }
    }
    return 0;
}