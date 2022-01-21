#include <iostream>
using namespace std;
int hz[105][5];
int main()
{
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    for (int i = 1; i <= x; i++)
    {
        cin >> hz[i][0] >> hz[i][1] >> hz[i][2] >> hz[i][3];
    }
    for (int i = 1; i <= y; i++)
    {
        int last = 0, t = 0, a, b;
        cin >> a >> b;
        for (int j = 1; j <= x; j++)
        {
            if (a >= hz[j][0] && a <= hz[j][2] && b >= hz[j][1] && b <= hz[j][3])
            {
                last = j;
                t++;
            }
        }
        if (last)
        {
            cout << "Y " << t << " " << last << endl;
        }
        else
        {
            cout << "N" << endl;
        }
    }
    return 0;
}