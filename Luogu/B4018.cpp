#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int w1, c1, t1, w2, c2, t2;
    cin >> w1 >> c1 >> t1 >> w2 >> c2 >> t2;
    if (w1 > w2 || (w1 == w2 && c1 > c2) || (w1 == w2 && c1 == c2 && t1 < t2))
    {
        cout << "A" << endl;
    }
    else
    {
        cout << "B" << endl;
    }
    return 0;
}