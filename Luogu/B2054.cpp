#include <iomanip>
#include <iostream>
using namespace std;
int main()
{
    int tot = 0, n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int age;    //! 1.建立一个变量存当前这个人的年龄
        cin >> age; //! 2.输入
        tot += age; //! 3.把当前这个人的年龄加入到总年龄里
    }
    cout << fixed << setprecision(2) << 1.0 * tot / n << endl;
    return 0;
}