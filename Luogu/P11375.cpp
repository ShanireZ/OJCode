#include <algorithm>
#include <iostream>
using namespace std;
string str, fn;
int main()
{
    long long n, s;
    cin >> n >> s >> str;
    int cu = 0;
    for (int i = str.size() - 1; i >= 0; i--)
    {
        if (str[i] == 'U')
        {
            cu++;
        }
        else if (cu)
        {
            cu--;
        }
        else
        {
            fn += str[i];
        }
    }
    s = max(1ll, s >> cu);
    for (int i = fn.size() - 1; i >= 0; i--)
    {
        s = (s << 1) + (fn[i] == 'R');
    }
    cout << s << endl;
    return 0;
}