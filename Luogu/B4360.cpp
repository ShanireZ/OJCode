#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int h, w, x1, x2, y1, y2;
    cin >> h >> w >> x1 >> x2 >> y1 >> y2;
    for (int i = 1; i <= h; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            char ch;
            cin >> ch;
            if (i >= x1 && i <= x2 && j >= y1 && j <= y2)
            {
                cout << ch;
            }
        }
        if (i >= x1 && i <= x2)
        {
            cout << endl;
        }
    }
    return 0;
}