#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
string ans[1005];
string plus_string(string a, string b)
{
    string result;
    if (a.size() < b.size()) //使a长度>=b长度
    {
        swap(a, b);
    }
    b.insert(0, a.size() - b.size(), '0'); //位数少的b前方补0
    bool next = false;                     //是否进位
    for(int pos = a.size() - 1; pos >= 0; pos--)
    {
        int temp = (a[pos] - '0') + (b[pos] - '0') + next;
        next = false;
        if (temp >= 10) //当前位需进位
        {
            temp -= 10;
            next = true;
        }
        result.insert(0, 1, temp + '0');
    }
    if (next == true)
    {
        result.insert(0, "1");
    }
    return result;
}
int main()
{
    int m, n;
    cin >> m >> n;
    ans[m] = "1", ans[m - 1] = "0";
    for (int i = m + 1; i <= n; i++)
    {
        ans[i] = plus_string(ans[i - 1], ans[i - 2]);
    }
    cout << ans[n];
    return 0;
}