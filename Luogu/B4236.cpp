#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    // 末尾0的个数取决于1~n的因数中有多少对2*5
    // 因数2的个数必然多于5的个数,所以只需要统计因数中5的个数即可
    // 1~n中5的倍数有n/5个,25的倍数有n/25个,125的倍数有n/125个...
    long long n, ans = 0;
    cin >> n;
    for (long long i = 5; i <= n; i *= 5)
    {
        ans += n / i;
    }
    cout << ans << endl;
    return 0;
}