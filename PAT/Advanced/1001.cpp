#include <iostream>
#include <sstream>
#include <string>
using namespace std;
int main() // a+b求和，答案每三位一逗号
{
    int a, b;
    cin >> a >> b;
    a = a + b;
    string ans;
    stringstream t;
    t << a;
    t >> ans;
    for (int i = ans.size() - 3; i > 0 && ans[i - 1] != '-'; i -= 3)
    {
        ans.insert(i, ",");
    }
    cout << ans;
    return 0;
}