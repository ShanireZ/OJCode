#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int n, m;
int grounds[105];
struct Cow
{
    int g1, g2;
};
Cow cows[155];
int main()
{
    freopen("revegetate.in", "r", stdin);
    freopen("revegetate.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;
        cows[i].g1 = min(a, b);
        cows[i].g2 = max(a, b);
    }
    for (int i = 1; i <= n; i++)
    {
        int type;
        for (type = 1; type <= 4; type++)
        {
            int trig = 1;
            for (int j = 1; j <= m; j++)
            {
                if (cows[j].g2 == i && grounds[cows[j].g1] == type)
                {
                    trig = 0;
                    break;
                }
            }
            if (trig)
            {
                grounds[i] = type;
                cout << type;
                break;
            }
        }
    }
    return 0;
}