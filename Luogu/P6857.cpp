#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        //! 半欧拉图 只有0个或2个奇点
        long long n, tot;
        cin >> n;
        if (n % 2 == 1)
        {
            tot = n * (n - 1); //!没有奇点 n个点*n-1条边
        }
        else
        {
            tot = 2 * (n - 1) + (n - 2) * (n - 2); //! 2个奇点*n-1条边 n-2个偶点*n-2条边
        }
        cout << tot / 2 << endl;
    }
    return 0;
}