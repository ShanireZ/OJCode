#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int n;
    cin >> n;
    if (n < 9)
    {
        cout << -1 << endl;
        return 0;
    }
    cout << n << endl;
    for (int i = 1; i <= 6; i++) //直径 4是直径重心
    {
        cout << i << " " << i + 1 << endl;
    }
    int root = 3;
    for (int i = 8; i <= n; i++) //重心设为3 5亦可
    {
        cout << root << " " << i << endl;
    }
    return 0;
}