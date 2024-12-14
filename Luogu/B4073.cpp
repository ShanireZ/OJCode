#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int w, x;
    cin >> w >> x;
    int cnt = (w - 500 + 499) / 500;
    int ex[6] = {0, 4, 6, 9, 10, 17};
    cout << 20 + ex[x] * cnt << endl;
    return 0;
}