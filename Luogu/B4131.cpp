#include <cmath>
#include <iostream>
using namespace std;
// int a[10] = {0, 123, 1234, 2345, 3456, 4567, 5678, 6789};
int v[10] = {0, 6, 10, 14, 18, 22, 26, 30};
int main()
{
    int ans = 0;
    for (int i = 1; i <= 7; i++)
    {
        for (int j = 1; j <= 7; j++)
        {
            int x = sqrt(v[i] + v[j]);
            if (x * x == v[i] + v[j])
            {
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}