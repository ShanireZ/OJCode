#include <iostream>
using namespace std;
int main()
{
    int n, sum = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) //*一個數異或同一個數兩次 這個數沒有變化
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