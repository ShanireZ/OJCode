#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int w, f, a, r;
    cin >> w >> f >> a >> r;
    if (w < r)
    {
        cout << "Rejected" << endl;
        return 0;
    }
    if (1.0 * f / w > 0.2)
    {
        cout << "Rejected" << endl;
        return 0;
    }
    if (1.0 * a / w > 0.3)
    {
        cout << "Rejected" << endl;
        return 0;
    }
    cout << "Accepted" << endl;
    return 0;
}