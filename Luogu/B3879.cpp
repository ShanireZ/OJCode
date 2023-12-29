#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    long long n, k, ans = 0;
    cin >> n >> k;
    // 设x为sum/k，如果k为奇数，那么sum=kx；如果k为偶数，那么sum=(2x+1)(k/2)
    // 如果sum是完全平方数，那么sum的两个组成部分肯定一个是ab^2、另一个是ac^2 的形式
    long long hf = (k % 2 == 1 ? k : k / 2);
    for (long long i = 2; hf >= i * i; i++)
    {
        while (hf % (i * i) == 0)
        {
            hf /= i * i;
        }
    }
    if (k % 2 == 1) // sum=kx
    {
        for (long long i = 1;; i++)
        {
            long long x = i * i * hf;
            if (x + k / 2 > n) // 右边界检查
            {
                break;
            }
            else if (x - k / 2 >= 1) // 左边界检查
            {
                ans++;
            }
        }
    }
    else // sum=(2x+1)(k/2)
    {
        // 如果k/2中的的a是偶数，那么2x+1也为偶数
        // 但2x+1必为奇数，所以产生冲突此情况无解
        if (hf % 2 == 0)
        {
            cout << 0 << endl;
            return 0;
        }
        //  2x+1=ab^2且a为奇数2x+1也是奇数，所以b^2必须为奇数
        for (long long i = 1;; i += 2)
        {
            long long x = (i * i * hf - 1) / 2;
            if (x + k / 2 > n) // 右边界检查
            {
                break;
            }
            else if (x - k / 2 >= 0) // 左边界检查
            {
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
// TAG: 数论 完全平方数