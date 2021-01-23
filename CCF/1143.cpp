#include <iostream>
#include <algorithm>
using namespace std;
int cnt[1025][1025];
int main()
{
    int d, n;
    cin >> d >> n;
    for (int i = 0; i < n; i++)
    {
        int x, y, a;
        cin >> x >> y >> a;
        int startX = max(x - d, 0);
        int endX = min(x + d, 1024);
        int startY = max(y - d, 0);
        int endY = min(y + d, 1024);
        for (int j = startX; j <= endX; j++)
        {
            for (int k = startY; k <= endY; k++)
            {
                cnt[j][k] += a;
            }
        }
    }
    int maxT = 0, num = 1;
    for (int i = 0; i < 1025; i++)
    {
        for (int j = 0; j < 1025; j++)
        {
            if (cnt[i][j] > maxT)
            {
                num = 1;
                maxT = cnt[i][j];
            }
            else if (cnt[i][j] == maxT)
            {
                num++;
            }
        }
    }
    cout << num << " " << maxT;
    return 0;
}