#include <algorithm>
#include <iostream>
using namespace std;
int n, pre, now;
int main()
{
    cin >> n >> pre;
    for (int i = 2; i <= n; i++)
    {
        cin >> now;
        if (now <= pre)
        {
            cout << "No" << endl;
            return 0;
        }
        pre = now;
    }
    cout << "Yes" << endl;
    return 0;
}