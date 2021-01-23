#include <iostream>
#include <algorithm>
using namespace std;
int cows[20005];
int main()
{
    int n, b;
    cin >> n >> b;
    for (int i = 1; i <= n; i++)
    {
        cin >> cows[i];
    }
    sort(cows + 1, cows + 1 + n);
    int tot = 0;
    for (int i = n; i >= 1; i--)
    {
        tot += cows[i];
        if (tot > b)
        {
            cout << n - i + 1;
            return 0;
        }
    }
}