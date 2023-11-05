#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
int main()
{
    int n, cnt = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int num;
        cin >> num;
        if (num % 10 - num / 1000 - num / 10 % 10 - num / 100 % 10 > 0)
        {
            cnt += 1;
        }
    }
    cout << cnt << endl;
    return 0;
}