#include <iomanip>
#include <iostream>
using namespace std;
int main()
{
    double t;
    int n;
    cin >> t >> n;
    cout << fixed << setprecision(3) << t / n << endl;
    cout << n * 2 << endl;
    return 0;
}