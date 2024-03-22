#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    long long xmin = 1e9, xmax = -1e9, ymin = 1e9, ymax = -1e9, n;
    cin >> n;
    while (n--)
    {
        long long x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        xmin = min(xmin, min(x1, x2));
        xmax = max(xmax, max(x1, x2));
        ymin = min(ymin, min(y1, y2));
        ymax = max(ymax, max(y1, y2));
    }
    cout << (xmax - xmin) * (ymax - ymin) << endl;
    return 0;
}