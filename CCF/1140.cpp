#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
int total[20001];
string mult_string(string a, string b)
{
    if (a == "0" || b == "0")
    {
        return "0";
    }
    string result;
    memset(total, 0, sizeof(total));
    for (int i = 0; i <= a.size() - 1; i++)
    {
        int pos_a = a.size() - 1 - i;
        for (int j = 0; j <= b.size() - 1; j++)
        {
            int pos_b = b.size() - 1 - j;
            total[i + j] += (a[pos_a] - '0') * (b[pos_b] - '0');
            if (total[i + j] > 9)
            {
                int next = total[i + j] / 10;
                total[i + j] %= 10;
                total[i + j + 1] += next;
            }
        }
    }
    int pos = a.size() + b.size() - 1;
    if (total[pos] == 0)
    {
        pos--;
    }
    for (int i = pos; i >= 0; i--)
    {
        result += total[i] + '0';
    }
    return result;
}

int main()
{
    string a, b;
    cin >> a >> b;
    cout << mult_string(a, b) << endl;
    return 0;
}