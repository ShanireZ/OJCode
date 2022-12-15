#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
long long trans10(string s, long long base)
{
    long long sum = 0;
    for (int i = 0; i < int(s.size()); i++)
    {
        sum = sum * base + ((s[i] >= '0' && s[i] <= '9') ? s[i] - '0' : s[i] - 'a' + 10);
    }
    return sum;
}
int main() // 进制转换+枚举+二分，需要注意n2二分的上下界
{
    string n1, n2;
    long long tag, radix;
    cin >> n1 >> n2 >> tag >> radix;
    if (tag == 2)
    {
        swap(n1, n2);
    }
    long long t1 = trans10(n1, radix);
    char maxc = *max_element(n2.begin(), n2.end()); // C++17
    long long l = max(2, (maxc <= '9') ? maxc - '0' + 1 : maxc - 'a' + 11);
    long long r = max(t1, l);
    while (l <= r)
    {
        long long mid = (l + r) / 2;
        long long t2 = trans10(n2, mid);
        if (t1 == t2)
        {
            cout << mid;
            return 0;
        }
        else if (t2 > t1 || t2 < 0)
        {
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    cout << "Impossible";
    return 0;
}