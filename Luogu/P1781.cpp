#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
bool cmp_str(string a, string b)
{
    if (a.size() > b.size())
    {
        return 1;
    }
    else if (a.size() < b.size())
    {
        return 0;
    }
    else
    {
        int pos = 0;
        while (a[pos] == b[pos])
        {
            pos++;
        }
        if (a[pos] > b[pos])
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    string max = "0";
    int id = 0;
    for (int i = 1; i <= n; i++)
    {
        string tmp;
        cin >> tmp;
        if (cmp_str(tmp, max))
        {
            max = tmp;
            id = i;
        }
    }
    cout << id << endl
         << max;
    return 0;
}