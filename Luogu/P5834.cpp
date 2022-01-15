#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int main()
{
    long long n;
    cin >> n;
    long long nums[10] = {-1, 1, 2, 4, 7, 8, 11, 13};
    long long t = n / 8;
    n %= 8;
    cout << t * 15 + nums[n] << endl;
    return 0;
}