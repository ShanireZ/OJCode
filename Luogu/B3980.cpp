#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
using namespace std;
int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int tot = 0;
        for (int i = 1; i <= 128; i++)
        {
            string s;
            cin >> s;
            int l = 200, r = 0;
            for (int j = 1; j <= 128; j++)
            {
                if (s[j - 1] == '1')
                {
                    l = min(l, j), r = max(r, j);
                }
            }
            if (r != 0)
            {
                tot += r - l + 1;
            }
        }
        cout << sqrt(tot) << endl;
    }
    return 0;
}
// TAG: 洪水填充 FloodFill