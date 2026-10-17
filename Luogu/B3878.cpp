#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    long long n, k, ans = 0;
    cin >> n >> k;
    // 設x為sum/k，如果k為奇數，那麼sum=kx；如果k為偶數，那麼sum=(2x+1)(k/2)
    // 如果sum是完全平方數，那麼sum的兩個組成部分肯定一個是ab^2、另一個是ac^2 的形式
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
            if (x + k / 2 > n) // 右邊界檢查
            {
                break;
            }
            else if (x - k / 2 >= 1) // 左邊界檢查
            {
                ans++;
            }
        }
    }
    else // sum=(2x+1)(k/2)
    {
        // 如果k/2中的的a是偶數，那麼2x+1也為偶數
        // 但2x+1必為奇數，所以產生衝突此情況無解
        if (hf % 2 == 0)
        {
            cout << 0 << endl;
            return 0;
        }
        //  2x+1=ab^2且a為奇數2x+1也是奇數，所以b^2必須為奇數
        for (long long i = 1;; i += 2)
        {
            long long x = (i * i * hf - 1) / 2;
            if (x + k / 2 > n) // 右邊界檢查
            {
                break;
            }
            else if (x - k / 2 >= 0) // 左邊界檢查
            {
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}