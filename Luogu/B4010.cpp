#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int n, res = 0, rid = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int a, b;
        cin >> a >> b;
        double x = 1.0 * b / a;
        if (x > res)
        {
            res = x, rid = i;
        }
    }
    cout << rid << endl;
    return 0;
}