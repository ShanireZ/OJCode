#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;
int a[65][65][3], b[65][65][3], c[65][65][3], w, h;
double ans;
int main()
{
    cin >> h >> w;
    for (int k = 0; k < 3; k++)
    {
        for (int i = 1; i <= h; i++)
        {
            for (int j = 1; j <= w; j++)
            {
                cin >> a[i][j][k];
            }
        }
    }
    for (int k = 0; k < 3; k++)
    {
        for (int i = 1; i <= h; i++)
        {
            for (int j = 1; j <= w; j++)
            {
                cin >> b[i][j][k];
                c[i][j][k] = a[i][j][k] - b[i][j][k];
                c[i][j][k] *= c[i][j][k];
                c[i][j][k] += c[i - 1][j][k] + c[i][j - 1][k] - c[i - 1][j - 1][k];
            }
        }
    }
    for (int l1 = (h + 1) / 2; l1 <= h; l1++)
    {
        for (int l2 = (w + 1) / 2; l2 <= w; l2++)
        {
            for (int i = 1; i + l1 - 1 <= h; i++)
            {
                for (int j = 1; j + l2 - 1 <= w; j++)
                {
                    double psnr = 0;
                    for (int k = 0; k < 3; k++)
                    {
                        psnr += c[i + l1 - 1][j + l2 - 1][k] - c[i - 1][j + l2 - 1][k] - c[i + l1 - 1][j - 1][k] + c[i - 1][j - 1][k];
                    }
                    psnr /= 3 * l1 * l2;
                    ans = max(ans, 20 * log10(255 / sqrt(psnr)));
                }
            }
        }
    }
    cout << fixed << setprecision(8) << ans << endl;
    return 0;
}