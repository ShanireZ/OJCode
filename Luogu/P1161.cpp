#include <iostream>
using namespace std;
int main()
{
    int n, sum = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) //*一个数异或同一个数两次 这个数没有变化
    {
        double a;
        int t;
        cin >> a >> t;
        for (int j = 1; j <= t; j++)
        {
            int id = a * j;
            sum = sum ^ id;
        }
    }
    cout << sum;
    return 0;
}