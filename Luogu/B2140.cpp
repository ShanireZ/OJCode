#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int n, ca = 0, cb = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x = i, c0 = 0, c1 = 0;
        while (x != 0)
        {
            x % 2 == 0 ? c0++ : c1++;
            x /= 2;
        }
        c1 > c0 ? ca++ : cb++;
    }
    cout << ca << " " << cb << endl;
    return 0;
}