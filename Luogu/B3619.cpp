#include <iostream>
using namespace std;
char ans[100], all[40] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
                          'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N',
                          'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
int main()
{
    int n, x, pos = 0;
    cin >> n >> x;
    while (n)
    {
        ans[++pos] = all[n % x];
        n /= x;
    }
    for (int i = pos; i > 0; i--)
    {
        cout << ans[i];
    }
    return 0;
}