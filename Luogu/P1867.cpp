#include <cmath>
#include <iostream>
using namespace std;
int main()
{
    int lv = 0, ex = 0, n;
    double hp = 10;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        double x;
        int a;
        cin >> x >> a;
        hp -= x;
        hp = min(hp, 10.0);
        if (hp <= 0)
        {
            break;
        }
        ex += a;
    }
    int now = 1;
    while (true)
    {
        if (ex < now)
        {
            break;
        }
        lv += 1;
        ex -= now;
        now *= 2;
    }
    cout << lv << " " << ex << endl;
    return 0;
}