#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
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

bool cmp(string a, string b)
{
    if (a == b)
    {
        return true;
    }
    if (a.size() != b.size())
    {
        return a.size() > b.size();
    }
    else
    {
        int pos = 0;
        while (a[pos] == b[pos])
        {
            pos++;
        }
        return a[pos] > b[pos];
    }
}

string div_string(string a, string b)
{
    string result;
    if (!cmp(a, b)) //a较小
    {
        result = "1";
    }
    else
    {
        int start = b.size();
        string temp = a.substr(0, start); //复制首次被除数部分

        for (int i = 0; i <= a.size() - b.size(); i++)
        {
            stringstream temp_io;
            int b_int, temp_int;
            temp_io << b;
            temp_io >> b_int;
            temp_io.clear();
            temp_io << temp;
            temp_io >> temp_int;
            if (temp_int >= b_int) //可被除
            {
                int count = temp_int / b_int;
                temp_int = temp_int % b_int;
                temp_io.clear();
                temp_io << temp_int;
                temp_io >> temp;
                result += ('0' + count);
            }
            else if (i != 0) //不可被除且不是首位
            {
                result += '0';
            }
            if (start < a.size())
            {
                if (temp == "0") //余数为0则清除
                {
                    temp.erase();
                }
                temp += a.substr(start++, 1);
            }
        }
    }
    return result;
}

struct Person
{
    string left, right, mul;
    int left_int, right_int, power;
};

Person kingdom[1001];

bool cmp_kingdom(Person a, Person b)
{
    return a.power < b.power;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i <= n; i++)
    {
        cin >> kingdom[i].left >> kingdom[i].right;
        stringstream temp_io;
        temp_io << kingdom[i].left;
        temp_io >> kingdom[i].left_int;
        temp_io.clear();
        temp_io << kingdom[i].right;
        temp_io >> kingdom[i].right_int;
        kingdom[i].power = kingdom[i].left_int * kingdom[i].right_int;
    }
    sort(kingdom + 1, kingdom + 1 + n, cmp_kingdom);
    kingdom[0].mul = "1";
    for (int i = 1; i <= n; i++)
    {
        kingdom[i].mul = mult_string(kingdom[i - 1].mul, kingdom[i - 1].left);
    }
    cout << div_string(kingdom[n].mul, kingdom[n].right);
    return 0;
}