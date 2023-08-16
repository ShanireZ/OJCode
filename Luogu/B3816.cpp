#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    long long n, c, maxa = 0;
    cin >> n >> c;
    long long mint = maxa + c * n, pos = 0;
    for (int i = 1; i <= n; i++)
    {
        long long x;
        cin >> x;
        maxa = max(maxa, x);
        long long t = maxa + c * (n - i);
        if (t < mint)
        {
            mint = t, pos = i;
        }
    }
    cout << pos << " " << mint << endl;
    return 0;
}