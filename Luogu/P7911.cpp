#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <cstdio>
using namespace std;
map<string, int> mp;
bool check(string ip)
{
    vector<int> adr;
    int p = 0;
    while (p < ip.size())
    {
        int now = 0, st = p;
        if (ip[p] > '9' || ip[p] < '0')
        {
            return false;
        }
        while (ip[p] >= '0' && ip[p] <= '9') //读数
        {
            now = now * 10 + ip[p] - '0';
            p++;
        }
        adr.push_back(now); //存数
        if ((adr.size() < 4 && ip[p] != '.') ||
            (adr.size() == 4 && ip[p] != ':') ||
            (adr.size() == 5 && ip[p] != 'Z'))
        {
            return false;
        }
        int ws = 0, x = now;
        while (x)
        {
            ws++;
            x /= 10;
        }
        if ((now != 0 && ws != p - st) || (now == 0 && p - st != 1)) //有前导0位数不对
        {
            return false;
        }
        p++;
    }
    if (adr.size() != 5)
    {
        return false;
    }
    for (int i = 0; i < 5; i++)
    {
        if ((i < 4 && adr[i] > 255) || (i == 4 && adr[i] > 65535))
        {
            return false;
        }
    }
    return true;
}
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        string type, ip;
        cin >> type >> ip;
        if (check(ip + 'Z') == false)
        {
            cout << "ERR" << endl;
            continue;
        }
        if (type[0] == 'S')
        {
            if (mp[ip] == 0)
            {
                mp[ip] = i;
                cout << "OK" << endl;
            }
            else
            {
                cout << "FAIL" << endl;
            }
        }
        else
        {
            if (mp[ip] == 0)
            {
                cout << "FAIL" << endl;
            }
            else
            {
                cout << mp[ip] << endl;
            }
        }
    }
    return 0;
}