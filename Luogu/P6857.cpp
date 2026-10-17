#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        //! 半歐拉圖 只有0個或2個奇點
        long long n, tot;
        cin >> n;
        if (n % 2 == 1)
        {
            tot = n * (n - 1); //!沒有奇點 n個點*n-1條邊
        }
        else
        {
            tot = 2 * (n - 1) + (n - 2) * (n - 2); //! 2個奇點*n-1條邊 n-2個偶點*n-2條邊
        }
        cout << tot / 2 << endl;
    }
    return 0;
}