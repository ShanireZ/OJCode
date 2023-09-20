#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    long long n, m, p, q;
    cin >> n >> m >> p >> q;
    if (p * m + q < n * m)
    {
        cout << "Program ends with return value 0." << endl;
    }
    else
    {
        cout << "Segmentation fault." << endl;
    }
    return 0;
}