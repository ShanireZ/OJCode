#include <iostream>
using namespace std;
int main()
{
    int x, y;
    cin >> x >> y;
    cout << 60 * x + 40 * y - 10 * min(x, y) << endl;
    return 0;
}