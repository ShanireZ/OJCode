#include <algorithm>
#include <iostream>
using namespace std;
bool check(int x)
{
    while (x)
    {
        if (x % 10 == 3 || x % 10 == 7)
        {
            return false;
        }
        x /= 10;
    }
    return true;
}
int main()
{
    int n, cnt = 0;
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        for (int j = i + 1; i + j < n; j++)
        {
            int k = n - i - j;
            if (j < k && check(k) && check(i) && check(j))
            {
                cnt++;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}