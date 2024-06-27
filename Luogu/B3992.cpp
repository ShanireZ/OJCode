#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int n, tot = 0, cnt = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        if (x % 10 != 3 && x % 3 != 0)
        {
            tot += x, cnt++;
        }
    }
    cout << tot << " " << cnt << endl;
    return 0;
}