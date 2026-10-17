#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
//! 一共有4種可能 VV KK VK KV
//! VK可使得分+1
//! KK VV 都可以改變為 VK 得到額外的1分
//! 先統計VK得分 然後再看是否有額外分
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