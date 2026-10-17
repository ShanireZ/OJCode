#include <iomanip>
#include <iostream>
using namespace std;
int main()
{
    int tot = 0, n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int age;    //! 1.建立一個變數存當前這個人的年齡
        cin >> age; //! 2.輸入
        tot += age; //! 3.把當前這個人的年齡加入到總年齡裡
    }
    cout << fixed << setprecision(2) << 1.0 * tot / n << endl;
    return 0;
}