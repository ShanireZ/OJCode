#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
//! 一共有4种可能 VV KK VK KV
//! VK可使得分+1
//! KK VV 都可以改变为 VK 得到额外的1分
//! 先统计VK得分 然后再看是否有额外分
int main()
{
    int n, tot = 0;
    string str;
    cin >> n >> str;
    int p = str.find("VK");
    while (p != string::npos)
    {
        tot++;
        str.replace(p, 2, "O");
        p = str.find("VK");
    }
    int p1 = str.find("KK"), p2 = str.find("VV");
    if (p1 != string::npos || p2 != string::npos)
    {
        tot++;
    }
    cout << tot;
    return 0;
}