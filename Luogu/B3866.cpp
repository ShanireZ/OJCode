#include <algorithm>
#include <iostream>
using namespace std;
int ns[10];
int main()
{
    int n, cnt = 0;
    cin >> n;
    while (n != 495)
    {
        ns[1] = n / 100, ns[2] = n / 10 % 10, ns[3] = n % 10;
        sort(ns + 1, ns + 4);
        n = (ns[3] * 100 + ns[2] * 10 + ns[1]) - (ns[1] * 100 + ns[2] * 10 + ns[3]);
        cnt++;
    }
    cout << cnt << endl;
    return 0;
}